/*
  ==============================================================================

    SLAPFxPanel.cpp
    Created: 25 Dec 2019 2:54:26pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPFxPanel.h"

SLAPFxPanel::SLAPFxPanel(StackableLabsAudioPluginAudioProcessor* inProcessor)
	: SLAPPanelBase(inProcessor),
	_style(SLAPFxPanelStyle::kSLAPFxPanelStyle_Delay)
{
	setSize(FX_PANEL_WIDTH, FX_PANEL_HEIGHT);
}

SLAPFxPanel::~SLAPFxPanel()
{
}

void SLAPFxPanel::setFxPanelStyle(SLAPFxPanelStyle inStyle)
{
	_style = inStyle;
}

void SLAPFxPanel::paint(Graphics& g)
{
	SLAPPanelBase::paint(g);

	switch (_style) {
		case kSLAPFxPanelStyle_Delay:
		{
			g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
		}
		break;
		case kSLAPFxPanelStyle_Chorus:
		{
			g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight(), Justification::centred, 1);
		}
		break;
		case kSLAPFxPanelStyle_TotalNumStyles:
		{
			jassertfalse;
		}
		break;
		default: 
		{
			jassertfalse;
		};
	}
}
