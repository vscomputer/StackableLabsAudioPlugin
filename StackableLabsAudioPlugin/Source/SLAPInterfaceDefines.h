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
