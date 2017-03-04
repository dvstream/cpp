// chapter_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        char *port_state = new char[3];
        port_state[0] = 65;
        port_state[1] = 97;
        port_state[2] = 0;
        for (int j = 0; j < 3; ++j)
        {
            std::cout << port_state[j] << std::endl;
        }
        delete[]port_state;
    }

    char *port_state = new char[3];
    port_state[0] = 65;
    port_state[1] = 97;
    port_state[2] = 0;
    for (int j = 0; j < 3; ++j)
    {
        std::cout << port_state[j] << std::endl;
    }
    delete[]port_state;

    return 0;
}

