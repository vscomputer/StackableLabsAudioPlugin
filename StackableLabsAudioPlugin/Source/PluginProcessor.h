/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SLAPGain.h"
#include "SLAPDelay.h"
#include "SLAPLfo.h"
#include "SLAPPresetManager.h"

//==============================================================================
/**
*/
class StackableLabsAudioPluginAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    StackableLabsAudioPluginAudioProcessor();
    ~StackableLabsAudioPluginAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	float getInputGainMeterLevel(int inChannel);
	float getOutputGainMeterLevel(int inChannel);

	AudioProcessorValueTreeState parameters;
	SLAPPresetManager* getPresetManager()
	{
		return _presetManager.get();
	}

private:
	void initializeDSP();
	void initializeParameters();

	std::unique_ptr<SLAPGain> _inputGain[2];
	std::unique_ptr<SLAPGain> _outputGain[2];
	std::unique_ptr<SLAPDelay> _delay[2];
	std::unique_ptr<SLAPLfo> _lfo[2];
	std::unique_ptr<SLAPPresetManager> _presetManager;

	//std::unique_ptr<SLAPGain> _inputGain[2];
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StackableLabsAudioPluginAudioProcessor)
};
