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
}

SLAPTopPanel::~SLAPTopPanel()
{
}
