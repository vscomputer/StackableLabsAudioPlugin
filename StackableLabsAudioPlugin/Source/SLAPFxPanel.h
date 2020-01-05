/*
  ==============================================================================

    SLAPFxPanel.h
    Created: 25 Dec 2019 2:54:26pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "SLAPPanelBase.h"
#include "SLAPParameterSlider.h"

enum SLAPFxPanelStyle
{
	kSLAPFxPanelStyle_Delay,
	kSLAPFxPanelStyle_Chorus,
	kSLAPFxPanelStyle_TotalNumStyles
};

class SLAPFxPanel
	: public SLAPPanelBase,
	  public ComboBox::Listener
{
public:
	SLAPFxPanel(StackableLabsAudioPluginAudioProcessor* inProcessor);
	~SLAPFxPanel();

	void setFxPanelStyle(SLAPFxPanelStyle inStyle);

	void paint(Graphics& g) override;

	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
private:
	SLAPFxPanelStyle _style;
	OwnedArray<SLAPParameterSlider> _sliders;
};