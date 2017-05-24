/*
Copyright (c) 2017 Brian Schnepp

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

//TODO

#define COLOR_UNIT unsigned char

#include <stdlib.h>

struct Pixel
{
	COLOR_UNIT red;
	COLOR_UNIT blue;
	COLOR_UNIT green;
}Pixel;

struct GuiOption
{
	struct Pixel* logo;
	char* os_name;
}GuiOption;

struct Pointer
{
	struct Pixel** image;	//We have no alpha so we need a 2D array.
	uint64_t posx;
	uint64_t posy; 
}Pointer;

int width;
int height;

struct Pixel* screen;

int Init()
{
	//Figure out width and height, create the array of pixels, etc. etc.
	width = 1920;
	height = 1080;
	//PLACEHOLDERS TODO
	screen = (struct Pixel*)malloc(sizeof(struct Pixel) * (width * height));
}

int CreateGui(void)
{
	//TODO
	return 0;
}
