/*
  ==============================================================================

    SLAPParameterComboBox.h
    Created: 1 Jan 2020 7:23:16pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"

class SLAPParameterComboBox
	: public ComboBox
{
public:
	SLAPParameterComboBox(AudioProcessorValueTreeState &stateToControl, const String& parameterId);
	~SLAPParameterComboBox();
private:
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> _attachment;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SLAPParameterComboBox)
};