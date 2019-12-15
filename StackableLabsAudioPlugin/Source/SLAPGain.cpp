/*
  ==============================================================================

    SLAPGain.cpp
    Created: 15 Dec 2019 3:58:42pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPGain.h"

SLAPGain::SLAPGain()
{
	
}
SLAPGain::~SLAPGain()
{
	
}

void SLAPGain::process(float* inAudio, float inGain, float* outAudio, int numSamplesToRender)
{
	for (int i = 0; i < numSamplesToRender; i++)
	{
		outAudio[i] = inAudio[i] * inGain;
	}
}