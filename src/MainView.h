#ifndef MainView_h
#define MainView_h

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "label/Label.h"

class MainView {
    public:
        MainView(Display &display);
        void setTitle(const String& title);
        void setCO2(int co2);
        void setTemperature(int t);
        void Clear();
        // void setCO2Raw(float co2Raw);
        // void setRange(int range);
        // void setBackgroundCO2(int co2);
        // void setAccuracy(int accuracy);

    private:
        Display * const _display;
        Label _titleLabel;
        Label _ppmLabel;
        Label _co2Label;
        Label _tempLabel;
        Label _co2Value;
        Label _tempValue;
};

#endif