/*
  ==============================================================================

    SLAPDelay.h
    Created: 15 Dec 2019 3:58:33pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPAudioHelpers.h"

class SLAPDelay
{
public:
	SLAPDelay();
	~SLAPDelay();
	void setSampleRate(double inSampleRate);
	void reset();
	void process(float* inAudio, float inTime, float inFeedback, float inWetDry, float* outAudio, int inNumSamplesToRender);

private:
	double getInterpolatedSample(float inDelayTimeInSamples);

	double _sampleRate;
	double _buffer[maxBufferDelaySize];
	double _feedbackSample;

	int _delayIndex;
};
