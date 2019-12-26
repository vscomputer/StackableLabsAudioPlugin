/*
  ==============================================================================

    SLAPCenterPanel.h
    Created: 25 Dec 2019 2:53:24pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPPanelBase.h"
#include "SLAPCenterPanelMenuBar.h"

class SLAPCenterPanel
	: public SLAPPanelBase
{
public:
	SLAPCenterPanel(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPCenterPanel();
private:
	ScopedPointer<SLAPCenterPanelMenuBar> _menuBar;
};
