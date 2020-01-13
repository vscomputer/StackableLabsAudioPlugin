/*
  ==============================================================================

    SLAPPresetManager.h
    Created: 12 Jan 2020 8:57:47pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"

class SLAPPresetManager
{
public:
	SLAPPresetManager(AudioProcessor* inProcessor);
	~SLAPPresetManager();

	void getXmlForPreset(XmlElement* inElement);
	void loadPresetForXml(XmlElement* inElement);
private:
	XmlElement* _currentPresetXml;
	AudioProcessor* _processor;
};