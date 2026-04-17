//UsefulStuff.CPP
#include "UsefulStuff.h"

namespace UsefulStuff
{
	//Diff - main color, ambi - color of shadow, spec - glare
	
	//Colors for cars
	float diffPink[] = { 1, 0.3, 0.3 }; //Pink
	float ambiPink[] = { 0.45, 0.1, 0.13 };
	float specPink[] = { 0.8, 0.5, 0.5};

	float diffRed[] = {0.9, 0, 0}; //Red
	float ambiRed[] = {0.7, 0, 0.1};
	float specRed[] = {0.8, 0.6, 0.6};

	float diffOrange[] = {0.7, 0.4, 0}; //Orange
	float ambiOrange[] = {0.4, 0.1, 0};
	float specOrange[] = {0.8, 0.5, 0.4};

	float diffYellow[] = { 0.9, 0.9, 0}; //Yellow
	float ambiYellow[] = { 0.2, 0.1, 0.2 };
	float specYellow[] = { 0.9, 0.9, 0.5 };
	
	float diffGreen[] = { 0, 0.7, 0 }; //Green
	float ambiGreen[] = { 0.1, 0.2, 0.1 };
	float specGreen[] = { 0.2, 0.8, 0.2 };

	float diffVomitGreen[] = {0.4, 0.4, 0.1}; //Vomit green
	float ambiVomitGreen[] = {0.1, 0.1, 0};
	float specVomitGreen[] = {0.6, 0.6, 0.2};

	float diffBlue[] = {0.3, 0.3, 0.7}; //Blue
	float ambiBlue[] = {0.05, 0.05, 0.5};
	float specBlue[] = {0.5, 0.5, 0.8};
	
	float diffDarkBlue[] = {0, 0, 0.6}; //Dark blue
	float ambiDarkBlue[] = {0, 0, 0.3};
	float specDarkBlue[] = {0.3, 0.3, 0.8};	

	float diffPurple[] = {0.5, 0, 0.5}; //Purple
	float ambiPurple[] = {0.2, 0, 0.2};
	float specPurple[] = {0.7, 0, 0.7};

	float diffLightGray[] = { 0.7, 0.7, 0.7 }; //Light gray
	float ambiLightGray[] = { 0.3, 0.3, 0.4 };
	float specLightGray[] = { 0.85, 0.85, 0.8 };

	float diffWhite[] = { 0.85, 0.85, 0.85 }; //White
	float ambiWhite[] = { 0.5, 0.5, 0.5 };
	float specWhite[] = { 0.95, 0.95, 0.95 };

	//Colors for board
	float diffGray[] = { 0.5, 0.5, 0.5 }; //Grey
	float ambiGray[] = { 0.1, 0.1, 0.1 };
	float specGray[] = { 0.7, 0.7, 0.7 };

	//Colors for grid
	float diffBlack[] = { 0.2, 0.2, 0.2 }; //Black
	float ambiBlack[] = { 0.1, 0.1, 0.1 };
	float specBlack[] = { 0.4, 0.4, 0.4 };

	const float shininess = 64;

	void draw_parallelepiped(float x, float y, float z) {
		glBegin(GL_QUADS);

		// Front face
		glNormal3f(0, 0, 1);
		glVertex3f(-x, -y, z);
		glVertex3f(x, -y, z);
		glVertex3f(x, y, z);
		glVertex3f(-x, y, z);

		// Back face
		glNormal3f(0, 0, -1);
		glVertex3f(-x, -y, -z);
		glVertex3f(-x, y, -z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, -z);

		// Upper face
		glNormal3f(0, 1, 0);
		glVertex3f(-x, y, z);
		glVertex3f(x, y, z);
		glVertex3f(x, y, -z);
		glVertex3f(-x, y, -z);

		// Lower face
		glNormal3f(0, -1, 0);
		glVertex3f(-x, -y, z);
		glVertex3f(x, -y, z);
		glVertex3f(x, -y, -z);
		glVertex3f(-x, -y, -z);

		// Left face
		glNormal3f(-1, 0, 0);
		glVertex3f(-x, -y, z);
		glVertex3f(-x, y, z);
		glVertex3f(-x, y, -z);
		glVertex3f(-x, -y, -z);

		// Right face
		glNormal3f(1, 0, 0);
		glVertex3f(x, -y, z);
		glVertex3f(x, y, z);
		glVertex3f(x, y, -z);
		glVertex3f(x, -y, -z);

		glEnd();
	}

	void draw_string(void* font, const char* text, float x, float y) {
		if (text == nullptr) return;
		
		glRasterPos2f(x, y); // Placing string
		while (*text) { //Printing string byte by byte
			glutBitmapCharacter(font, *text);
			text++;
		}
	}
}
