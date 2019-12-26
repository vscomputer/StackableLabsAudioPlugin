/*
  ==============================================================================

    SLAPCenterPanelMenuBar.cpp
    Created: 25 Dec 2019 2:54:01pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPCenterPanelMenuBar.h"

SLAPCenterPanelMenuBar::SLAPCenterPanelMenuBar(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor)
{
	setSize(CENTER_PANEL_MENU_BAR_WIDTH, CENTER_PANEL_MENU_BAR_HEIGHT);
}

SLAPCenterPanelMenuBar::~SLAPCenterPanelMenuBar()
{
}
