//Car.CPP
#include "UsefulStuff.h"
#include "Car.h"

namespace RushHourGame
{
    void Car::draw() {
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, getAmbiColor());
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, getDiffColor());
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, getSpecColor());
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, UsefulStuff::shininess);
        glPushMatrix();
        
        glTranslatef(getXCenter(), getYCenter(), getZCenter());
        
        if (!isVert()) {
            glRotatef(90, 0, 0, 1); //To set vertical direction
        }
        glTranslatef(0, -0.1, 0); //Center shift right/down
        UsefulStuff::draw_parallelepiped(getXSize(), getYSize(), getZSize());
        
        glPopMatrix();
    }
}
