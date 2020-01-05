/*
  ==============================================================================

    SLAPFxPanel.cpp
    Created: 25 Dec 2019 2:54:26pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPFxPanel.h"
#include "SLAPParameters.h"
#include "SLAPHelperFunctions.h"

SLAPFxPanel::SLAPFxPanel(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor),
	_style(SLAPFxPanelStyle::kSLAPFxPanelStyle_Delay)
{
	setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
	setFxPanelStyle(kSLAPFxPanelStyle_Delay);
}

SLAPFxPanel::~SLAPFxPanel()
{
}

void SLAPFxPanel::setFxPanelStyle(SLAPFxPanelStyle inStyle)
{
	_style = inStyle;
	_sliders.clear();

	const int sliderSize = 56;
	int x = 130;
	int y = (getHeight() * 0.5) - (sliderSize * 0.5);


	switch (_style) {
		case kSLAPFxPanelStyle_Delay:
		{
			SLAPParameterSlider* time = new SLAPParameterSlider(_processor->parameters,SLAPParameterId[kParameter_DelayTime]);
			time->setBounds(x, y, sliderSize, sliderSize);
			addAndMakeVisible(time);

			_sliders.add(time);

			x = x + (sliderSize * 2);

			SLAPParameterSlider* feedback = new SLAPParameterSlider(_processor->parameters, SLAPParameterId[kParameter_DelayFeedback]);
			feedback->setBounds(x, y, sliderSize, sliderSize);
			addAndMakeVisible(feedback);

			_sliders.add(feedback);
			x = x + (sliderSize * 2);

			SLAPParameterSlider* wetDry = new SLAPParameterSlider(_processor->parameters, SLAPParameterId[kParameter_DelayWetDry]);
			wetDry->setBounds(x, y, sliderSize, sliderSize);
			addAndMakeVisible(wetDry);

			_sliders.add(wetDry);

		}
		break;
		case kSLAPFxPanelStyle_Chorus:
		{
			SLAPParameterSlider* rate = new SLAPParameterSlider(_processor->parameters, SLAPParameterId[kParameter_ModulationRate]);
			rate->setBounds(x, y, sliderSize, sliderSize);
			addAndMakeVisible(rate);

			_sliders.add(rate);
			x = x + (sliderSize * 2);

			SLAPParameterSlider* depth = new SLAPParameterSlider(_processor->parameters, SLAPParameterId[kParameter_ModulationDepth]);
			depth->setBounds(x, y, sliderSize, sliderSize);
			addAndMakeVisible(depth);
			_sliders.add(depth);
			x = x + (sliderSize * 2);

			SLAPParameterSlider* wetDry = new SLAPParameterSlider(_processor->parameters, SLAPParameterId[kParameter_DelayWetDry]);
			wetDry->setBounds(x, y, sliderSize, sliderSize);
			addAndMakeVisible(wetDry);
			_sliders.add(wetDry);
		}
		break;
		case kSLAPFxPanelStyle_TotalNumStyles:
		{
			jassertfalse;
		}
		break;
		default:
		{
			jassertfalse;
		};
	}
}

void SLAPFxPanel::paint(Graphics& g)
{
	SLAPPanelBase::paint(g);

	switch (_style) {
		case kSLAPFxPanelStyle_Delay:
		{
			g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight() * 0.75, Justification::centred, 1);
		}
		break;
		case kSLAPFxPanelStyle_Chorus:
		{
			g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight() * 0.75, Justification::centred, 1);
		}
		break;
		case kSLAPFxPanelStyle_TotalNumStyles:
		{
			jassertfalse;
		}
		break;
		default: 
		{
			jassertfalse;
		};
	}

	for (int i = 0; i < _sliders.size(); i++)
	{
		paintComponentLabel(g, _sliders[i]);
	}
}

void SLAPFxPanel::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
	SLAPFxPanelStyle style = (SLAPFxPanelStyle)comboBoxThatHasChanged->getSelectedItemIndex();

	setFxPanelStyle(style);
}
