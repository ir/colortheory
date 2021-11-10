// This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "colorstuff.h"

int main()
{
    int hex = 0x65cec9;
    std::cout << "Hi!" << std::endl;
    
    c_picker color = c_picker(hex); // ye
    
    rgb thing = color.hex2rgb(hex); // converts to rgb
    hsvl h = color.rgb2hsvl(thing); // converts to hsvl (l not really needed at all, too lazy to remove)
    rgb conv = color.hsvl2rgb(h);   // converts hsv back to rgb
    
    triad tri  = color.hex2triad(hex);  // creates tetrad scheme of color
    anal ana   = color.hex2anal(hex);   // creates analogous scheme of color
    tetrad tet = color.hex2tetrad(hex); // creates tetrad scheme of color
    
    // prints schemes as hexadecimal
    color.p_anal(ana);
    color.p_triad(tri);
    color.p_tetrad(tet);
}


