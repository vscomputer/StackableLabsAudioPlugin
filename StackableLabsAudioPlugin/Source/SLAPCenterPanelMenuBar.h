/*
  ==============================================================================

    SLAPCenterPanelMenuBar.h
    Created: 25 Dec 2019 2:54:01pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPPanelBase.h"
#include "SLAPParameterComboBox.h"

class SLAPCenterPanelMenuBar
	: public SLAPPanelBase
{
public:
	SLAPCenterPanelMenuBar(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPCenterPanelMenuBar();
private:
	ScopedPointer<SLAPParameterComboBox> _fxTypeComboBox;
};