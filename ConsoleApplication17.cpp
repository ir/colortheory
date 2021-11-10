// ConsoleApplication17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "colorstuff.h"


int main()
{
    int hex = 0x65cec9;
    std::cout << "Hi!" << std::endl;
    c_picker color = c_picker(hex);
    rgb thing = color.hex2rgb(hex);
    hsvl h = color.rgb2hsvl(thing);
    rgb conv = color.hsvl2rgb(h);
    
    triad tri = color.hex2triad(hex);
    anal ana = color.hex2anal(hex);
    tetrad tet = color.hex2tetrad(hex);
    
    color.p_anal(ana);
    color.p_triad(tri);
    color.p_tetrad(tet);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
