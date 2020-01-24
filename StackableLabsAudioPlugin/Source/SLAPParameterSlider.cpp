/*
  ==============================================================================

    SLAPParameterSlider.cpp
    Created: 1 Jan 2020 7:23:01pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPParameterSlider.h"

SLAPParameterSlider::SLAPParameterSlider(AudioProcessorValueTreeState& stateToControl, const String& parameterId, const String& parameterLabel)
	: juce::Slider(parameterId)
{
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
	setRange(0.0f, 1.0f, 0.001f);
	_attachment = new AudioProcessorValueTreeState::SliderAttachment(stateToControl, parameterId, *this);
}

SLAPParameterSlider::~SLAPParameterSlider()
{
}
