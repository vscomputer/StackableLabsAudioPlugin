/*
  ==============================================================================

    SLAPVuMeter.cpp
    Created: 25 Jan 2020 11:31:49am
    Author:  Clint

  ==============================================================================
*/

#include "SLAPVuMeter.h"
#include "SLAPInterfaceDefines.h"
#include "SLAPParameters.h"

SLAPVuMeter::SLAPVuMeter(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: _parameterId(-1),
	_Ch0Level(0),
	_Ch1Level(0),
	_processor(inProcessor)
{
}

SLAPVuMeter::~SLAPVuMeter()
{
}

void SLAPVuMeter::paint(Graphics& g)
{
	const int meter_width = getWidth() / 3;

	g.setColour(SLAPColour_6);
	g.fillRect(0, 0, meter_width, getHeight());
	g.fillRect(meter_width * 2, 0, meter_width, getHeight());

	int ch0Fill = getHeight() - (getHeight() * _Ch0Level);
	int ch1Fill = getHeight() - (getHeight() * _Ch1Level);

	if(ch0Fill < 0)
	{
		ch0Fill = 0;
	}
	if(ch1Fill < 0)
	{
		ch1Fill = 0;
	}	

	g.setColour(SLAPColour_7);
	g.fillRect(0, ch0Fill, meter_width, getHeight());
	g.fillRect(meter_width * 2, ch1Fill, meter_width, getHeight());
}

void SLAPVuMeter::setParameterId(int inParameterId)
{
	_parameterId = inParameterId;
	startTimerHz(15);
}

void SLAPVuMeter::timerCallback()
{
	float updatedCh0Level = 0.0f;
	float updatedCh1Level = 0.0f;

	switch (_parameterId)
	{
	case(kParameter_InputGain):
		{
			updatedCh0Level = _processor->getInputGainMeterLevel(0);
			updatedCh1Level = _processor->getInputGainMeterLevel(1);
		}
		break;
	case(kParameter_OutputGain):
		{
			updatedCh0Level = _processor->getOutputGainMeterLevel(0);
			updatedCh1Level = _processor->getOutputGainMeterLevel(1);			
		}
		break;
	}

	if(updatedCh0Level > _Ch0Level)
	{
		_Ch0Level = updatedCh0Level;		
	}
	else
	{
		_Ch0Level = slMeterSmoothingCoeff * (_Ch0Level - updatedCh0Level) + updatedCh0Level;
	}

	if (updatedCh0Level > _Ch1Level)
	{
		_Ch1Level = updatedCh1Level;
	}
	else
	{
		_Ch1Level = slMeterSmoothingCoeff * (_Ch1Level - updatedCh1Level) + updatedCh1Level;
	}

	_Ch0Level = slap_denormalize(_Ch0Level);
	_Ch1Level - slap_denormalize(_Ch1Level);

	if(_Ch0Level && _Ch1Level)
	{
		repaint();
	}

}
