/*
  ==============================================================================

    SLAPPresetManager.cpp
    Created: 12 Jan 2020 8:57:47pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPPresetManager.h"

SLAPPresetManager::SLAPPresetManager(AudioProcessor* inProcessor)
	:_currentPresetIsSaved(false),
	_currentPresetName("Untitled"),
	_processor(inProcessor)
{
	const String pluginName = _processor->getName();

	_presetDirectory = File::getSpecialLocation(File::userDesktopDirectory).getFullPathName() + pluginName;
}

SLAPPresetManager::~SLAPPresetManager()
{
}

void SLAPPresetManager::getXmlForPreset(XmlElement* inElement)
{
	const int numParameters = _processor->getNumParameters();

	for (int i = 0; i < numParameters; i++)
	{
		inElement->setAttribute(_processor->getParameterName(i), _processor->getParameter(i));
	}
}

void SLAPPresetManager::loadPresetForXml(XmlElement* inElement)
{
	_currentPresetXml = inElement;

	const int numParameters = _processor->getNumParameters();

	for (int i = 0; i < _currentPresetXml->getNumAttributes(); i++)
	{
		const String name = _currentPresetXml->getAttributeName(i);
		const float value = _currentPresetXml->getDoubleAttribute(name);

		for (int j = 0; j < _processor->getNumParameters(); j++)
		{
			if(_processor->getParameterName(j) == name)
			{
				_processor->setParameter(j, value);
			}
		}		
	}

}

int SLAPPresetManager::getNumberOfPresets()
{
}

String SLAPPresetManager::getPresetName(int inPresetIndex)
{
}

void SLAPPresetManager::createNewPreset()
{
}

void SLAPPresetManager::savePreset()
{
}

void SLAPPresetManager::saveAsPreset(String inPresetName)
{
}

void SLAPPresetManager::loadPreset(int inPresetIndex)
{
}

bool SLAPPresetManager::isCurrentPresetSaved()
{
}

String SLAPPresetManager::getCurrentPresetName()
{
}

void SLAPPresetManager::storeLocalPreset()
{
}
