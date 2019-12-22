/*
  ==============================================================================

    SLAPLfo.cpp
    Created: 15 Dec 2019 3:58:22pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPLfo.h"
#include "JuceHeader.h"


SLAPLfo::SLAPLfo()
{
	reset();
}

SLAPLfo::~SLAPLfo()
{
}

void SLAPLfo::reset()
{
	_phase = 0.0f;
	zeromem(_buffer, sizeof(float) * maxBufferDelaySize);//he did this in setSampleRate which seems wrong?
}

void SLAPLfo::setSampleRate(double inSampleRate)
{
	_sampleRate = inSampleRate;
}

void SLAPLfo::process(float inRate, float inDepth, int inNumberOfSamples)
{
	const float rate = jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
	for (int i = 0; i < inNumberOfSamples; i++)
	{
		_phase = _phase + (rate / _sampleRate);
		if (_phase > 1.0f)
		{
			_phase = _phase - 1.0f;
		}

		const float lfoPosition = sinf(_phase * sTwoPi) * inDepth;
		_buffer[i] = lfoPosition;
	}

}

float* SLAPLfo::getBuffer()
{
	return _buffer;
}
