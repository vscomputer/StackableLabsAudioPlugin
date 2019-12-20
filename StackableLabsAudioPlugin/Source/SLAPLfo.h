/*
  ==============================================================================

    SLAPLfo.h
    Created: 15 Dec 2019 3:58:22pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPAudioHelpers.h"

class SLAPLfo
{
public:
	SLAPLfo();
	~SLAPLfo();

	void reset();
	void setSampleRate(double inSampleRate);

	void process(float inRate, float inDepth, int inNumberOfSamples);
	float* getBuffer();
private:
	double _sampleRate;
	float _phase;
	float _buffer[maxBufferDelaySize];
};
