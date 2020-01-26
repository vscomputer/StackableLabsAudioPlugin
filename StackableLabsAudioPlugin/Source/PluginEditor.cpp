/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
StackableLabsAudioPluginAudioProcessorEditor::StackableLabsAudioPluginAudioProcessorEditor (StackableLabsAudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
	_lookAndFeel = std::make_unique<SLAPLookAndFeel>();
	setLookAndFeel(_lookAndFeel.get());
	LookAndFeel::setDefaultLookAndFeel(_lookAndFeel.get());
	
	setSize (MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);
	_mainPanel = std::make_unique<SLAPMainPanel>(&processor);
	
	addAndMakeVisible(_mainPanel.get());

	_backgroundImage = ImageCache::getFromMemory(BinaryData::kadenze_bg_png, BinaryData::kadenze_bg_pngSize);
}

StackableLabsAudioPluginAudioProcessorEditor::~StackableLabsAudioPluginAudioProcessorEditor()
{
	setLookAndFeel(nullptr);
	LookAndFeel::setDefaultLookAndFeel(nullptr);
}

//==============================================================================
void StackableLabsAudioPluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
	g.drawImage(_backgroundImage, getLocalBounds().toFloat());
}

void StackableLabsAudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
