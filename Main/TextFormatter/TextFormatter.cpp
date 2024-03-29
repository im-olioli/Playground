#include "TextFormatter.h"

#include <iostream>

std::string Text_formatter::color_text(std::string text, Colors text_color)
{
    uint8_t color_integer = static_cast<uint8_t>(text_color);
    
    text = "\033[3" + std::to_string(color_integer) + "m" + text + "\033[0m";

    return text;
}

std::string Text_formatter::color_text(std::string text, Colors text_color, Colors background_color)
{
    uint8_t color_integer = static_cast<uint8_t>(background_color);

    text = "\033[4" + std::to_string(color_integer) + "m" + color_text(text, text_color);
    
    return text;
}

void Text_formatter::header(std::string title)
{
    size_t title_size = title.length() + 8;

    std::string line = " ";
    for(size_t i = 0; i < title_size; i++) line += "=";
    line += "\n ||  " + title + "  ||\n ";
    for(size_t i = 0; i < title_size; i++) line += "=";
    line += "\n\n";

    std::cout << line;
}

void Text_formatter::header(std::string title, Colors color)
{
    size_t title_size = title.length() + 8;

    std::string line = " ";
    for(size_t i = 0; i < title_size; i++) line += "=";
    line += "\n ||  " + color_text(title, color) + "  ||\n ";
    for(size_t i = 0; i < title_size; i++) line += "=";
    line += "\n\n";

    std::cout << line;
}
