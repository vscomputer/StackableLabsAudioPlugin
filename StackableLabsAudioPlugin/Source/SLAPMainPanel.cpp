/*
  ==============================================================================

    SLAPMainPanel.cpp
    Created: 25 Dec 2019 2:52:57pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPMainPanel.h"
#include "SLAPParameters.h"

SLAPMainPanel::SLAPMainPanel(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor)
{
	setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_WIDTH);
	_topPanel = new SLAPTopPanel(inProcessor);
	_topPanel->setTopLeftPosition(0, 0);
	addAndMakeVisible(_topPanel);

	_inputGainPanel = new SLAPGainPanel(inProcessor);
	_inputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
	_inputGainPanel->setParameterId(kParameter_InputGain);
	addAndMakeVisible(_inputGainPanel);

	_outputGainPanel = new SLAPGainPanel(inProcessor);
	_outputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
	_outputGainPanel->setParameterId(kParameter_OutputGain);
	addAndMakeVisible(_outputGainPanel);

	_centerPanel = new SLAPCenterPanel(inProcessor);
	_centerPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
	addAndMakeVisible(_centerPanel);

}

SLAPMainPanel::~SLAPMainPanel()
{
}
