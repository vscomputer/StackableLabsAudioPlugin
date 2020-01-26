/*
  ==============================================================================

    SLAPTopPanel.cpp
    Created: 25 Dec 2019 2:55:29pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPTopPanel.h"

SLAPTopPanel::SLAPTopPanel(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor)
{
	setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);

	int button_x = 15;
	int button_y = 10;
	int button_w = 55;
	int button_h = 25;

	_newPreset = std::make_unique<TextButton>();
	_newPreset->setButtonText("NEW");
	_newPreset->setBounds(button_x, button_y, button_w, button_h);
	_newPreset->addListener(this);
	addAndMakeVisible(_newPreset.get());
	button_x = button_x + button_w;

	_savePreset = std::make_unique<TextButton>();
	_savePreset->setButtonText("SAVE");
	_savePreset->setBounds(button_x, button_y, button_w, button_h);
	_savePreset->addListener(this);
	addAndMakeVisible(_savePreset.get());
	button_x = button_x + button_w;

	_saveAsPreset = std::make_unique<TextButton>();
	_saveAsPreset->setButtonText("SAVE AS");
	_saveAsPreset->setBounds(button_x, button_y, button_w, button_h);
	_saveAsPreset->addListener(this);
	addAndMakeVisible(_saveAsPreset.get());
	button_x = button_x + button_w;

	const int comboBox_w = 200;
	const int comboBox_x = TOP_PANEL_WIDTH * 0.5 - comboBox_w * 0.5;

	_presetDisplay = std::make_unique<ComboBox>();
	_presetDisplay->setBounds(comboBox_x, button_y, comboBox_w, button_h);
	_presetDisplay->addListener(this);
	addAndMakeVisible(_presetDisplay.get());

	updatePresetComboBox();
}

SLAPTopPanel::~SLAPTopPanel()
{
}

void SLAPTopPanel::paint(Graphics& g)
{
	SLAPPanelBase::paint(g);

	g.setColour(SLAPColour_1);
	g.setFont(font_2);

	const int label_w = 220;

	g.drawFittedText("STACKABLE LABS DELAY/CHORUS", TOP_PANEL_WIDTH - (label_w + 20), 0, label_w, getHeight(), Justification::centredRight, 1);
}

void SLAPTopPanel::buttonClicked(Button* b)
{
	SLAPPresetManager* presetManager = _processor->getPresetManager();
	if(b == _newPreset.get())
	{
		presetManager->createNewPreset();
		updatePresetComboBox();
	}
	else if(b == _savePreset.get())
	{
		presetManager->savePreset();
	}
	else if(b == _saveAsPreset.get())
	{
		displaySaveAsPopup();
	}
}

void SLAPTopPanel::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
	SLAPPresetManager* presetManager = _processor->getPresetManager();
	if(comboBoxThatHasChanged == _presetDisplay.get())
	{
		const int index = _presetDisplay->getSelectedItemIndex();
		presetManager->loadPreset(index);
	}
}

void SLAPTopPanel::displaySaveAsPopup()
{
	SLAPPresetManager* presetManager = _processor->getPresetManager();

	String currentPresetName = presetManager->getCurrentPresetName();

	AlertWindow window("Save As", "Please enter a name for your preset", AlertWindow::NoIcon);

	window.centreAroundComponent(this, getWidth(), getHeight());
	window.addTextEditor("presetName", currentPresetName, "preset name:");
	window.addButton("Confirm", 1);
	window.addButton("Cancel", 0);

	if(window.runModalLoop())
	{
		String presetName = window.getTextEditor("presetName")->getText();
		presetManager->saveAsPreset(presetName);

		updatePresetComboBox();
	}
}

void SLAPTopPanel::updatePresetComboBox()
{
	SLAPPresetManager* presetManager = _processor->getPresetManager();

	String currentPresetName = presetManager->getCurrentPresetName();

	_presetDisplay->clear(dontSendNotification);

	_presetDisplay->setText(presetManager->getCurrentPresetName());

	const int numPresets = presetManager->getNumberOfPresets();

	for (int i = 0; i < numPresets; i++)
	{
		_presetDisplay->addItem(presetManager->getPresetName(i), i + 1);
	}
}
