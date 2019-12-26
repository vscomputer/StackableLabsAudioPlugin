/*
  ==============================================================================

    SLAPTopPanel.h
    Created: 25 Dec 2019 2:55:29pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPPanelBase.h"

class SLAPTopPanel
	: public SLAPPanelBase
{
public:
	SLAPTopPanel(StackableLabsAudioPluginAudioProcessor *inProcessor);
	~SLAPTopPanel();
private:
};