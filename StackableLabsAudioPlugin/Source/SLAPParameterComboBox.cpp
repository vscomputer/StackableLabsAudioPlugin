/*
  ==============================================================================

    SLAPParameterComboBox.cpp
    Created: 1 Jan 2020 7:23:16pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPParameterComboBox.h"

SLAPParameterComboBox::SLAPParameterComboBox(AudioProcessorValueTreeState& stateToControl, const String& parameterId)
	: juce::ComboBox(parameterId)
{
	_attachment = new AudioProcessorValueTreeState::ComboBoxAttachment(stateToControl, parameterId, *this);
}

SLAPParameterComboBox::~SLAPParameterComboBox()
{
}
