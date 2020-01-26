/*
  ==============================================================================

    SLAPMainPanel.h
    Created: 25 Dec 2019 2:52:57pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPPanelBase.h"
#include "SLAPTopPanel.h"
#include "SLAPGainPanel.h"
#include "SLAPCenterPanel.h"

class SLAPMainPanel
	: public SLAPPanelBase
{
public:
	SLAPMainPanel(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPMainPanel();
private:
	std::unique_ptr<SLAPTopPanel> _topPanel;
	std::unique_ptr<SLAPGainPanel> _inputGainPanel;
	std::unique_ptr<SLAPGainPanel> _outputGainPanel;
	std::unique_ptr<SLAPCenterPanel> _centerPanel;	
};