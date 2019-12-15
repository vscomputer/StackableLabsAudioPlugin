/*
  ==============================================================================

    SLAPGain.h
    Created: 15 Dec 2019 3:58:42pm
    Author:  Clint

  ==============================================================================
*/

#pragma once

class SLAPGain
{
public:
	SLAPGain();
	~SLAPGain();
	void process(float* inAudio, float inGain, float* outAudio, int numSamplesToRender);
private:
};