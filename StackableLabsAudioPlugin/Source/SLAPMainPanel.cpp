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
	_topPanel = std::make_unique<SLAPTopPanel>(inProcessor);
	_topPanel->setTopLeftPosition(0, 0);
	addAndMakeVisible(_topPanel.get());

	_inputGainPanel = std::make_unique<SLAPGainPanel>(inProcessor);
	_inputGainPanel->setTopLeftPosition(0, TOP_PANEL_HEIGHT);
	_inputGainPanel->setParameterId(kParameter_InputGain);
	addAndMakeVisible(_inputGainPanel.get());

	_outputGainPanel = std::make_unique<SLAPGainPanel>(inProcessor);
	_outputGainPanel->setTopLeftPosition(MAIN_PANEL_WIDTH - GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
	_outputGainPanel->setParameterId(kParameter_OutputGain);
	addAndMakeVisible(_outputGainPanel.get());

	_centerPanel = std::make_unique<SLAPCenterPanel>(inProcessor);
	_centerPanel->setTopLeftPosition(GAIN_PANEL_WIDTH, TOP_PANEL_HEIGHT);
	addAndMakeVisible(_centerPanel.get());

}

SLAPMainPanel::~SLAPMainPanel()
{
}
