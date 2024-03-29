#pragma once

#include <string>

namespace Text_formatter
{
    enum Colors
    {
        Red = 1,
        Green = 2,
        Yellow = 3,
        Blue = 4,
        Magenta = 5,
        Cyan = 6,
        White = 7,
        Black = 0
    };

    std::string color_text(std::string text, Colors text_color);
    std::string color_text(std::string text, Colors text_color, Colors background_color);

    void header(std::string title);
    void header(std::string title, Colors color);
};
