#include <iostream>

#include "TextFormatter/TextFormatter.h"

int main(int argc, char* argv[])
{
    Text_formatter::header("Hello world!", Text_formatter::Magenta);
    
    std::cout << Text_formatter::color_text("Hello world!\n", Text_formatter::Red, Text_formatter::Cyan);
    
    return 0;
}
