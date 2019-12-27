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

	_menuBar = new SLAPCenterPanelMenuBar(inProcessor);
	_menuBar->setTopLeftPosition(0, 0);
	addAndMakeVisible(_menuBar);

	_fxPanel = new SLAPFxPanel(inProcessor);
	_fxPanel->setTopLeftPosition(0, CENTER_PANEL_MENU_BAR_HEIGHT);
	addAndMakeVisible(_fxPanel);
}

SLAPCenterPanel::~SLAPCenterPanel()
{	
}
