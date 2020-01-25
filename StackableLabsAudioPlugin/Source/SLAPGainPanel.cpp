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
	setSize(GAIN_PANEL_WIDTH, GAIN_PANEL_HEIGHT);
	
}

SLAPGainPanel::~SLAPGainPanel()
{
}

void SLAPGainPanel::setParameterId(int parameterId)
{
	_slider = new SLAPParameterSlider(_processor->parameters, SLAPParameterId[parameterId], SLAPParameterLabel[parameterId]);

	const int sliderSize = 54;

	_slider->setBounds((getWidth() * 0.5) - (sliderSize * 0.5), (getHeight() * 0.25) - (sliderSize * 0.5), sliderSize, sliderSize);

	addAndMakeVisible(_slider);
}

void SLAPGainPanel::paint(Graphics& g)
{
	SLAPPanelBase::paint(g);

	if(_slider)
	{
		paintComponentLabel(g, _slider);
	}
}


