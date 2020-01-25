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
	if(isMouseOver())
	{
		//here you can make drawing things happen when the mouse is over a panel
	}
	//this is a place you can do per-panel drawing routines
}

void SLAPPanelBase::mouseEnter(const MouseEvent& event)
{
	repaint();
}

void SLAPPanelBase::mouseExit(const MouseEvent& event)
{
	repaint();
}
