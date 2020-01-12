/*
  ==============================================================================

    SLAPPanelBase.cpp
    Created: 25 Dec 2019 2:52:26pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPPanelBase.h"

SLAPPanelBase::SLAPPanelBase(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: _processor(inProcessor)
{
}

SLAPPanelBase::~SLAPPanelBase()
{
}

void SLAPPanelBase::paint(Graphics& g)
{
	g.setColour(Colours::grey);
	g.fillAll();

	g.setColour(Colours::black);	
	g.drawRoundedRectangle(0, 0, getWidth(), getHeight(), 4, 2);
}
