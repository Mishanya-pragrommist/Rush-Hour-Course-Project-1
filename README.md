# Rush Hour Game (OpenGL & C++)
A 3D computer implementation of the classic logic 
puzzle game "Rush Hour", developed 
as a coursework project.
The application features a 3D environment
where players must move vehicles
to clear a path for the red car 
to reach the exit.

## Features
- Built using the OpenGL and freeGLUT libraries.
- OOP Architecture: uses an abstract base class Object with inheritance 
and polymorphism for game elements like the Board and Car.
- Collision detection prevents cars from passing through each other
- Includes 7 unique levels with increasing complexity.
- Saves and reads best completion time from a "records.txt" file.
- Support for scene rotation, scaling, and real-time time tracking.

## Technical Stack
1. Language: C++
2. Graphics API: OpenGL
3. Window Management: freeGLUT 
4. Design Pattern: Object-Oriented Programming (OOP)

## Controls
* LMB (Hold & Drag) - Select and move a car 
* RMB (Hold & Drag) - Rotate the game board (scene rotation) 
* W / S - Zoom In / Zoom Out (Scale scene)
* A / D - Switch between levels
* 1 – 7 - Jump to a specific level
* R - Restart current level
* Q - Reset all records
* Esc - Exit game

## Class Hierarchy
The project follows a modular structure with several key classes:
- Scene. The main controller that manages level state, rendering loops, event handling (mouse/keyboard), and time.
- Object. An abstract base class defining position, size, 
color properties, and a virtual method draw().
- Board. Inherits from Object; handles rendering the 6x6 grid and the finish line.
- Car. Inherits from Object; handles vehicle orientation (vertical/horizontal) 
and movement logic

## File Structure

1) main.cpp - entry point, freeGLUT initialization.
2) Scene.h/cpp - game logic and scene management.
3) Object.h/cpp - base class for 3D entities.
4) Board.h/cpp - game board rendering.
5) Car.h/cpp - vehicle properties and behavior.
6) UsefulStuff.h/cpp: Namespaces for colors, text rendering, and geometric primitives.

## Installation & Running
1. Ensure you have a C++ compiler installed.
2. Open command line in project folder and run the following command:
- g++ *.cpp -o RushHour -I"freeglut-MSVC-3.0.0-2.mp\include" -L"freeglut-MSVC-3.0.0-2.mp\lib" -lfreeglut -lopengl32 -lglu32 -static-libgcc -static-libstdc++
3. Run the application:
- ./RushHour.exe 
- (or just find the file RushHour.exe and click twice on it)

Another way - by using Visual Studio:
1) Open file "Semester Project, ended version.sln".
2) Press Ctrl + B to compile the project.
3) Press Ctrl + F5 to run it.

Please note that to run this application there should 
be file freeglut.h near the .exe file

## Author
Developed by Mykhailo Bondarenko, Student of group KN-223v, National technical university "Kharkiv Polytechnic institute"
