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
	g.setColour(Colours::whitesmoke);
	g.fillAll();

	g.setColour(Colours::black);
	g.drawRect(0, 0, getWidth(), getHeight());
}
