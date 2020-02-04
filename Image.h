#pragma once

#include <string>
#include <stdint.h>

// opaque struct. backend-agnostic. currently uses GDI+
class ROMFont
{
public:
	ROMFont(std::string filename, int size);
	~ROMFont();

	void SetBold(bool bold);
	void SetItalic(bool italic);

	bool IsBold();
	bool IsItalic();

private:
	friend class Image;
	void* myData;
};

class Image
{
public:
	Image(std::string filename);
	~Image();
	void Display(int16_t x, int16_t y);
	void DisplayEx(int16_t x, int16_t y, int16_t inX, int16_t inY, int16_t w, int16_t h, bool no_alpha);
	uint32_t* GetPixels();
	uint32_t GetWidth();
	uint32_t GetHeight();
	uint32_t GetPixelAt(int32_t x, int32_t y);

	static Image* RenderText(ROMFont* font, std::string text, int r, int g, int b);
	static int Image::RenderTextWidth(ROMFont* font, std::string text);

private:
	Image()
	{
		myPixels = 0;
		myWidth = 0;
		myHeight = 0;
	}

	uint32_t* myPixels;
	uint32_t myWidth;
	uint32_t myHeight;
};