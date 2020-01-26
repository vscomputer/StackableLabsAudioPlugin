/*
  ==============================================================================

    SLAPTopPanel.h
    Created: 25 Dec 2019 2:55:29pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPPanelBase.h"

class SLAPTopPanel
	: public SLAPPanelBase,
	public Button::Listener,
	public ComboBox::Listener
{
public:
	SLAPTopPanel(StackableLabsAudioPluginAudioProcessor *inProcessor);
	~SLAPTopPanel();
	void paint(Graphics& g) override;
	void buttonClicked(Button*) override;
	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
private:
	void displaySaveAsPopup();
	void updatePresetComboBox();
	
	std::unique_ptr<ComboBox> _presetDisplay;
	std::unique_ptr<TextButton> _newPreset;
	std::unique_ptr<TextButton> _savePreset;
	std::unique_ptr<TextButton> _saveAsPreset;
	
};