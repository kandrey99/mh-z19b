#include "Label.h"

void Label::init(Display* display, int16_t x, int16_t y, uint16_t w, uint16_t h, const String &text)
{
    _display = display;
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    _text = text;
}

const String& Label::text()
{
    return _text;
}

void Label::setText(const String &text) 
{
    _text = text;
}

void Label::setNumber(long num)
{
    _text = String(num);
}

void Label::setAlingment(Alignment alignment)
{
    _alignment = alignment;
}

void Label::setFreeFont(const GFXfont* font)
{
    _freeFont = font;
}

void Label::setTextColor(uint16_t textColor)
{
    _textColor = textColor;
}

void Label::setTextColor(uint16_t textColor, uint16_t textBgColor)
{
    _textColor = textColor;
    _textBgColor = textBgColor;
}

void Label::setBackground(uint16_t background)
{
    _background = background;
}

void Label::setBorderVisible(bool visible)
{
    _borderVisible = visible;
}

void Label::setBorderColor(uint16_t color)
{
    _borderColor = color;
}

void Label::setTextFont(uint8_t font)
{
    _textFont = font;
}

void Label::update()
{
    draw();
}

void Label::draw(boolean inverted)
{
    uint16_t fg, bg;
    if(!inverted) {
        fg = _textColor;
        bg = _textBgColor;
    } else {
        fg = _textBgColor;
        bg = _textColor;
    }

    _display->setTextColor(fg, bg);

    if (_freeFont == nullptr)
        _display->setTextFont(_textFont);
    else
        _display->setFreeFont(_freeFont);

    uint8_t textDatum = 0;
    uint32_t x = _x, y = _y;    
    switch (_alignment)
    {
        case TopLeft: textDatum = TL_DATUM; break;
        case TopCenter: textDatum = TC_DATUM; x = _x + (_w / 2); break;
        case TopRight: textDatum = TR_DATUM; x = _x + _w; break;
        case MiddleLeft: textDatum = ML_DATUM; y = _y + (_h / 2); break;        
        case MiddleCenter: textDatum = MC_DATUM; x = _x + (_w / 2); y = _y + (_h / 2); break;
        case MiddleRight: textDatum = MR_DATUM; x = _x + _w; y = _y + (_h / 2); break;
        case BottomLeft: textDatum = BL_DATUM; y = _y + _h; break;
        case BottomCenter: textDatum = BC_DATUM; x = _x + (_w / 2); y = _y + _h;  break;
        case BottomRight: textDatum = BR_DATUM; x = _x + _w; y = _y + _h;  break;
    }
    _display->fillRect(_x, _y, _w, _h, bg);
    _display->setTextDatum(textDatum);
    int16_t tw = _display->textWidth(_text);
    if (tw > _w)
    {
        _display->drawNumber(tw, x, y);
        _display->drawRect(_x, _y, _w, _h, TFT_RED);
        return;
    }
    _display->drawString(_text, x, y);
    if (_borderVisible)
    {
        _display->drawRect(_x, _y, _w, _h, _borderColor);
    }
}