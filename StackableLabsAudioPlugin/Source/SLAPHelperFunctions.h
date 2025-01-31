/*
  ==============================================================================

    SLAPHelperFunctions.h
    Created: 4 Jan 2020 9:55:37pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "SLAPInterfaceDefines.h"

inline void paintComponentLabel(Graphics& g, Component* inComponent)
{
	const int x = inComponent->getX() - (inComponent->getWidth() * 0.25f);
	const int y = inComponent->getY() + inComponent->getHeight();
	const int w = inComponent->getWidth() * 1.5f;
	const int h = 20;

	const String label = inComponent->getName();

	const float cornerSize = 3.0f;

	g.setColour(SLAPColour_3);
	g.fillRoundedRectangle(x, y, w, h, cornerSize);

	g.setColour(SLAPColour_1);
	g.setFont(font_1);
	g.drawFittedText(label, x, y, w, h, Justification::centred, 1);
}