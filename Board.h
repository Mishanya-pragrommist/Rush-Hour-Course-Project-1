// Board.h
#ifndef BOARD_h
#define BOARD_h
#include "glut.h"
#include "Object.h"

namespace RushHourGame
{
    class Board : public Object
    {
    private:
        void draw_finish_square(); // Draw 2 squares where red car shoud be placed 
        void drawGrid();
    public:
        Board(float xCenter, float yCenter, float zCenter, float xSize, float ySize, float zSize,
            float* diffColor, float* ambiColor, float* specColor)
            : Object(xCenter, yCenter, zCenter, xSize, ySize, zSize, 
                     specColor, diffColor, ambiColor) {}
        
        virtual void draw();
    };
}

#endif
