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
#include "SLAPFxPanel.h"

class SLAPCenterPanel
	: public SLAPPanelBase
{
public:
	SLAPCenterPanel(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPCenterPanel();
private:
	std::unique_ptr<SLAPCenterPanelMenuBar> _menuBar;
	std::unique_ptr<SLAPFxPanel> _fxPanel;
};
