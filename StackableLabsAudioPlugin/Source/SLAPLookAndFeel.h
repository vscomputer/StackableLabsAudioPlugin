/*
  ==============================================================================

    SLAPLookAndFeel.h
    Created: 24 Jan 2020 2:10:01pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "SLAPInterfaceDefines.h"

class SLAPLookAndFeel
	: public LookAndFeel_V4
{
public:
	SLAPLookAndFeel()
	{
		setColour(ComboBox::backgroundColourId, SLAPColour_3);
		setColour(ComboBox::outlineColourId, SLAPColour_2);
		setColour(ComboBox::arrowColourId, SLAPColour_1);
		setColour(ComboBox::textColourId, SLAPColour_1);

		setColour(TextButton::buttonColourId, SLAPColour_1);
		setColour(TextButton::textColourOnId, SLAPColour_1);
		setColour(TextButton::textColourOffId, SLAPColour_1);
	}
	~SLAPLookAndFeel();

	Font getTextButtonFont(TextButton&, int buttonHeight) override
	{
		return font_1;
	}

	void drawButtonBackground(Graphics& g, Button& button, const Colour& backgroundColour,
		bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
	{
		Colour fillColor;

		if(shouldDrawButtonAsDown)
		{
			fillColor = SLAPColour_5;
		}
		else if(shouldDrawButtonAsHighlighted)
		{
			fillColor = SLAPColour_3;
		}

		const float cornerSize = 6.0f;
		const juce::Rectangle<float> bounds = button.getLocalBounds().toFloat().reduced(0.5f, 0.5f);

		g.setColour(fillColor);
		g.fillRoundedRectangle(bounds.reduced(1), cornerSize);

	}
private:
};
