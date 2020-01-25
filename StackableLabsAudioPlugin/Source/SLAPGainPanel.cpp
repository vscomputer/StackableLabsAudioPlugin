/*
  ==============================================================================

    SLAPGainPanel.cpp
    Created: 25 Dec 2019 2:54:51pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPGainPanel.h"
#include "SLAPParameters.h"
#include "SLAPHelperFunctions.h"

SLAPGainPanel::SLAPGainPanel(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor)
{

	const int meter_width = 64;
	setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
	_vuMeter = new SLAPVuMeter(inProcessor);
	_vuMeter->setBounds((getWidth()* 0.5) - (meter_width * 0.5), 
						getHeight() * 0.55 - (meter_width * 0.5), 
						meter_width, 
						getHeight() * 0.45);
	addAndMakeVisible(_vuMeter);
}

SLAPGainPanel::~SLAPGainPanel()
{
}

void SLAPGainPanel::setParameterId(int inParameterId)
{
	_slider = new SLAPParameterSlider(_processor->parameters, SLAPParameterId[inParameterId], SLAPParameterLabel[inParameterId]);

	const int sliderSize = 54;

	_slider->setBounds((getWidth() * 0.5) - (sliderSize * 0.5), (getHeight() * 0.25) - (sliderSize * 0.5) - 10, sliderSize, sliderSize);

	addAndMakeVisible(_slider);

	_vuMeter->setParameterId(inParameterId);
}

void SLAPGainPanel::paint(Graphics& g)
{
	SLAPPanelBase::paint(g);

	if(_slider)
	{
		paintComponentLabel(g, _slider);
	}
}


