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
		_sliderImage = ImageCache::getFromMemory(BinaryData::kadenze_knob_png, BinaryData::kadenze_knob_pngSize);

		setColour(ComboBox::backgroundColourId, SLAPColour_3);
		setColour(ComboBox::outlineColourId, SLAPColour_2);
		setColour(ComboBox::arrowColourId, SLAPColour_1);
		setColour(ComboBox::textColourId, SLAPColour_1);

		setColour(TextButton::buttonColourId, SLAPColour_1);
		setColour(TextButton::textColourOnId, SLAPColour_1);
		setColour(TextButton::textColourOffId, SLAPColour_1);
	}

	virtual ~SLAPLookAndFeel(){};

	//buttons

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

	//comboboxes

	Font getLabelFont(Label&) override
	{
		return  font_1;
	}

	void drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, bool isSeparator, bool isActive, bool isHighlighted, bool isTicked, bool hasSubMenu, const String& text, const String& shortcutKeyText, const Drawable* icon, const Colour* textColour) override
	{
		juce::Rectangle<int> r(area);
		Colour fillColour = isHighlighted ? SLAPColour_5 : SLAPColour_4;
		g.setColour(fillColour);
		g.fillRect(r.getX(), r.getY(), r.getWidth(), r.getHeight() - 1);

		Colour myTextColour = isTicked ? SLAPColour_7 : SLAPColour_1;
		g.setColour(myTextColour);
		g.setFont(font_1);

		r.setLeft(10);
		r.setY(1);

		g.drawFittedText(text, r, Justification::left, 1);

	}

	void drawComboBox(Graphics& g, int width, int height, bool isButtonDown, int buttonX, int buttonY, int buttonW, int buttonH, ComboBox& box) override
	{
		const float cornerSize = 3.0f;
		const juce::Rectangle<int> boxBounds(0, 0, width, height);

		g.setColour(SLAPColour_3);
		g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);

		juce::Rectangle<int> arrow(width - 30, 0, 20, height);

		Path path;
		path.startNewSubPath(arrow.getX() + 3.0f, arrow.getCentreY() - 2.0f);
		path.lineTo(arrow.toFloat().getCentreX(), arrow.toFloat().getCentreY() +3.0f);
		path.lineTo(arrow.toFloat().getRight() - 3.0f, arrow.toFloat().getCentreY() - 2.0f);

		Colour arrowColour = box.findColour(ComboBox::arrowColourId).withAlpha(box.isEnabled() ? 0.9f : 0.2f);
		g.setColour(arrowColour);
		g.strokePath(path, PathStrokeType(2.0f));
	}

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider&) override
	{
		const int numFrames = _sliderImage.getHeight() / _sliderImage.getWidth();
		const int frameIndex = (int)std::ceil(sliderPosProportional * (numFrames - 1));

		const float radius = jmin(width * 0.5f, height * 0.5f);
		const float centerX = x + (width * 0.5f);
		const float centerY = y + (height * 0.5f);
		const float rX = centerX - radius;
		const float rY = centerY - radius;

		g.drawImage(_sliderImage, rX, rY, radius * 2, radius * 2, 0, frameIndex * _sliderImage.getWidth(), _sliderImage.getWidth(), _sliderImage.getWidth());
	}

private:
	Image _sliderImage;
};
