//Scene.h
#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include "Board.h"
#include "Car.h"

namespace RushHourGame
{
    const int rows = 6, columns = 6; //Sizes of map array
    const int num_of_levels = 7;

    /// <summary>
    /// This class draws cars and board, 
    /// handles keyboard and mouse input (car moving and collisions), 
    /// scales up/down screen, saves records etc
    /// </summary>
    class Scene 
    {
    private:
        Board* board;
        std::vector<Car*> cars; // Array of cars
        int map[rows][columns]; // Array that shows placement of each car
                               // 0 - place is empty
                               // 1, 2, 3 etc - there is car with this number
        int records[num_of_levels]; //Records from all levels

        float boardSize = 0.65, zBoard = 0.06; // Board sizes
        float carSizeX = 0.095, carSizeY = 0.195, carSizeZ = 0.1; // Sizes of each cars
        float dist = 0.16;    // Distanse between cars and board
        float width, height;  // Window size
        float distZ;          // Distanse between scene and screen
        float angleX, angleY; // Angles to rotate scene
        int mouseX, mouseY;   // Mouse coords
        
        bool finish;          // true - level is finished, false - not finished
        int time, tick;       // Time in seconds
        int currentLevel;
        int button;           // 0: button isnt pressed, 1: left, 2: right
        
        int xFrom, yFrom;     // Original place of car
        int xTo, yTo;         // Place where car should be moved
        float step = 0.2;     // Step of grid. Also lenght of board cells
        
        //Methods
        void initialize();         // Initialize beginning settings of the scene
        void resetMap();           // Place cars in their initial places in map according to current level
        void allocateCars();       // Set coords to all cars
        float allocX(int i) const; // Translate coordinate X from map to worlds ones
        float allocY(int j) const; // Translate coordinate Y from map to worlds ones

        bool findNearest(int x, int y, int& Ox, int& Oy, bool findCar); //Find cars/empty spots
        bool moveCar(int xFrom, int zFrom, int xTo, int zTo); // Move car to empty spots if there are some near it

        void resetRecords();     // Set all records to 0
        void getRecords();       // Read records from file
        void setRecords() const; // Write records to file
    public:
        Scene(); ~Scene();
        
        void draw_scene(); //Draw all scene objects + update timer and record text
        void timer();      // Measure time so it can be output in window
        void resize(int width, int height); // Resize objects when resizing window

        void mouse_click(int button, int state, int x, int y);
        void mouse_move(int x, int y);
        void keyboard(unsigned char key, int x, int y);
	};
}

#endif
