/*
  ==============================================================================

    SLAPMainPanel.h
    Created: 25 Dec 2019 2:52:57pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPPanelBase.h"

class SLAPMainPanel
	: public SLAPPanelBase
{
public:
	SLAPMainPanel(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPMainPanel();
private:
};