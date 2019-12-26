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
	ScopedPointer<SLAPTopPanel> _topPanel;
	ScopedPointer<SLAPGainPanel> _inputGainPanel;
	ScopedPointer<SLAPGainPanel> _outputGainPanel;
	ScopedPointer<SLAPCenterPanel> _centerPanel;
};