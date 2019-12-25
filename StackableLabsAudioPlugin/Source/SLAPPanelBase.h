/*
  ==============================================================================

    SLAPPanelBase.h
    Created: 25 Dec 2019 2:52:26pm
    Author:  Clint

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "PluginProcessor.h"

class SLAPPanelBase
	: Component
{
public:
	SLAPPanelBase(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPPanelBase();

	void paint(Graphics& g) override;
protected:
	StackableLabsAudioPluginAudioProcessor* _processor;
};