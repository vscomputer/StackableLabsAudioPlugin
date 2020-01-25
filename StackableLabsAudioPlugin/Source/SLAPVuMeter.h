/*
  ==============================================================================

    SLAPVuMeter.h
    Created: 25 Jan 2020 11:31:49am
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"

class SLAPVuMeter:
	public Component,
	public Timer
{
public:
	SLAPVuMeter(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPVuMeter();

	void paint(Graphics& g) override;
	void setParameterId(int inParameterId);
	void timerCallback() override;
private:

	int _parameterId;

	float _Ch0Level;
	float _Ch1Level;
	StackableLabsAudioPluginAudioProcessor* _processor;
};