/*
  ==============================================================================

    SLAPParameterSlider.h
    Created: 1 Jan 2020 7:23:01pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"

class SLAPParameterSlider
	: public Slider
{
public:
	SLAPParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterId);
	~SLAPParameterSlider();
private:
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> _attachment;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SLAPParameterSlider);
};