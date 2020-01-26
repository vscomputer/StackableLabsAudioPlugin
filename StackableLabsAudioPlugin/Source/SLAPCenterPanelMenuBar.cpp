/*
  ==============================================================================

    SLAPCenterPanelMenuBar.cpp
    Created: 25 Dec 2019 2:54:01pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPCenterPanelMenuBar.h"
#include "SLAPParameters.h"

SLAPCenterPanelMenuBar::SLAPCenterPanelMenuBar(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor)
{
	setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);

	const int width = 85;
	_fxTypeComboBox = std::make_unique<SLAPParameterComboBox>(_processor->parameters, SLAPParameterId[kParameter_DelayType]);
	_fxTypeComboBox->setBounds(getWidth() - width, 0, width, getHeight());
	_fxTypeComboBox->addItem("DELAY", 1);
	_fxTypeComboBox->addItem("CHORUS", 2);
	_fxTypeComboBox->setSelectedItemIndex((int)_processor->getParameter(kParameter_DelayType), dontSendNotification);
	addAndMakeVisible(_fxTypeComboBox.get());
}

SLAPCenterPanelMenuBar::~SLAPCenterPanelMenuBar()
{
}

void SLAPCenterPanelMenuBar::addFxTypeComboBoxListener(ComboBox::Listener* inListener)
{
	_fxTypeComboBox->addListener(inListener);
}

void SLAPCenterPanelMenuBar::removeFxTypeComboBoxListener(ComboBox::Listener* inListener)
{
	_fxTypeComboBox->removeListener(inListener);
}
