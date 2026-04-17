//UsefulStuff.H
#include "glut.h"
#ifndef USEFUL_STUFF_H
#define USEFUL_STUFF_H

// Contains colors arrays (for cars, board, world),
// functions for drawing parallelepipeds and text in window
namespace UsefulStuff
{
	//Colors for cars
	extern float diffPink[]; //Pink
	extern float ambiPink[];
	extern float specPink[];

	extern float diffRed[]; //Red
	extern float ambiRed[];
	extern float specRed[];

	extern float diffOrange[]; //Orange
	extern float ambiOrange[];
	extern float specOrange[];

	extern float diffYellow[]; //Yellow
	extern float ambiYellow[];
	extern float specYellow[];
	
	extern float diffGreen[]; //Green
	extern float ambiGreen[];
	extern float specGreen[];

	extern float diffVomitGreen[]; //Vomit green
	extern float ambiVomitGreen[];
	extern float specVomitGreen[];

	extern float diffBlue[]; //Blue
	extern float ambiBlue[];
	extern float specBlue[];
	
	extern float diffDarkBlue[]; //Dark blue
	extern float ambiDarkBlue[];
	extern float specDarkBlue[];

	extern float diffPurple[]; //Purple
	extern float ambiPurple[];
	extern float specPurple[];
	
	extern float diffLightGray[]; //Light gray
	extern float ambiLightGray[];
	extern float specLightGray[];

	extern float diffWhite[]; //White
	extern float ambiWhite[];
	extern float specWhite[];

	//Colors for board
	extern float diffGray[]; //Grey
	extern float ambiGray[];
	extern float specGray[];

	extern float diffBlack[]; //Black
	extern float ambiBlack[];
	extern float specBlack[];

	extern const float shininess;

	void draw_parallelepiped(float length, float width, float height);

	/// <summary>
	/// Output string in window 
	/// </summary>
	/// <param name="font">string font</param>
	/// <param name="text">the text itself</param>
	/// <param name="x">X coord in world</param>
	/// <param name="y">Y coord in world</param>
	void draw_string(void* font, const char* text, float x, float y); 
}

#endif
