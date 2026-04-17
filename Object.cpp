//Object.CPP
#include "Object.h"

namespace RushHourGame
{
	Object::Object(float xCoord, float yCoord, float zCoord, float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor) { 
		setCoords(xCoord, yCoord, zCoord);
		setSize(xSize, ySize, zSize);
		setColors(diffColor, ambiColor, specColor);
	}

	// Set XYZ size
	void Object::setSize(float xSize, float ySize, float zSize) {
		this->xSize = xSize;
		this->ySize = ySize;
		this->zSize = zSize;
	}

	// Set XYZ coords
	void Object::setCoords(float xCenter, float yCenter, float zCenter)  {
		this->xCenter = xCenter;
		this->yCenter = yCenter;
		this->zCenter = zCenter;
	}

	// Set colors (diff - main one, ambi - shadow one, spec - glare)
	void Object::setColors(float* diffColor, float* ambiColor, float* specColor)  {
		this->diffColor = diffColor;
		this->ambiColor = ambiColor;
		this->specColor = specColor;
	}
}
