/*
  ==============================================================================

    SLAPGain.cpp
    Created: 15 Dec 2019 3:58:42pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPGain.h"
#include "JuceHeader.h"

SLAPGain::SLAPGain()
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
}