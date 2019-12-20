/*
  ==============================================================================

    SLAPAudioHelpers.h
    Created: 15 Dec 2019 3:57:39pm
    Author:  Clint

  ==============================================================================
*/

#pragma once

const static double sPi = 3.14159265;
const static double sTwoPi = 6.28318531;

inline float slap_linear_interp(float v0, float v1, float t)
{
	return (1 - t) * v0 + t * v1;
}