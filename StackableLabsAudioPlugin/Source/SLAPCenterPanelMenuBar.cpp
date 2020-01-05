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

	_fxTypeComboBox = new SLAPParameterComboBox(_processor->parameters, SLAPParameterId[kParameter_DelayType]);
	_fxTypeComboBox->setBounds(getWidth() - width, 0, width, getHeight());
	addAndMakeVisible(_fxTypeComboBox);
}

SLAPCenterPanelMenuBar::~SLAPCenterPanelMenuBar()
{
}
