//main.cpp
#include "glut.h"
#include "Scene.h"

RushHourGame::Scene* scene;

static void draw_scene() { scene->draw_scene(); }
static void timer(int) {
    scene->timer();
    glutTimerFunc(25, timer, 0);
}
static void mouse_click(int button, int state, int x, int y) {
    scene->mouse_click(button, state, x, y);
}
static void mouse_move(int x, int y) { scene->mouse_move(x, y); }

static void resize(int width, int height) { scene->resize(width, height); }

static void keyboard(unsigned char key, int x, int y) { scene->keyboard(key, x, y); }

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    scene = new RushHourGame::Scene();

    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Rush Hour Game");

    glutDisplayFunc(draw_scene);
    glutReshapeFunc(resize);
    glutMotionFunc(mouse_move);
    glutMouseFunc(mouse_click);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(25, timer, 0);

    glutMainLoop();

    delete scene;
    return 0;
}
