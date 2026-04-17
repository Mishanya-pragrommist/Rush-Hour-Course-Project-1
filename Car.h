//Car.H
#ifndef HORIZCAR_H
#define HORIZCAR_H
#include "glut.h"
#include "Object.h"

namespace RushHourGame
{
	class Car : public Object
	{
	private:
		bool isVertical; //Direction of movement: true - vertical, false - horizontal
	public:
		Car(float xCenter, float yCenter, float zCenter, float xSize, float ySize, float zSize,
			float* diffColor, float* ambiColor, float* specColor, bool isVertical)
			: Object(xCenter, yCenter, zCenter, xSize, ySize, zSize, 
				diffColor, ambiColor, specColor) {
			setDirection(isVertical);
		}

		bool isVert() const { return isVertical; }
		void setDirection(bool isVertical) { this->isVertical = isVertical; };
		
		void hideCar() {
			setCoords(0, 0, 0); setSize(0, 0, 0);
		}
		virtual void draw();
	};
}

#endif
