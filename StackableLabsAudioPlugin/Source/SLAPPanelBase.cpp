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
	//this is a place you can do per-panel drawing routines
}
