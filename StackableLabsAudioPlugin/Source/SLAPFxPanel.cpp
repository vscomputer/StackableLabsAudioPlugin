/*
  ==============================================================================

    SLAPFxPanel.cpp
    Created: 25 Dec 2019 2:54:26pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPFxPanel.h"

SLAPFxPanel::SLAPFxPanel(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor)
{
	setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

SLAPFxPanel::~SLAPFxPanel()
{
}

void SLAPFxPanel::setFxPanelStyle(SLAPFxPanelStyle inStyle)
{
	_style = inStyle;
}
