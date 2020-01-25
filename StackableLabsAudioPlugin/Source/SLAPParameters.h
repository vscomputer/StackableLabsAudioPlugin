/*
  ==============================================================================

    SLAPParameters.h
    Created: 26 Dec 2019 9:16:15pm
    Author:  Clint

  ==============================================================================
*/

#pragma once

enum kSLAPParameter
{
	kParameter_InputGain = 0,
	kParameter_DelayTime,
	kParameter_DelayFeedback,
	kParameter_DelayWetDry,
	kParameter_DelayType,
	kParameter_OutputGain,
	kParameter_ModulationRate,
	kParameter_ModulationDepth,
	kParameter_TotalNumParameters
};

static String SLAPParameterId[kParameter_TotalNumParameters]
{
	"InputGain",
	"Time",
	"Feedback",
	"WetDry",
	"Type",
	"OutputGain",
	"ModulationRate",
	"ModulationDepth"
};

static String SLAPParameterLabel[kParameter_TotalNumParameters]
{
	"InputGain",
	"DelayTime",
	"DelayFeedback",
	"DelayAmount",
	"Type",
	"OutputGain",
	"ModulationRate",
	"ModulationDepth"
};