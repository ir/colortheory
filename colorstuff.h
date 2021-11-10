#ifndef __COLORSTUFF

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <sstream>

#endif // !__COLORSTUFF

struct rgb
{
	int r;
	int g;
	int b;
};

struct hsvl
{
	int h;
	int s;
	int v;
	int l;
};

struct triad
{
	rgb col1;
	rgb col2;
	rgb col3;
};

struct anal {
	rgb col1;
	rgb col2;
	rgb col3;
};

struct tetrad {
	rgb col1;
	rgb col2;
	rgb col3;
	rgb col4;
};

class c_picker
{
public:
	c_picker(int col)
	{
		c_hex = col;
		for (int i = 0; i < 6; i++) {
			switch (i)
			{
			case 0:
			case 1: c_rgb.r += i;
				break;
			case 2:
			case 3: c_rgb.g += i;
				break;
			case 4:
			case 5: c_rgb.b += i;
				break;
			}
		}
	}
	~c_picker(){}

	rgb hex2rgb(int hex);
	hsvl rgb2hsvl(rgb rgbcol);
	rgb hsvl2rgb(hsvl hsvlcol);

	triad hex2triad(int hex);
	anal hex2anal(int hex);
	tetrad hex2tetrad(int hex);

	int rgb2hex(rgb rgbcol);
	void p_triad(triad col);
	void p_tetrad(tetrad col);
	void p_anal(anal col);

	rgb get_rgb() {
		return c_rgb;
	}
	hsvl get_hsvl() {
		return c_hsvl;
	}

private:
	int c_hex;
	rgb c_rgb;
	hsvl c_hsvl;
};

