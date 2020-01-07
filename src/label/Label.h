#ifndef Label_h
#define Label_h

#define LABEL_VERSION "0.0.1"

#include "display/Display.h"

enum Alignment
{
    TopLeft = 0,
    TopCenter,
    TopRight,
    MiddleLeft,
    MiddleCenter,
    MiddleRight,
    BottomLeft,
    BottomCenter,
    BottomRight
};

class Label
{
public:
    void init(Display* display, int16_t x, int16_t y, uint16_t w, uint16_t h, const String &text);
    const String& text();
    void setText(const String &text);
    void setNumber(long num);
    void setFreeFont(const GFXfont* font);
    void setAlingment(Alignment alignment);
    void setTextColor(uint16_t textColor);
    void setTextColor(uint16_t textColor, uint16_t textBgColor);
    void setBackground(uint16_t background);
    void setBorderVisible(bool visible);
    void setBorderColor(uint16_t color);
    void setTextFont(uint8_t size);
    void update();

private:
    void draw(boolean inverted = false);
    Display* _display;
    int16_t _x, _y;
    uint16_t _w, _h;
    String _text;
    const GFXfont* _freeFont = nullptr;
    Alignment _alignment = TopLeft;
    uint16_t _textColor = TFT_WHITE, _textBgColor = TFT_BLACK;
    uint16_t _background = TFT_BLACK;
    bool _borderVisible = false;
    uint16_t _borderColor = TFT_WHITE;
    uint8_t _textFont = 1;
};

#endif