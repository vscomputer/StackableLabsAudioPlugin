/*
  ==============================================================================

    SLAPGainPanel.h
    Created: 25 Dec 2019 2:54:51pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPPanelBase.h"

class SLAPGainPanel
	: public SLAPPanelBase
{
public:
	SLAPGainPanel(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPGainPanel();
private:
};