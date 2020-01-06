/*
  ==============================================================================

    SLAPDelay.h
    Created: 15 Dec 2019 3:58:33pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPAudioHelpers.h"

enum SLAPDelayType
{
	kSLAPDelayType_Delay = 0,
	kSLAPDelayType_Chorus,
};

class SLAPDelay
{
public:
	SLAPDelay();
	~SLAPDelay();
	void setSampleRate(double inSampleRate);
	void reset();
	void process(float* inAudio, float inTime, float inFeedback, float inWetDry, float inType, float* inModulationBuffer, float* outAudio, int inNumSamplesToRender);

private:
	double getInterpolatedSample(float inDelayTimeInSamples);

	double _sampleRate;
	double _buffer[maxBufferDelaySize];
	double _feedbackSample;
	float _timeSmoothed;

	int _delayIndex;
};
