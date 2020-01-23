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

	ScopedPointer<ComboBox> _presetDisplay;
	ScopedPointer<TextButton> _newPreset;
	ScopedPointer<TextButton> _savePreset;
	ScopedPointer<TextButton> _saveAsPreset;
};