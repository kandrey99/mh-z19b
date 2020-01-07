#include "display/Display.h"

Display::Display()
{
    init(2);
    setRotation(3);
    fillScreen(TFT_BLACK);
    setTextSize(1);
    setTextColor(TFT_WHITE, TFT_BLACK);
    setCursor(0, 0);
}