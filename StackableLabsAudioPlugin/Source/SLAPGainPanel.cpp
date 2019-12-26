/*
  ==============================================================================

    SLAPGainPanel.cpp
    Created: 25 Dec 2019 2:54:51pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPGainPanel.h"

SLAPGainPanel::SLAPGainPanel(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor)
{
	setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
	
}

SLAPGainPanel::~SLAPGainPanel()
{
}


