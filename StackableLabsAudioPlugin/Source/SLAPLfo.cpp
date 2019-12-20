/*
  ==============================================================================

    SLAPLfo.cpp
    Created: 15 Dec 2019 3:58:22pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPLfo.h"
#include "SLAPAudioHelpers.h"

class SLAPLfo
{
public:
	SLAPLfo();
	~SLAPLfo();

	void reset();
	void setSampleRate(double inSampleRate);

	void process(float inRate, float inDepth, int inNumberOfSamples);
private:
	double _sampleRate;
	float _phase;
	float _buffer[maxBufferDelaySize];
};
