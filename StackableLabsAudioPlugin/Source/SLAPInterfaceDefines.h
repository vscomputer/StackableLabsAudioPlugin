/*
  ==============================================================================

    SLAPInterfaceDefines.h
    Created: 25 Dec 2019 3:18:20pm
    Author:  Clint

  ==============================================================================
*/

#pragma once
const static int MAIN_PANEL_WIDTH = 750;
const static int MAIN_PANEL_HEIGHT = 300;

const static int TOP_PANEL_WIDTH = MAIN_PANEL_WIDTH;
const static int TOP_PANEL_HEIGHT = 45;

const static int GAIN_PANEL_WIDTH = 100;
const static int GAIN_PANEL_HEIGHT = MAIN_PANEL_HEIGHT - TOP_PANEL_HEIGHT;

const static int CENTER_PANEL_WIDTH = MAIN_PANEL_WIDTH - (GAIN_PANEL_WIDTH * 2);
const static int CENTER_PANEL_HEIGHT = GAIN_PANEL_HEIGHT;

const static int CENTER_PANEL_MENU_BAR_WIDTH = CENTER_PANEL_WIDTH;
const static int CENTER_PANEL_MENU_BAR_HEIGHT = 35;

const static int FX_PANEL_WIDTH = CENTER_PANEL_WIDTH;
const static int FX_PANEL_HEIGHT = CENTER_PANEL_HEIGHT - CENTER_PANEL_MENU_BAR_HEIGHT;

const Colour SLAPColour_1 = Colour(105, 105, 105);
const Colour SLAPColour_2 = Colour(0, 0, 0).withAlpha(0.0f);
const Colour SLAPColour_3 = Colour(0, 0, 0).withAlpha(0.3f);
const Colour SLAPColour_4 = Colour(0, 0, 0).withAlpha(0.6f);
const Colour SLAPColour_5 = Colour(105, 105, 105).withAlpha(0.3f);
const Colour SLAPColour_6 = Colour(0,0,0).withAlpha(0.8f);
const Colour SLAPColour_7 = Colour(125, 125, 125);

const Font font_1{ "Impact",12.00f,Font::bold };
const Font font_2{ "Impact",22.00f,Font::bold };
const Font font_3{ "Impact",48.00f,Font::bold };