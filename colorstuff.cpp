#include "colorstuff.h"

rgb c_picker::hex2rgb(int hex) {
	c_picker::c_rgb.r = ((hex >> 16) & 0xff);
	c_picker::c_rgb.g = ((hex >> 8)  & 0xff);
	c_picker::c_rgb.b = ((hex)       & 0xff);
	return c_picker::c_rgb;
}

hsvl c_picker::rgb2hsvl(rgb rgbcol) {
    std::vector<double> rgb = { (double)rgbcol.r, (double)rgbcol.g, (double)rgbcol.b };
    for (int i = 0; i < rgb.size(); i++) {
        rgb[i] = rgb[i] / 255;
    }
    
    // h = 0, s = 1, v = 2
    double cmax = fmax(rgb[0], fmax(rgb[1], rgb[2]));
    double cmin = fmin(rgb[0], fmax(rgb[1], rgb[2]));
    double diff = cmax - cmin; // difference

    double h = -1, s = -1, l = 50 * (cmin + cmax);
    if (cmax == cmin)
        h = 0;
    else if (cmax == rgb[0])
        h = 60 * ((rgb[1] - rgb[2]) / diff) + 360;
    else if (cmax == rgb[1])
        h = 60 * ((rgb[2] - rgb[0]) / diff) + 120;
    else if (cmax == rgb[2])
        h = 60 * ((rgb[0] - rgb[1]) / diff) + 240;
    std::fmod(h, 360); // modulo 360

    if (cmax == 0)
        s = 0;
    else
        s = (diff / cmax) * 100;

    double v = cmax * 100;
    c_picker::c_hsvl = { 
        (int)std::round(h),(int)std::round(s), 
        (int)std::round(v), (int)std::round(l) 
    };
    return { c_picker::c_hsvl };
}

rgb c_picker::hsvl2rgb(hsvl hsvlcol) {
    float H = hsvlcol.h, S = hsvlcol.s, V = hsvlcol.v;
    if (H > 360 || H < 0 || S>100 || S < 0 || V>100 || V < 0) {
        return{-1,-1,-1};
    }
    float s = S / 100;
    float v = V / 100;
    float C = s * v;
    float X = C * (1 - abs(fmod(H / 60.0, 2) - 1));
    float m = v - C;
    float r, g, b;
    if (H >= 0 && H < 60) {
        r = C, g = X, b = 0;
    }
    else if (H >= 60 && H < 120) {
        r = X, g = C, b = 0;
    }
    else if (H >= 120 && H < 180) {
        r = 0, g = C, b = X;
    }
    else if (H >= 180 && H < 240) {
        r = 0, g = X, b = C;
    }
    else if (H >= 240 && H < 300) {
        r = X, g = 0, b = C;
    }
    else {
        r = C, g = 0, b = X;
    }

    int R = (r + m) * 255;
    int G = (g + m) * 255;
    int B = (b + m) * 255;

    return { R,G,B };
}

triad c_picker::hex2triad(int hex) {
    rgb rgbcol = c_picker::hex2rgb(hex);
    hsvl hsvcol = c_picker::rgb2hsvl(rgbcol);
    int h, s, v;
    hsvl col2 = { h = hsvcol.h + 120, s = hsvcol.s, v = hsvcol.v };
    hsvl col3 = { h = hsvcol.h - 120, s = hsvcol.s, v = hsvcol.v };
    rgb rcol2 = c_picker::hsvl2rgb(col2);
    rgb rcol3 = c_picker::hsvl2rgb(col3);
    triad colors = {
        rgbcol,
        rcol2,
        rcol3
    };
    
    return colors;
}

anal c_picker::hex2anal(int hex) {
    rgb rgbcol = c_picker::hex2rgb(hex);
    hsvl hsvcol = c_picker::rgb2hsvl(rgbcol);
    int h, s, v;
    hsvl col2 = { h = hsvcol.h + 30, s = hsvcol.s, v = hsvcol.v };
    hsvl col3 = { h = hsvcol.h - 30, s = hsvcol.s, v = hsvcol.v };
    rgb rcol2 = c_picker::hsvl2rgb(col2);
    rgb rcol3 = c_picker::hsvl2rgb(col3);
    anal colors = {
        rgbcol,
        rcol2,
        rcol3
    };

    return colors;
}

tetrad c_picker::hex2tetrad(int hex) {
    rgb rgbcol = c_picker::hex2rgb(hex);
    hsvl hsvcol = c_picker::rgb2hsvl(rgbcol);
    int h, s, v;
    hsvl col2 = { h = hsvcol.h + 60, s = hsvcol.s, v = hsvcol.v };
    hsvl col3 = { h = hsvcol.h + 180, s = hsvcol.s, v = hsvcol.v };
    hsvl col4 = { h = hsvcol.h - 120, s = hsvcol.s, v = hsvcol.v };
    rgb rcol2 = c_picker::hsvl2rgb(col2);
    rgb rcol3 = c_picker::hsvl2rgb(col3);
    rgb rcol4 = c_picker::hsvl2rgb(col4);
    tetrad colors = {
        rgbcol,
        rcol2,
        rcol3,
        rcol4
    };

    return colors;
}

int c_picker::rgb2hex(rgb rgbcol) {
    return (rgbcol.r << 16 | rgbcol.g << 8 | rgbcol.b);
}

void c_picker::p_triad(triad col) {
    int hex1 = c_picker::rgb2hex(col.col1), 
        hex2 = c_picker::rgb2hex(col.col2), 
        hex3 = c_picker::rgb2hex(col.col3);
    std::cout << std::hex << std::endl 
              << "Triad:" << std::endl 
              << "Color1: #" << hex1 << std::endl
              << "Color2: #" << hex2 << std::endl
              << "Color3: #" << hex3 << std::endl;
}

void c_picker::p_anal(anal col) {
    int hex1 = c_picker::rgb2hex(col.col1),
        hex2 = c_picker::rgb2hex(col.col2),
        hex3 = c_picker::rgb2hex(col.col3);
    std::cout << std::hex << std::endl 
        << "Analogous:" << std::endl
        << "Color1: #" << hex1 << std::endl
        << "Color2: #" << hex2 << std::endl
        << "Color3: #" << hex3 << std::endl;
}

void c_picker::p_tetrad(tetrad col) {
    int hex1 = c_picker::rgb2hex(col.col1),
        hex2 = c_picker::rgb2hex(col.col2),
        hex3 = c_picker::rgb2hex(col.col3),
        hex4 = c_picker::rgb2hex(col.col4);
    std::cout << std::hex << std::endl
        << "Tetrad:"   << std::endl
        << "Color1: #" << hex1 << std::endl
        << "Color2: #" << hex2 << std::endl
        << "Color3: #" << hex3 << std::endl
        << "Color4: #" << hex4 << std::endl;
}


