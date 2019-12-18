/*
  ==============================================================================

    SLAPDelay.cpp
    Created: 15 Dec 2019 3:58:33pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPDelay.h"
#include "JuceHeader.h"
#include "SLAPAudioHelpers.h"

SLAPDelay::SLAPDelay()
	: _sampleRate(-1), _buffer{}, _feedbackSample(0.0), _delayIndex(0)
{
}

SLAPDelay::~SLAPDelay()
{
}

void SLAPDelay::setSampleRate(double inSampleRate)
{
	_sampleRate = inSampleRate;
}

void SLAPDelay::reset()
{
	zeromem(_buffer, sizeof(double) * maxBufferDelaySize);
}

void SLAPDelay::process(float* inAudio, float inTime, float inFeedback, float inWetDry, float* outAudio,
	int inNumSamplesToRender)
{
	const float wet = inWetDry;
	const float dry = 1.0 - wet;
	const float feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);

	for (int i = 0; i < inNumSamplesToRender; i++)
	{
		const double delayTimeInSamples = inTime * _sampleRate;
		const auto sample = getInterpolatedSample(delayTimeInSamples);
		_buffer[_delayIndex] = inAudio[i] + (_feedbackSample * feedbackMapped);
		_feedbackSample = sample;
		
		outAudio[i] = inAudio[i] * dry + sample * wet;
		_delayIndex = _delayIndex + 1;

		if (_delayIndex >= maxBufferDelaySize)
		{
			_delayIndex = _delayIndex - maxBufferDelaySize;
		}
	}
}

double SLAPDelay::getInterpolatedSample(float inDelayTimeInSamples)
{
	double readPosition = (double)_delayIndex - inDelayTimeInSamples;

	if (readPosition < 0.0f)
	{
		readPosition = readPosition + maxBufferDelaySize;
	}

	int index_y0 = (int)readPosition - 1;
	if(index_y0 < 0)
	{
		index_y0 = index_y0 + maxBufferDelaySize;
	}
	int index_y1 = (int)readPosition;
	if (index_y1 > maxBufferDelaySize)
	{
		index_y1 = index_y1 - maxBufferDelaySize;
	}

	const float sample_y0 = _buffer[index_y0];
	const float sample_y1 = _buffer[index_y1];
	const float t = readPosition - (int)readPosition;

	const double outSample = slap_linear_interp(sample_y0, sample_y1, t);
	return outSample;
}


