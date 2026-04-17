#include <fstream>
#include <stdio.h>
#include <string>
#include "glut.h"
#include "Scene.h"
#include "Board.h"
#include "Car.h"
#include "UsefulStuff.h"

namespace RushHourGame
{
    using namespace UsefulStuff;
    std::string path = "records.txt";
    
    Scene::Scene() {
        getRecords();
        currentLevel = 1;
        tick = 0;
        board = new Board(0, 0, 0, boardSize, boardSize, zBoard,  diffGray, ambiGray, specGray);

        // Creating cars and placing them on board 
        // (dont forget to go to resetArr() func to place cars where you want)
        
        // Horizontal cars
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                                diffRed, ambiRed, specRed, false)); //Red 1
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                                diffOrange, ambiOrange, specOrange, false)); //Orange 2
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                               diffBlack, ambiBlack, specBlack, false)); //Black 3
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                               diffPink, ambiPink, specPink, false)); //Pink 4
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                               diffVomitGreen, ambiVomitGreen, specVomitGreen, false)); //Vomit green 5
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                               diffLightGray, ambiLightGray, specLightGray, false)); //LightGray 6

        // Vertical cars
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                                diffYellow, ambiYellow, specYellow, true)); //Yellow 7
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                                diffDarkBlue, ambiDarkBlue, specDarkBlue, true)); //DarkBlue 8
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                                diffBlue, ambiBlue, specBlue, true)); //Blue 9
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                                diffPurple, ambiPurple, specPurple, true)); //Purple 10
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                                diffGreen, ambiGreen, specGreen, true)); //Green 11
        cars.push_back(new Car(0, 0, 0, 0, 0, 0,
                                diffWhite, ambiWhite, specWhite, true)); //White 12
        initialize();
    }

    Scene::~Scene() {
        for (const auto &car : cars) { delete car; }
        delete board;
    }

    // === To work with records file === 

    
    void Scene::resetRecords() {
        std::ofstream fout; 
        fout.open(path);
        if (!fout.is_open()) {
            perror("Error: file records.txt wasnt opened\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < num_of_levels; i++) {
            fout << 0 << " ";
            records[i] = 0;
        }
        fout.close();
    }
    void Scene::getRecords() {
        std::ifstream fin;
        fin.open(path);
        if (!fin.is_open()) {
            perror("Error: file records.txt wasnt opened\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < num_of_levels; i++) {
            fin >> records[i];
        }
        fin.close();
    }
    void Scene::setRecords() const { 
        std::ofstream fout; 
        fout.open(path);
        if (!fout.is_open()) {
            perror("Error: file records.txt wasnt opened\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < num_of_levels; i++) {
            fout << records[i] << " ";
        }
        fout.close();
    }
    
    // === Initialize levels ===

    void Scene::initialize() {
        resetMap();
        allocateCars();
        xFrom = 0; yFrom = 0;
        xTo = yTo = 0;
        distZ = -2;
        angleX = 0; angleY = -10;
        time = 0;
        finish = false;
    }

    void Scene::resetMap()
    {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                map[i][j] = 0;
            }
        }
        switch (currentLevel)
        {
        case 1:
            map[0][3] = 1; //Red
            map[3][2] = 2; //Orange
            //map[2][5] = 3; //Black
            //map[0][2] = 4; //Pink
            map[2][5] = 5; //Vomit green
            //map[1][0] = 6; //LightGray

            map[2][4] = 7; //Yellow
            //map[4][4] = 8; //Dark blue
            //map[3][3] = 9; //Blue
            map[2][1] = 10; //Purple
            //map[1][1] = 11; // Green
            //map[4][3] = 12; //White
            break;
        case 2: //Level 2
            map[1][3] = 1; //Red
            map[1][5] = 2; //Orange
            map[3][5] = 3; //Black
            map[1][0] = 4; //Pink
            //map[1][0] = 5; //Vomit green
            map[3][0] = 6; //LightGray

            map[4][4] = 7; //Yellow
            //map[0][5] = 8; //Dark blue
            map[0][1] = 9; //Blue
            map[4][2] = 10; //Purple
            map[0][5] = 11; // Green
            //map[3][1] = 12; //White
            break;
        case 3: //Level 3
            map[2][3] = 1; //Red
            map[2][2] = 2; //Orange
            map[1][4] = 3; //Black
            map[3][4] = 4; //Pink
            //map[1][0] = 5; //Vomit green
            //map[3][0] = 6; //LightGray

            //map[4][4] = 7; //Yellow
            map[1][3] = 8; //Dark blue
            //map[0][1] = 9; //Blue
            map[4][3] = 10; //Purple
            map[4][1] = 11; // Green
            //map[3][1] = 12; //White
            break;
        case 4: //Level 4
            map[3][3] = 1; //Red
            map[1][4] = 2; //Orange
            map[4][5] = 3; //Black
            map[4][2] = 4; //Pink
            //map[4][1] = 5; //Vomit green
            //map[0][0] = 6; //LightGray

            map[3][5] = 7; //Yellow
            map[5][4] = 8; //Dark blue
            map[2][3] = 9; //Blue
            map[2][1] = 10; //Purple
            map[5][1] = 11; // Green
            //map[2][1] = 12; //White
            break;
        case 5: //Level 5
            map[1][3] = 1; //Red
            map[2][4] = 2; //Orange
            map[3][5] = 3; //Black
            map[0][2] = 4; //Pink
            map[3][1] = 5; //Vomit green
            //map[0][0] = 6; //LightGray

            map[5][5] = 7; //Yellow
            map[4][4] = 8; //Dark blue
            map[3][3] = 9; //Blue
            map[2][2] = 10; //Purple
            //map[5][3] = 11; // Green
            map[1][1] = 12; //White
            break;
        case 6: //Level 6
            map[1][3] = 1; //Red
            map[2][2] = 2; //Orange
            map[2][5] = 3; //Black
            //map[2][2] = 4; //Pink
            //map[4][1] = 5; //Vomit green
            //map[0][0] = 6; //LightGray

            map[3][1] = 7; //Yellow
            map[1][5] = 8; //Dark blue
            map[4][5] = 9; //Blue
            map[5][5] = 10; //Purple
            map[5][3] = 11; // Green
            map[3][4] = 12; //White
            break;
        case 7: //Level 7
            map[2][3] = 1; //Red
            map[0][5] = 2; //Orange
            map[4][4] = 3; //Black
            map[2][2] = 4; //Pink
            map[4][1] = 5; //Vomit green
            map[0][0] = 6; //LightGray

            map[2][5] = 7; //Yellow
            map[0][3] = 8; //Dark blue
            map[1][3] = 9; //Blue
            map[4][3] = 10; //Purple
            map[5][3] = 11; // Green
            map[2][1] = 12; //White
            break;
        }
        for (const auto& car : cars) {
            car->hideCar();
        }
    }

    void Scene::allocateCars() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (map[i][j] > 0 && map[i][j] <= cars.size()) {
                    cars[map[i][j] - 1]->setCoords(allocX(i), allocY(j), dist);
                    cars[map[i][j] - 1]->setSize(carSizeX, carSizeY, carSizeZ);
                }
            }
        }
    }
    
    float Scene::allocX(int i) const { 
        return  step * i - (rows - 1) * step / 2;
        //step * i -- step of grid
        //(rows - 1) * step -- width of grid
        //(rows - 1) * step / 2 -- half of width of grid (to find center of grid)
    }
    float Scene::allocY(int j) const { 
        return  step * j - (columns - 1) * step / 2;
    }
    
    void Scene::draw_scene() {
        glViewport(0, 0, width, height);
        glClearColor(0.3, 0.0, 0.3, 0); //Background color
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        // To write a text----------------------------------------------------
        glOrtho(0, 1, 0, 1, -1, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        float xText = 0.17, yText = 0.95;
        char buffer[128];

        //While playing
        if (!finish) { 
            glColor3f(1, 1, 0);
            sprintf_s(buffer, "Esc: Exit, R: Restart, Q: reset records, 1-7 or A D: Switch Levels");
            draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buffer, 0.01, yText);

            glColor3f(0, 1, 0);
            sprintf_s(buffer, "Level: %d", currentLevel);
            draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buffer, 0.01, yText - 0.05);

            glColor3f(1, 0.6, 0);
            sprintf_s(buffer, "Time, sec: %d", time);
            draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buffer, 0.01, yText - 0.1);

            if (records[currentLevel - 1] > 0) {
                glColor3f(1, 1, 1);                
                sprintf_s(buffer, "Your record here: %d sec", records[currentLevel - 1]);
            }
            else {
                glColor3f(1, 0, 0);
                sprintf_s(buffer, "You've not got record here yet");
            }
            draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buffer, 0.01, yText - 0.15);
        }
        //When level is completed
        else { 
            if (records[currentLevel - 1] > time || records[currentLevel - 1] == 0) {
                records[currentLevel - 1] = time; //If user beated record, it is overwtitten
            }
            glColor3f(1, 1, 0);
            sprintf_s(buffer, "Level %d completed. Your time is %d sec", currentLevel, time);
            draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buffer, xText, yText);

            // Set record text color
            if (time <= records[currentLevel - 1]) {
                glColor3f(0, 1, 0); //Green - if user beat record
                sprintf_s(buffer, "Your NEW record is %d sec here =)", records[currentLevel - 1]);
            }
            else {
                glColor3f(1, 0.2, 0.2); //Red - if user didnt
                sprintf_s(buffer, "Your record is %d sec here =/", records[currentLevel - 1]);
            }
            draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buffer, xText, yText - 0.05); 

            //Judgement of records
            if (time >= 0 && time < 10) {
                glColor3f(1, 1, 1);
                sprintf_s(buffer, "Excellent result!");
            }
            else if (time >= 10 && time < 20) {
                glColor3f(0.3, 0.9, 0.3);
                sprintf_s(buffer, "Pretty good=)");
            }
            else if (time >= 20 && time < 40) {
                glColor3f(0.7, 0.7, 1);
                sprintf_s(buffer, "Not bad, but neither good");
            }
            else if (time >= 40 && time < 60) {
                glColor3f(1, 0.7, 0);
                sprintf_s(buffer, "I know you can do it better(=");
            }
            else if (time >= 60 && time < 100){
                glColor3f(1, 0.2, 0.2);
                sprintf_s(buffer, "...have you even tryed?");
            }
            else {
                glColor3f(0, 0, 0);
                sprintf_s(buffer, "Nothing to say...");
            }
            draw_string(GLUT_BITMAP_TIMES_ROMAN_24, buffer, xText, yText - 0.1);
            setRecords();
        }

        glPopMatrix();
        glFlush(); //To render text

        //Settings of light --------------------------------------------------
        float lightDiffuse[] = { 0.8, 0.9, 0.8, 1 };
        float lightAmbient[] = { 0.3, 0.3, 0.3, 1 }; 
        float lightSpecular[] = { 0.9, 0.9, 0.9, 1 };
        float lightPosition[] = { 0, 1, 1, 0 }; // Placement of bulb (lampochka)
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

        glPushMatrix();
        glLoadIdentity();
        glTranslatef(1, 1, 1);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glPopMatrix();
        glEnable(GL_LIGHTING); // Enable light in the scene   
        glEnable(GL_LIGHT0); //Create a bulb
        //----------------------------------------------------------------------

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60, width / height, 1, 400); //To create a perspective in the scene
        glMatrixMode(GL_MODELVIEW); // To enable work with a model
        glLoadIdentity();

        glTranslatef(0, 0, distZ);	// To place a camera relative to board
        glRotatef(angleX, 0, 1, 0);  // To rotate Oy of camera
        glRotatef(angleY, 1, 0, 0);  // To rotate Ox of camera
        glEnable(GL_DEPTH_TEST); 

        // Draw all objects of scene
        board->draw();
        for (const auto &car : cars) { car->draw(); }
        
        // Turn off lights
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST);

        glutSwapBuffers();
    }

    //Handle keyboard input
    void Scene::keyboard(unsigned char key, int x, int y)  {
        switch (key) {
        // Scale up
        case 'w':
            if (distZ >= -1.75) break;
            distZ += 0.1f;
            break;

        // Scale down
        case 's': 
            if (distZ <= -10) break;
            distZ -= 0.1f;
            break;

        //Restart current level
        case 'r': 
            initialize(); break;

        //Set all records to 0
        case 'q':
            resetRecords();
            break;

        //Switch level to the previous
        case 'a': 
            if (currentLevel - 1 < 1) {
                currentLevel = 7;
                initialize();
                break;
            }
            currentLevel--;
            initialize();
            break;

        //Switch level to the next
        case 'd':
            if (currentLevel + 1 > num_of_levels) {
                currentLevel = 1;
                initialize();
                break;
            }
            currentLevel++;
            initialize();
            break;

        // Switch levels by 1, 2, 3 etc burrons
        case '1': 
            currentLevel = 1;
            initialize();
            break;
        case '2':
            currentLevel = 2;
            initialize();
            break;
        case '3':
            currentLevel = 3;
            initialize();
            break;
        case '4':
            currentLevel = 4;
            initialize();
            break;
        case '5':
            currentLevel = 5;
            initialize();
            break;
        case '6':
            currentLevel = 6;
            initialize();
            break;
        case '7':
            currentLevel = 7;
            initialize();
            break;

        //Close window
        case 27:
            exit(0); 
        }
    }

    // Handle mouse clicking
    void Scene::mouse_click(int button, int state, int x, int y) {
        mouseX = x; mouseY = y;
        this->button = button;
        
        // if red car is placed where 2 red squares are (i.e. the level is completed)
        if (state == GLUT_UP && map[4][3] == 1) {
            finish = true;
            return;
        }
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
            findNearest(x, y, xFrom, yFrom, true); //Findig a car
        }
    }

    // Handle mouse dragging
    void Scene::mouse_move(int x, int y) {
        switch (button) 
        {
        //Left button - to move cars
        case GLUT_LEFT_BUTTON:
            if (finish) break;
            //Finding an empty spot where you can move car
            if (findNearest(x, y, xTo, yTo, false)) {
                if (moveCar(xFrom, yFrom, xTo, yTo)) {
                    xFrom = xTo;
                    yFrom = yTo;
                }
            }
            break;

        //Right button - to rotate scene
        case GLUT_RIGHT_BUTTON: 
            angleX += x - mouseX; 
            angleY += y - mouseY;
            mouseX = x; mouseY = y;
            break;
        }
        glutPostRedisplay();
    }

    void Scene::timer() {
        tick++;
        if (tick >= 40) {
            if (!finish) time++;
            tick = 0;
        }
        draw_scene(); //Redraw game
    }

    void Scene::resize(int width, int height) {
        this->width = width;
        if (height == 0) height = 1;
        this->height = height;
    }  
    
    bool Scene::findNearest(int x, int y, int& Ox, int& Oy, bool findCar) {
        int viewport[4];
        double mvMatrix[16], projMatrix[16];
        double minDist = 2000;
        int iMin = -1, jMin = -1;

        glGetIntegerv(GL_VIEWPORT, viewport);
        glGetDoublev(GL_MODELVIEW_MATRIX, mvMatrix);
        glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {

                // If we found a car, ignore empty spots. 
                // Otherwise if empty spot is found, ignore cars
                if ((findCar && map[i][j] == 0) || (!findCar && map[i][j] > 0)) {
                    continue;
                }

                double wx = allocX(i);
                double wy = allocY(j);
                double wz = dist;
                double dX, dY, dZ;

                gluProject(wx, wy, wz, mvMatrix, projMatrix, viewport, &dX, &dY, &dZ);

                dY = viewport[3] - dY - 1;
                double distance = (x - dX) * (x - dX) + (y - dY) * (y - dY);

                if (distance < minDist) {
                    minDist = distance;
                    iMin = i; jMin = j;
                }
            }
        }

        //Different distances for finding car or empty spot
        float n = findCar ?  800.0f : 300.0f; 
        if (minDist < n) {
            Ox = iMin;
            Oy = jMin;
            return true;
        }
        return false;
    }
    
    bool Scene::moveCar(int xFrom, int yFrom, int xTo, int yTo) {
        // If coords are outside the matrix
        if (xFrom < 0 || yFrom < 0 || xTo < 0 || yTo < 0 ||
            xFrom >= rows || yFrom >= columns || xTo >= rows || yTo >= columns) {
            return false;
        }

        int carIndex = map[xFrom][yFrom] - 1;
        
        // If car coords are the same as destination coords
        if (xFrom == xTo && yFrom == yTo) { return false; }
        if (abs(yFrom - yTo) > 1 || abs(xFrom - xTo) > 1) { return false; }

        //Check collisions for vertical cars   
        if (cars[carIndex]->isVert()) {      
            if (yTo < 1) {
                return false;
            }
            //Collision in the center of board
            if ((xFrom > 0 && xFrom < 5) && (yFrom > 1 && yFrom < 5)) {
                if ((map[xFrom - 1][yTo - 1] > 0 && !cars[map[xFrom - 1][yTo - 1] - 1]->isVert())
                    || (map[xFrom][yTo - 1] > 0 && !cars[map[xFrom][yTo - 1] - 1]->isVert())
                    || (map[xFrom - 1][yTo] > 0 && !cars[map[xFrom - 1][yTo] - 1]->isVert())
                    || (map[xFrom][yTo] > 0 && !cars[map[xFrom][yTo] - 1]->isVert())) {
                    return false;
                }
                if (((yTo + 1 < columns && map[xFrom][yTo + 1] > 0 
                    && map[xFrom][yTo + 1] != map[xFrom][yFrom])
                    && cars[map[xFrom][yTo + 1] - 1]->isVert())
                    || ((yTo - 1 >= 0 && map[xFrom][yTo - 1] > 0 
                    && map[xFrom][yTo - 1] != map[xFrom][yFrom]) 
                    && cars[map[xFrom][yTo - 1] - 1]->isVert())) {
                    return false;
                }
            }

            //Upper side
            if (yFrom == 5 && (xFrom > 0 && xFrom < 5) ) { 
                if ((map[xFrom - 1][yTo - 1] > 0 && !cars[map[xFrom - 1][yTo - 1] - 1]->isVert())
                    || map[xFrom][yTo - 1] > 0 && !cars[map[xFrom][yTo - 1] - 1]->isVert()) {
                    return false;
                }
                if (((yTo - 1 >= 0 && map[xFrom][yTo - 1] > 0
                    && map[xFrom][yTo - 1] != map[xFrom][yFrom])
                    && cars[map[xFrom][yTo - 1] - 1]->isVert())) {
                    
                    return false;
                }
            }

            //Lower side
            if (yFrom == 1 && (xFrom > 0 && xFrom < 5)) { 
                if ((map[xFrom - 1][yTo] > 0 && !cars[map[xFrom - 1][yTo] - 1]->isVert())
                    || (map[xFrom][yTo] > 0 && !cars[map[xFrom][yTo] - 1]->isVert())) {
                    
                    return false;
                }
                if (((yTo + 1 < columns && map[xFrom][yTo + 1] > 0
                    && map[xFrom][yTo + 1] != map[xFrom][yFrom])
                    && cars[map[xFrom][yTo + 1] - 1]->isVert())) {
                    
                    return false;
                }
            }

            //Left side
            if ((yFrom > 1 && yFrom < 5) && xFrom == 0) { 
                if ((map[xFrom][yTo - 1] > 0 && !cars[map[xFrom][yTo - 1] - 1]->isVert())
                    || (map[xFrom][yTo] > 0 && !cars[map[xFrom][yTo] - 1]->isVert())) {
                    
                    return false;
                }
                if (((yTo + 1 < columns && map[xFrom][yTo + 1] > 0
                    && map[xFrom][yTo + 1] != map[xFrom][yFrom])
                    && cars[map[xFrom][yTo + 1] - 1]->isVert())
                    || ((yTo - 1 >= 0 && map[xFrom][yTo - 1] > 0
                        && map[xFrom][yTo - 1] != map[xFrom][yFrom])
                        && cars[map[xFrom][yTo - 1] - 1]->isVert())) {
                    
                    return false;
                }
            }

            //Right side
            if ((yFrom > 1 && yFrom < 5) && xFrom == 5) { 
                if ((map[xFrom - 1][yTo] > 0 && !cars[map[xFrom - 1][yTo] - 1]->isVert())
                    || (map[xFrom - 1][yTo - 1] > 0 && !cars[map[xFrom - 1][yTo - 1] - 1]->isVert())) {
                    return false;
                }
                if (((yTo + 1 < columns && map[xFrom][yTo + 1] > 0
                    && map[xFrom][yTo + 1] != map[xFrom][yFrom])
                    && cars[map[xFrom][yTo + 1] - 1]->isVert())
                    || ((yTo - 1 >= 0 && map[xFrom][yTo - 1] > 0
                        && map[xFrom][yTo - 1] != map[xFrom][yFrom])
                        && cars[map[xFrom][yTo - 1] - 1]->isVert())) {
                    return false;
                }
            }

            //===Corners===
            // 
            //Left upper corner
            if ((xFrom == 0 || xFrom == 5) && yFrom == 5) { 
                if (map[xFrom][yFrom - 2] > 0 
                    && !cars[map[xFrom][yFrom - 2] - 1]->isVert()) {
                    return false;
                }
                if (map[xFrom][yTo - 1] > 0 && cars[map[xFrom][yTo - 1] - 1]->isVert()) {
                    return false;
                }
            }

            //Right upper corner
            if ((xFrom == 5) && yFrom == 5) { 
                if (map[xFrom - 1][yTo - 1] > 0
                    && !cars[map[xFrom - 1][yTo - 1] - 1]->isVert()) {
                    return false;
                }
                if (map[xFrom][yTo - 1] > 0 && cars[map[xFrom][yTo - 1] - 1]->isVert()) {
                    return false;
                }
            }

            //Right lower corner
            if ((xFrom == 5) && yFrom == 1) {
                if (map[xFrom - 1][yTo + 1] > 0 
                    && !cars[map[xFrom - 1][yTo] - 1]->isVert()) {
                    return false;
                }
                if (map[xFrom][yTo + 1] > 0 && cars[map[xFrom][yTo + 1] - 1]->isVert()) {
                    return false;
                }
            }

            //Left lower corner
            if ((xFrom == 0) && yFrom == 1) {
                if (map[xFrom][yFrom + 1] > 0
                    && cars[map[xFrom][yFrom + 1] - 1]->isVert()) {
                    return false;
                }
                if (map[xFrom][yTo + 1] > 0 && cars[map[xFrom][yTo + 1] - 1]->isVert()) {
                    return false;
                }
            }
        }

        //Check collisions for horizontal cars--------------------------------------    
        else {
            //Collisiom with the end of board
            if (xTo > 4) { 
                return false;
            }
            
            // Center of board
            if ((xFrom > 0 && xFrom < 4) && (yFrom > 0 && yFrom < 5)) { 
                if ((xTo + 1 < rows && yFrom + 1 < columns && map[xTo + 1][yFrom + 1] > 0 
                    && cars[map[xTo + 1][yFrom + 1] - 1]->isVert())
                    || (xTo + 1 < rows && map[xTo + 1][yFrom] > 0 && cars[map[xTo + 1][yFrom] - 1]->isVert())
                    || (yFrom + 1 < columns && map[xTo][yFrom + 1] > 0 && cars[map[xTo][yFrom + 1] - 1]->isVert())
                    || (map[xTo][yFrom] > 0 && cars[map[xTo][yFrom] - 1]->isVert())) {
                    return false;
                }

                // Check collision with horizontal cars, excluding the initial position
                if (((xTo + 1 < rows && map[xTo + 1][yFrom] > 0 
                    && map[xTo + 1][yFrom] != map[xFrom][yFrom])
                    && !cars[map[xTo + 1][yFrom] - 1]->isVert())
                    || ((xTo - 1 >= 0 && map[xTo - 1][yFrom] > 0 
                    && map[xTo - 1][yFrom] != map[xFrom][yFrom]) 
                    && !cars[map[xTo - 1][yFrom] - 1]->isVert())) {
                    return false;
                }
            }
            
            //Collisions on the sides
            if (yFrom == 5 && (xFrom > 0 && xFrom < 4)) { //Upper side
                if ((map[xTo + 1][yFrom] > 0 && cars[map[xTo + 1][yFrom] - 1]->isVert())
                    || (map[xTo][yFrom] > 0 && cars[map[xTo][yFrom] - 1]->isVert())) {
                    return false;
                }
                if (((xTo + 1 < rows && map[xTo + 1][yFrom] > 0
                    && map[xTo + 1][yFrom] != map[xFrom][yFrom])
                    && !cars[map[xTo + 1][yFrom] - 1]->isVert())
                    || ((xTo - 1 >= 0 && map[xTo - 1][yFrom] > 0
                        && map[xTo - 1][yFrom] != map[xFrom][yFrom])
                        && !cars[map[xTo - 1][yFrom] - 1]->isVert())) {

                    return false;
                }
            }
            if (yFrom == 0 && (xFrom > 0 && xFrom < 4)) { //Lower side
                if (map[xTo + 1][yFrom + 1] > 0 && cars[map[xTo + 1][yFrom + 1] - 1]->isVert()
                    || map[xTo][yFrom + 1] > 0 && cars[map[xTo][yFrom + 1] - 1]->isVert()) {
                    return false;
                }
                if (((xTo + 1 < rows && map[xTo + 1][yFrom] > 0
                    && map[xTo + 1][yFrom] != map[xFrom][yFrom])
                    && !cars[map[xTo + 1][yFrom] - 1]->isVert())
                    || ((xTo - 1 >= 0 && map[xTo - 1][yFrom] > 0
                        && map[xTo - 1][yFrom] != map[xFrom][yFrom])
                        && !cars[map[xTo - 1][yFrom] - 1]->isVert())) {

                    return false;
                }
            }
            if ((yFrom > 0 && yFrom < 5) && xFrom == 0) { //Left side
                if (map[xTo + 1][yFrom + 1] > 0 && cars[map[xTo + 1][yFrom + 1] - 1]->isVert()
                    || map[xTo + 1][yFrom] > 0 && cars[map[xTo + 1][yFrom] - 1]->isVert()) {
                    return false;
                }
                if (map[xTo + 1][yFrom] > 0 && !cars[map[xTo + 1][yFrom] - 1]->isVert()) {
                    return false;
                }
            }
            if ((yFrom > 0 && yFrom < 5) && xFrom == 4) { //Right side
                if (map[xTo][yFrom + 1] > 0 && cars[map[xTo][yFrom + 1] - 1]->isVert()
                    || map[xTo][yFrom] > 0 && cars[map[xTo][yFrom] - 1]->isVert()) {
                    return false;
                }
                if (map[xTo - 1][yFrom] > 0 && !cars[map[xTo - 1][yFrom] - 1]->isVert()) {
                    return false;
                }
            }

            //Corners
            if (xFrom == 0 && yFrom == 5) { //Left upper corner
                if (map[xTo + 1][yFrom] > 0 && cars[map[xTo + 1][yFrom] - 1]->isVert()) {
                    return false;
                }
                if (map[xTo + 1][yFrom] > 0 && !cars[map[xTo + 1][yFrom] - 1]->isVert()) {
                    return false;
                }
            }
            if (xFrom == 4 && yFrom == 5) { //Right upper corner
                if (map[xTo][yFrom] > 0 && cars[map[xTo][yFrom] - 1]->isVert()) {
                    return false;
                }
                if (map[xTo - 1][yFrom] > 0 && !cars[map[xTo - 1][yFrom] - 1]->isVert()) {
                    return false;
                }
            }
            if (xFrom == 4 && yFrom == 0) { //Right lower corner
                if (map[xTo][yFrom + 1] > 0 && cars[map[xTo][yFrom + 1] - 1]->isVert()) {
                    return false;
                }
                if (map[xTo - 1][yFrom] > 0 && !cars[map[xTo - 1][yFrom] - 1]->isVert()) {
                    return false;
                }
            }
            if (xFrom == 0 && yFrom == 0) { //Left lower corner
                if (map[xTo + 1][yFrom + 1] > 0 && cars[map[xTo + 1][yFrom + 1] - 1]->isVert()) {
                    return false;
                }
                if (map[xTo + 1][yFrom] > 0 && !cars[map[xTo + 1][yFrom] - 1]->isVert()) {
                    return false;
                }
            }
        }

        // Moving
        if (cars[carIndex]->isVert()) {
            cars[carIndex]->setYCenter(allocY(yTo)); // Move vertical car
        }
        else {
            cars[carIndex]->setXCenter(allocX(xTo)); // Move horizontal car
        }
        map[xTo][yTo] = map[xFrom][yFrom]; //Change info in the map
        map[xFrom][yFrom] = 0;
        return true;
    }
}
