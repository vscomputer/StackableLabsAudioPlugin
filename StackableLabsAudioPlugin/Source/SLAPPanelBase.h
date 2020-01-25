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
#include "SLAPInterfaceDefines.h"

class SLAPPanelBase
	: public Component
{
public:
	SLAPPanelBase(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPPanelBase();

	void paint(Graphics& g) override;

	void mouseEnter(const MouseEvent& event) override;
	void mouseExit(const MouseEvent& event) override;
protected:
	StackableLabsAudioPluginAudioProcessor* _processor;
};