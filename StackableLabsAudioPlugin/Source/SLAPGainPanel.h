/*
  ==============================================================================

    SLAPGainPanel.h
    Created: 25 Dec 2019 2:54:51pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPPanelBase.h"
#include "SLAPParameterSlider.h"

class SLAPGainPanel
	: public SLAPPanelBase
{
public:
	SLAPGainPanel(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPGainPanel();
	void setParameterId(int parameterId);
	void paint(Graphics& g) override;
private:
	ScopedPointer<SLAPParameterSlider> _slider;
};