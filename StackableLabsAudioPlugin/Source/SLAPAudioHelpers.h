/*
  ==============================================================================

    SLAPAudioHelpers.h
    Created: 15 Dec 2019 3:57:39pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
//#define slParameterSmoothingCoeff_Generic = 0.4
//#define slParameterSmoothingCoeff_Fine = 0.002

const static int maxBufferDelaySize = 192000;
const static double sPi = 3.14159265;
const static double sTwoPi = 6.28318531;
const static double slParameterSmoothingCoeff_Generic = 0.4;
const static double slParameterSmoothingCoeff_Fine = 0.002;
const static double slMeterSmoothingCoeff = 0.2f;

inline float slap_linear_interp(float v0, float v1, float t)
{
	return (1 - t) * v0 + t * v1;
}

inline float slap_denormalize(float inValue)
{
	float absValue = fabs(inValue);

	if(absValue < 1e-15)
	{
		return 0.0f;
	}
	else
	{
		return inValue;
	}
}

inline float dbToNormalizedGain(float inValue)
{
	float inValueDb = Decibels::gainToDecibels(inValue + 0.00001f);
	inValueDb = (inValueDb + 96.0f) / 96.0f;
	return inValueDb;
}

inline double tanh_clip(double x)
{
	return x * (27 + x * x) / (27 + 9 * x * x);
}