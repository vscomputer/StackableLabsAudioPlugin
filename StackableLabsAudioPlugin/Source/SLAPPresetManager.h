/*
  ==============================================================================

    SLAPPresetManager.h
    Created: 12 Jan 2020 8:57:47pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"

const static String PRESET_FILE_EXTENSION = ".spf";

class SLAPPresetManager
{
public:
	SLAPPresetManager(AudioProcessor* inProcessor);
	~SLAPPresetManager();

	void getXmlForPreset(XmlElement* inElement);
	void loadPresetForXml(XmlElement* inElement);

	int getNumberOfPresets();
	String getPresetName(int inPresetIndex);
	void createNewPreset();
	void savePreset();
	void saveAsPreset(String inPresetName);
	void loadPreset(int inPresetIndex);
	bool isCurrentPresetSaved();
	String getCurrentPresetName();
private:
	void storeLocalPreset();
	bool _currentPresetIsSaved;
	File _currentlyLoadedPreset;
	Array<File> _localPresets;
	String _currentPresetName;
	String _presetDirectory;
	XmlElement* _currentPresetXml;
	AudioProcessor* _processor;
};