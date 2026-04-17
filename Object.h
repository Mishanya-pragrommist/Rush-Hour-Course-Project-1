//Object.H
#ifndef OBJECT_H
#define OBJECT_H

namespace RushHourGame
{
    /// <summary>
    /// Contains X,Y,Z coords, sizes and colors of object.
    /// Other objects (Board and Cars) are derivated classes from this one
    /// </summary>
    class Object 
    {
	private:
		float xCenter, yCenter, zCenter; //Object placement
		float xSize, ySize, zSize; //Size of objects
		float* diffColor, * ambiColor, * specColor; //Their color
	public:
        Object(float xCoord, float yCoord, float zCoord, float xSize, float ySize, float zSize,
            float* diffColor, float* ambiColor, float* specColor);

        // Getters
        float getXCenter() const { return xCenter; } //Get placement of obj
        float getYCenter() const { return yCenter; }
        float getZCenter() const { return zCenter; }

        float getXSize() const { return xSize; } //Get size of obj
        float getYSize() const { return ySize; }
        float getZSize() const { return zSize; }

        float* getDiffColor() const { return diffColor; } //Get color of obj
        float* getAmbiColor() const { return ambiColor; }
        float* getSpecColor() const { return specColor; }

        //Setters
        void setXCenter(float xCenter) { this->xCenter = xCenter; }
        void setYCenter(float yCenter) { this->yCenter = yCenter; }
        void setCoords(float xCenter, float yCenter, float zCenter); //Set object placement

        void setSize(float xSize, float ySize, float zSize); //Set sizes of object
        void setColors(float* diffColor, float* ambiColor, float* specColor); //Set all colors

        virtual void draw() = 0; // Each derived object (Car and Board) is drawn differently
	};
}

#endif
