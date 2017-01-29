#include "screencasts.h"



/*
*  cube
*  ------
*  Draw a cube
*     at (x,y,z)
*     dimensions (dx,dy,dz)
*     rotated th about the y axis
*  TODO: Refactor this!!!
*/
void cube(double x, double y, double z,double dx, double dy, double dz,double th,int i,int j,int k)
{
	//if (dronpa[i+1][j+1][k+1].ter == true)  glColor4f(0, 1, 0, 1);	//zöld szín ha térrel terhelt molekulát adunk meg
	//else glColor4f(1, 0, 0, 1);		//alap piros szín

	/*  Cube vertices */
	GLfloat vertA[3] = { 1, 1, 1 };
	GLfloat vertB[3] = { 0, 1, 1 };
	GLfloat vertC[3] = { 0,0, 1 };
	GLfloat vertD[3] = { 1,0, 1 };
	GLfloat vertE[3] = { 1, 1,0 };
	GLfloat vertF[3] = { 0, 1,0 };
	GLfloat vertG[3] = { 0,0,0 };
	GLfloat vertH[3] = { 1,0,0 };

	glPushMatrix();
	/*  Transform */
	glTranslated(x, y, z);
	glRotated(th, 0, 1, 0);
	glScaled(dx, dy, dz);

	
	glEnable(GL_TEXTURE_2D);
	/* using the current texture */
	currentTexture = textures[1];
	glBindTexture(GL_TEXTURE_2D, currentTexture);

	/* Cube */
	/* front => ABCD */
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3fv(vertA);
	glTexCoord2f(1, 0); glVertex3fv(vertB);
	glTexCoord2f(1, 1); glVertex3fv(vertC);
	glTexCoord2f(0, 1); glVertex3fv(vertD);
	glEnd();

	/* back => FEHG */
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3fv(vertF);
	glTexCoord2f(1, 0); glVertex3fv(vertE);
	glTexCoord2f(1, 1); glVertex3fv(vertH);
	glTexCoord2f(0, 1); glVertex3fv(vertG);
	glEnd();

	/* right => EADH */
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glTexCoord2f(0, 0); glVertex3fv(vertE);
	glTexCoord2f(1, 0); glVertex3fv(vertA);
	glTexCoord2f(1, 1); glVertex3fv(vertD);
	glTexCoord2f(0, 1); glVertex3fv(vertH);
	glEnd();

	/* left => BFGC */
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glTexCoord2f(0, 0); glVertex3fv(vertB);
	glTexCoord2f(1, 0); glVertex3fv(vertF);
	glTexCoord2f(1, 1); glVertex3fv(vertG);
	glTexCoord2f(0, 1); glVertex3fv(vertC);
	glEnd();

	/* top => EFBA */
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0, 0); glVertex3fv(vertE);
	glTexCoord2f(1, 0); glVertex3fv(vertF);
	glTexCoord2f(1, 1); glVertex3fv(vertB);
	glTexCoord2f(0, 1); glVertex3fv(vertA);
	glEnd();

	/* bottom => DCGH */
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);
	glTexCoord2f(0, 0); glVertex3fv(vertD);
	glTexCoord2f(1, 0); glVertex3fv(vertC);
	glTexCoord2f(1, 1); glVertex3fv(vertG);
	glTexCoord2f(0, 1); glVertex3fv(vertH);
	glEnd();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

/*
*  sphere
*  ------
*  Draw a sphere
*     at (x,y,z)
*     radius (r)
*     rotated rot around the y axis
*/
void sphere(double x, double y, double z, double r, double rot)
{
	int th, ph;
	float yellow[] = { 1.0,1.0,0.0,1.0 };
	float emissions[] = { 0.0,0.0,0.01*emission,1.0 };
	/*
	Material shininess = specular exponent
	Material specular = specular color of material
	Material emission = simulates original lighting from an object
	*/
	glMaterialfv(GL_FRONT, GL_SHININESS, shinyvec);
	glMaterialfv(GL_FRONT, GL_SPECULAR, yellow);
	glMaterialfv(GL_FRONT, GL_EMISSION, emissions);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, currentTexture);
	glPushMatrix();

	/*  Transform */
	glTranslated(x, y, z);
	glScaled(r, r, r);
	glRotated(rot, 0, 1, 0);

	/*  Bands of latitude */
	for (ph = -90; ph<90; ph += DEF_D) {
		glBegin(GL_QUAD_STRIP);
		for (th = 0; th <= 360; th += 2 * DEF_D) {
			vertex(th, ph);
			vertex(th, ph + DEF_D);
		}
		glEnd();
	}

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

/*
*  vertex
*  ------
*  Draw vertex in polar coordinates with normal
*/
void vertex(double th, double ph)
{
	double x = Sin(th)*Cos(ph);
	double y = Cos(th)*Cos(ph);
	double z = Sin(ph);
	/*  For a sphere at the origin, the position
	and normal vectors are the same */
	glNormal3d(x, y, z);
	glTexCoord2d(th / 360.0, ph / 180.0 + 0.5);
	glVertex3d(x, y, z);
}

//koordináták printelése az adott helyre, ezt most nem használjuk
void szoveg(int hely,double x, double y, double z,double dx, double dy, double dz,double th)
{
	/*  Cube vertices */
	GLfloat vertA[3] = { 0.5, 0.5, 0.5 };
	

	glPushMatrix();
	/*  Transform */
	glTranslated(x, y, z);
	glRotated(th, 0, 1, 0);
	glScaled(dx, dy, dz);

	glRasterPos3fv(vertA);
	print("%i",hely);

	

	glPopMatrix();
	
}

//ugyanaz mint a cube függvény, csak kisebb fekete kockákat rajzol
void negyzetracs(double x, double y, double z,double dx, double dy, double dz,double th,int i, int j,int k, double s, int ii, int kk)
{
	
	

	
	glRotated(th, 0, 1, 0);
	glScaled(dx, dy, dz);
	glEnable(GL_TEXTURE_2D);
	glNormal3f(0, 0, 1);

	currentTexture = textures[0];
	glBindTexture(GL_TEXTURE_2D, currentTexture);
	glBegin(GL_QUADS);


	
	
				






						/*  Cube vertices */
	GLfloat A[3] = { 0.5 + s / 2 + ii, 1 , 0.5 + s / 2 + kk };
	GLfloat B[3] = { 0.5 - s / 2 + ii, 1 , 0.5 + s / 2 + kk };
	GLfloat C[3] = { 0.5 - s / 2 + ii,0 , 0.5 + s / 2 + kk };
	GLfloat D[3] = { 0.5 + s / 2 + ii,0 , 0.5 + s / 2 + kk };
	GLfloat E[3] = { 0.5 + s / 2 + ii, 1 ,0.5 - s / 2 + kk };
	GLfloat F[3] = { 0.5 - s / 2 + ii, 1 ,0.5 - s / 2 + kk };
	GLfloat G[3] = { 0.5 - s / 2 + ii,0,0.5 - s / 2 + kk };
	GLfloat H[3] = { 0.5 + s / 2 + ii,0 ,0.5 - s / 2 + kk };

	/* Cube */
	/* front => ABCD */
	/* back => FEHG */
	/* right => EADH */
	/* left => BFGC */
	/* top => EFBA */
	/* bottom => DCGH */
	glTexCoord2f(0, 0); glVertex3fv(A);
	glTexCoord2f(1, 0); glVertex3fv(B);
	glTexCoord2f(1, 1); glVertex3fv(C);
	glTexCoord2f(0, 1); glVertex3fv(D);

	glTexCoord2f(0, 0); glVertex3fv(F);
	glTexCoord2f(1, 0); glVertex3fv(E);
	glTexCoord2f(1, 1); glVertex3fv(H);
	glTexCoord2f(0, 1); glVertex3fv(G);

	glTexCoord2f(0, 0); glVertex3fv(E);
	glTexCoord2f(1, 0); glVertex3fv(A);
	glTexCoord2f(1, 1); glVertex3fv(D);
	glTexCoord2f(0, 1); glVertex3fv(H);

	glTexCoord2f(0, 0); glVertex3fv(B);
	glTexCoord2f(1, 0); glVertex3fv(F);
	glTexCoord2f(1, 1); glVertex3fv(G);
	glTexCoord2f(0, 1); glVertex3fv(C);

	glTexCoord2f(0, 0); glVertex3fv(E);
	glTexCoord2f(1, 0); glVertex3fv(F);
	glTexCoord2f(1, 1); glVertex3fv(B);
	glTexCoord2f(0, 1); glVertex3fv(A);

	glTexCoord2f(0, 0); glVertex3fv(D);
	glTexCoord2f(1, 0); glVertex3fv(C);
	glTexCoord2f(1, 1); glVertex3fv(G);
	glTexCoord2f(0, 1); glVertex3fv(H);
					
					

					
		
		glEnd();
	
	
	
	glDisable(GL_TEXTURE_2D);
}
