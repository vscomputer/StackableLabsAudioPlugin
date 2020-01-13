/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SLAPParameters.h"

//==============================================================================
StackableLabsAudioPluginAudioProcessor::StackableLabsAudioPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
	: AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
		.withInput("Input", AudioChannelSet::stereo(), true)
#endif
		.withOutput("Output", AudioChannelSet::stereo(), true)
#endif
	),
	parameters(*this, nullptr)
#endif
{
	initializeParameters();
	initializeDSP();
	_presetManager = new SLAPPresetManager(this);
}

StackableLabsAudioPluginAudioProcessor::~StackableLabsAudioPluginAudioProcessor()
{
}

//==============================================================================
const String StackableLabsAudioPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool StackableLabsAudioPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool StackableLabsAudioPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool StackableLabsAudioPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double StackableLabsAudioPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int StackableLabsAudioPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int StackableLabsAudioPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void StackableLabsAudioPluginAudioProcessor::setCurrentProgram (int index)
{
}

const String StackableLabsAudioPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void StackableLabsAudioPluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void StackableLabsAudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

    for (int i = 0; i < 2; i++)
    {
		_delay[i]->setSampleRate(sampleRate);
		_lfo[i]->setSampleRate(sampleRate);
    }
}

void StackableLabsAudioPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
    for (int i = 0; i < 2; i++)
    {
		_delay[i]->reset();
		_lfo[i]->reset();
    }
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool StackableLabsAudioPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void StackableLabsAudioPluginAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
		// ..do something to the data...
        auto* channelData = buffer.getWritePointer (channel);
		_inputGain[channel]->process(channelData, getParameter(kParameter_InputGain), channelData, buffer.getNumSamples());
		float rate = (channel == 0) ? getParameter(kParameter_ModulationRate) : 0;
		_lfo[channel]->process(rate, getParameter(kParameter_ModulationDepth), buffer.getNumSamples());
		_delay[channel]->process(channelData, getParameter(kParameter_DelayTime), getParameter(kParameter_DelayFeedback), getParameter(kParameter_DelayWetDry), getParameter(kParameter_DelayType), _lfo[channel]->getBuffer(), channelData, buffer.getNumSamples());
		_outputGain[channel]->process(channelData, getParameter(kParameter_OutputGain), channelData, buffer.getNumSamples());
		
    }
}

//==============================================================================
bool StackableLabsAudioPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* StackableLabsAudioPluginAudioProcessor::createEditor()
{
    return new StackableLabsAudioPluginAudioProcessorEditor (*this);
}

//==============================================================================
void StackableLabsAudioPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

	XmlElement preset("SLAP_StateInfo");
	XmlElement* presetBody = new XmlElement("SLAP_Preset");

	_presetManager->getXmlForPreset(presetBody);

	preset.addChildElement(presetBody);
	copyXmlToBinary(preset, destData);
}

void StackableLabsAudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

	auto xmlState = getXmlFromBinary(data, sizeInBytes);

	if(xmlState)
	{
		forEachXmlChildElement(*xmlState, subChild)
		{
			_presetManager->loadPresetForXml(subChild);
		}
	}
	else { jassertfalse; }
}

void StackableLabsAudioPluginAudioProcessor::initializeDSP()
{
	for (int i = 0; i < 2; i++)
	{
		_inputGain[i] = new SLAPGain();
		_outputGain[i] = new SLAPGain();
		_delay[i] = new SLAPDelay();
		_lfo[i] = new SLAPLfo();
	}
}

void StackableLabsAudioPluginAudioProcessor::initializeParameters()
{
	for (int i = 0; i < kParameter_TotalNumParameters; i++)
	{
		float defaultValue = 0.5f;
		if(i == 4)
		{
			defaultValue = 0.0f;
		}
		parameters.createAndAddParameter(SLAPParameterId[i], SLAPParameterId[i], SLAPParameterId[i], NormalisableRange<float>(0.0f, 1.0f), defaultValue, nullptr, nullptr);
	}
	parameters.state = ValueTree(Identifier("SLAP"));
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new StackableLabsAudioPluginAudioProcessor();
}
