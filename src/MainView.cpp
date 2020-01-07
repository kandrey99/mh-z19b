#include "MainView.h"

#include "fonts/DSEG7_Classic_Bold_32.h"
#include "fonts/term_8x15.h"

MainView::MainView(Display &display) : _display(&display)
{
    Clear();

    _titleLabel.init(_display, 0, 0, 160, 15, "CO2 Meter");
    _titleLabel.setFreeFont(&FreeMonoOblique9pt7b);
    _titleLabel.setTextColor(TFT_YELLOW);
    _titleLabel.setAlingment(Alignment::TopCenter);
    // _titleLabel.setBorderVisible(true);
    _titleLabel.update();

    _co2Label.init(_display, 10, 20, 40, 15, "CO2");
    _co2Label.setFreeFont(&FreeMonoOblique9pt7b);
    _co2Label.update();

    _ppmLabel.init(_display, 115, 20, 40, 15, "PPM");
    _ppmLabel.setFreeFont(&FreeMonoOblique9pt7b);
    _ppmLabel.update();

    _co2Value.init(_display, 20, 45, 115, 40, String(-1));
    _co2Value.setFreeFont(&DSEG7_Classic_Bold_32);
    //_co2Value.setFreeFont(&term_8x15);
    _co2Value.setAlingment(Alignment::MiddleCenter);
    //_co2Value.setBorderVisible(true);

    _tempLabel.init(_display, 0, 100, 100, 15, "Temp (C)");
    _tempLabel.setFreeFont(&FreeMonoOblique9pt7b);
    _tempLabel.update();

    //_tempValue.init(_display, 105, 100, 22, 15, String(-1));
    //_tempValue.setFreeFont(&FreeMonoOblique9pt7b);
    _tempValue.init(_display, 105, 98, 18, 15, String(-1));
    _tempValue.setFreeFont(&term_8x15);
    _tempValue.update();

    // _display->drawString("CO2 (raw): ", 0, 30); setCO2Raw(-1);
    // _display->drawString("Range: ", 0, 45); setRange(-1);
    // _display->drawString("Background CO2: ", 0, 60); setBackgroundCO2(-1);
    // _display->drawString("Accuracy: ", 0, 75); setAccuracy(-1);
}

void MainView::setTitle(const String& title)
{
    _titleLabel.setText(title);
}

void MainView::setCO2(int co2)
{
    if (_co2Value.text() != String(co2))
    {
        _co2Value.setNumber(co2);
        if (co2 < 800) _co2Value.setTextColor(TFT_GREEN);
        else if (co2 < 1200) _co2Value.setTextColor(TFT_YELLOW);
        else _co2Value.setTextColor(TFT_RED);
        _co2Value.update();
    }
}

void MainView::setTemperature(int t)
{
    _tempValue.setNumber(t);
    _tempValue.update();
}

void MainView::Clear()
{
    _display->fillScreen(TFT_BLACK);
}

// void MainView::setCO2Raw(float co2Raw)
// {
//     _display->fillRect(110, 30, 50, 15, TFT_BLACK);
//     _display->drawNumber(co2Raw, 110, 30);
// }

// void MainView::setRange(int range)
// {
//     _display->fillRect(110, 45, 50, 15, TFT_BLACK);
//     _display->drawNumber(range, 110, 45);
// }

// void MainView::setBackgroundCO2(int co2)
// {
//     _display->fillRect(110, 60, 50, 15, TFT_BLACK);
//     _display->drawNumber(co2, 110, 60);
// }

// void MainView::setAccuracy(int accuracy)
// {
//     _display->fillRect(110, 75, 50, 15, TFT_BLACK);
//     _display->drawNumber(accuracy, 110, 75);
// }