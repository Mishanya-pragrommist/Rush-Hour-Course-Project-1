//Board.CPP
#include "Board.h"
#include "UsefulStuff.h"

namespace RushHourGame
{
    void Board::draw_finish_square() {
        glMaterialfv(GL_FRONT, GL_AMBIENT, UsefulStuff::ambiRed);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, UsefulStuff::diffRed);
        glMaterialfv(GL_FRONT, GL_SPECULAR, UsefulStuff::specRed);
        
        glBegin(GL_QUADS);
        glNormal3f(0, 0, 1);
        glVertex3f(0.6, 0.2, 0.065);
        glVertex3f(0.2, 0.2, 0.065);
        glVertex3f(0.2, 0, 0.065);
        glVertex3f(0.6, 0, 0.065);
        
        glEnd();
    }
    void Board::drawGrid() {
        glMaterialfv(GL_FRONT, GL_AMBIENT, UsefulStuff::ambiBlack);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, UsefulStuff::diffBlack);
        glMaterialfv(GL_FRONT, GL_SPECULAR, UsefulStuff::specBlack);
        glMaterialf(GL_FRONT, GL_SHININESS, 20);

        glLineWidth(3);
        glBegin(GL_LINES);
        for (float y = -0.6; y <= 0.6; y += 0.2) { // Horizontal lines
            glVertex3f(-0.6, y, 0.065);
            glVertex3f(0.6, y, 0.065);
        }
        for (float x = -0.6; x <= 0.6; x += 0.2) { // Vertical lines
            glVertex3f(x, -0.6, 0.065);
            glVertex3f(x, 0.6, 0.065);
        }
        glEnd();
    }

    void Board::draw() {
        glMaterialfv(GL_FRONT, GL_AMBIENT, getAmbiColor());
        glMaterialfv(GL_FRONT, GL_DIFFUSE, getDiffColor());
        glMaterialfv(GL_FRONT, GL_SPECULAR, getSpecColor());
        glMaterialf(GL_FRONT, GL_SHININESS, UsefulStuff::shininess);

        glPushMatrix();
        glTranslatef(getXCenter(), getYCenter(), getZCenter());

        UsefulStuff::draw_parallelepiped(getXSize(), getYSize(), getZSize());
        drawGrid();
        draw_finish_square();

        glPopMatrix();
    }
}
