/*
  ==============================================================================

    SLAPMainPanel.cpp
    Created: 25 Dec 2019 2:52:57pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPMainPanel.h"

SLAPMainPanel::SLAPMainPanel(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor)
{
	setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_WIDTH);
}

SLAPMainPanel::~SLAPMainPanel()
{
}
