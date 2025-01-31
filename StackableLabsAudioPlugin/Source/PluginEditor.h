/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SLAPMainPanel.h"
#include "SLAPLookAndFeel.h"

//==============================================================================
/**
*/
class StackableLabsAudioPluginAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    StackableLabsAudioPluginAudioProcessorEditor (StackableLabsAudioPluginAudioProcessor&);
    ~StackableLabsAudioPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    StackableLabsAudioPluginAudioProcessor& processor;

	//UI elements
	std::unique_ptr<SLAPMainPanel> _mainPanel;
	std::unique_ptr<SLAPLookAndFeel> _lookAndFeel;
	
	Image _backgroundImage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StackableLabsAudioPluginAudioProcessorEditor)
};
