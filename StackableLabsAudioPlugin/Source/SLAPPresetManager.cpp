/*
  ==============================================================================

    SLAPPresetManager.cpp
    Created: 12 Jan 2020 8:57:47pm
    Author:  Clint

  ==============================================================================
*/

#include "SLAPPresetManager.h"

#if JUCE_WINDOWS
static const String directorySeparator = "\\";
#elif JUCE_MAC
static const String directorySeparator = "/";
#endif

SLAPPresetManager::SLAPPresetManager(AudioProcessor* inProcessor)
	:_currentPresetIsSaved(false),
	_currentPresetName("Untitled"),
	_processor(inProcessor)
{
	const String pluginName = _processor->getName();

	_presetDirectory = File::getSpecialLocation(File::userDesktopDirectory).getFullPathName() + directorySeparator + pluginName;

	if(!File(_presetDirectory).exists())
	{
		File(_presetDirectory).createDirectory();
	}

	storeLocalPreset();
}

SLAPPresetManager::~SLAPPresetManager()
{
}

void SLAPPresetManager::getXmlForPreset(XmlElement* inElement)
{
	auto& parameters = _processor->getParameters();
	for (int i = 0; i < parameters.size(); i++)
	{
		AudioProcessorParameterWithID* parameter = (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
		inElement->setAttribute(parameter->paramID, parameter->getValue());
	}
}

void SLAPPresetManager::loadPresetForXml(XmlElement* inElement)
{
	_currentPresetXml = inElement;
	auto& parameters = _processor->getParameters();

	for (int i = 0; i < _currentPresetXml->getNumAttributes(); i++)
	{
		const String paramId = _currentPresetXml->getAttributeName(i);
		const float value = _currentPresetXml->getDoubleAttribute(paramId);

		for (int j = 0; j < parameters.size(); j++)
		{
			AudioProcessorParameterWithID* parameter = (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
			if(paramId == parameter->paramID)
			{
				parameter->setValueNotifyingHost(value);
			}
		}
	}
}

int SLAPPresetManager::getNumberOfPresets()
{
	return _localPresets.size();
}

String SLAPPresetManager::getPresetName(int inPresetIndex)
{
	return _localPresets[inPresetIndex].getFileNameWithoutExtension();
}

void SLAPPresetManager::createNewPreset()
{
	auto& parameters = _processor->getParameters();

	for (int i = 0; i < parameters.size(); i++)
	{
		AudioProcessorParameterWithID* parameter = (AudioProcessorParameterWithID*)parameters.getUnchecked(i);
		const float defaultValue = parameter->getDefaultValue();
		parameter->setValueNotifyingHost(defaultValue);
	}
}

void SLAPPresetManager::savePreset()
{
	MemoryBlock destinationData;
	_processor->getStateInformation(destinationData);

	_currentlyLoadedPreset.deleteFile();

	_currentlyLoadedPreset.appendData(destinationData.getData(), destinationData.getSize());

	_currentPresetIsSaved = true;
}

void SLAPPresetManager::saveAsPreset(String inPresetName)
{
	File presetFile = File(_presetDirectory + directorySeparator + inPresetName + PRESET_FILE_EXTENSION);

	if(!presetFile.exists())
	{
		presetFile.create();
	}
	else
	{
		presetFile.deleteFile();
	}

	MemoryBlock destinationData;
	_processor->getStateInformation(destinationData);

	presetFile.appendData(destinationData.getData(), destinationData.getSize());

	_currentPresetIsSaved = true;
	_currentPresetName = inPresetName;

	storeLocalPreset();
}

void SLAPPresetManager::loadPreset(int inPresetIndex)
{
	_currentlyLoadedPreset = _localPresets[inPresetIndex];

	MemoryBlock presetBinary;

	if(_currentlyLoadedPreset.loadFileAsData(presetBinary))
	{
		_currentPresetIsSaved = true;
		_currentPresetName = getPresetName(inPresetIndex);
		_processor->setStateInformation(presetBinary.getData(), presetBinary.getSize());
	}
}

bool SLAPPresetManager::isCurrentPresetSaved()
{
	return _currentPresetIsSaved;
}

String SLAPPresetManager::getCurrentPresetName()
{
	return _currentPresetName;
}

void SLAPPresetManager::storeLocalPreset()
{
	_localPresets.clear();

	for (DirectoryIterator di(File(_presetDirectory), false, "*"+(String)PRESET_FILE_EXTENSION, File::TypesOfFileToFind::findFiles); di.next();)
	{
		File presetFile = di.getFile();
		_localPresets.add(presetFile);
	}
}
