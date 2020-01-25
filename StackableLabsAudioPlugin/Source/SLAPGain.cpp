/*
  ==============================================================================

    SLAPGain.cpp
    Created: 15 Dec 2019 3:58:42pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPGain.h"
#include "SLAPAudioHelpers.h"

SLAPGain::SLAPGain()
	: _outputSmoothed(0)
{
	
}
SLAPGain::~SLAPGain()
{
	
}

void SLAPGain::process(float* inAudio, float inGain, float* outAudio, int numSamplesToRender)
{
	float gainMapped = jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
	gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);

	for (int i = 0; i < numSamplesToRender; i++)
	{
		outAudio[i] = inAudio[i] * gainMapped;
	}

	float absValue = fabs(outAudio[0]);
	_outputSmoothed = slMeterSmoothingCoeff * (_outputSmoothed - absValue) + absValue;
}

float SLAPGain::getMeterLevel()
{
	return _outputSmoothed;
}
