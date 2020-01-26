/*
  ==============================================================================

    SLAPCenterPanel.cpp
    Created: 25 Dec 2019 2:53:24pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPCenterPanel.h"

SLAPCenterPanel::SLAPCenterPanel(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor)
{
	setSize(CENTER_PANEL_WIDTH, CENTER_PANEL_HEIGHT);

	_menuBar = std::make_unique<SLAPCenterPanelMenuBar>(inProcessor);
	_menuBar->setTopLeftPosition(0, 0);
	addAndMakeVisible(_menuBar.get());

	_fxPanel = std::make_unique <SLAPFxPanel>(inProcessor);
	_fxPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
	addAndMakeVisible(_fxPanel.get());

	_menuBar->addFxTypeComboBoxListener(_fxPanel.get());
}

SLAPCenterPanel::~SLAPCenterPanel()
{	
}
