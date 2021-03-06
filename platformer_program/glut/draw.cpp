#include "screencasts.h"





/*
* drawCube()
* ------
* Draws a cube
*/
void drawCube(cube_s cb)
{
	//the molecule at coordinates 0;0;0 can not be used!!! (it won't be drawn)
	if (cb.tsr.hely.x >0 || cb.tsr.hely.y>0 || cb.tsr.hely.z>0)
	{
		cube(cb.tsr.t.x, cb.tsr.t.y, cb.tsr.t.z,
			cb.tsr.s.x, cb.tsr.s.y, cb.tsr.s.z,
			cb.tsr.r.y, cb.tsr.hely.x, cb.tsr.hely.y, cb.tsr.hely.z);
	}
}

void drawPlatform(platform_s cb)
{
	//the molecule at coordinates 0;0;0 can not be used!!! (it won't be drawn)
	
		negyzetracs(cb.tsr.t.x, cb.tsr.t.y, cb.tsr.t.z,
			cb.tsr.s.x, cb.tsr.s.y, cb.tsr.s.z,
			cb.tsr.r.y, cb.tsr.hely.x, cb.tsr.hely.y, cb.tsr.hely.z,cb.tsr.tobbi.x,cb.tsr.tobbi.y,cb.tsr.tobbi.z);
	
}

/*
*  drawLight
*  ------
*  Draws the light
*/
void drawLight(void)
{
	/*  Light switch */
	if (toggleLight) {
		/*  Translate intensity to color vectors */
		GLfloat Ambient[] = { 0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0 };
		GLfloat Diffuse[] = { 0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0 };
		GLfloat Specular[] = { 0.01*specular,0.01*specular,0.01*specular,1.0 };
		GLfloat Position[] = { distance*Sin(lightPh),lightY,distance*Cos(lightPh),1.0 };

		/*  Draw light position as sphere (still no lighting here) */
		glColor3fv(white);
		glDisable(GL_LIGHTING);
		sphere(Position[0], Position[1], Position[2], 0.1, 0);

		/*  Set ambient, diffuse, specular components and position of light 0 */
		/*
		Light uses the Phong model
		Once light is enabled, colors assigned by glColor* isn't used
		Ambient is light that's been scattered by environment that its direction is impossible to determine
		Diffuse is is light that comes from one direction, so it's brighter if it comes squarely on surface rather than glances off
		Specular is light that comes from a particular direction and bounces off in preferred direction
		Position is the position of our light. In this case it is the same as the sphere.
		*/
		glLightfv(GL_LIGHT0, GL_AMBIENT, Ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse);
		glLightfv(GL_LIGHT0, GL_POSITION, Position);
		glLightfv(GL_LIGHT0, GL_SPECULAR, Specular);

		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
	}
	else {
		glDisable(GL_LIGHTING);
	}
}

/*
*  drawParameters()
*  ------
*  Draw the parameters in the lower left corner
*/
void drawParameters(void)
{
	drawLight();

	if (toggleParams) 
	{
		glColor3fv(white);

		/*  Display parameters */
		printAt(30, 40, "Points = %i",space);
		printAt(30, 25, "Level = %i", (space+9)/10);
		printAt(30, 10, "Highest Score = %i",highscore);
		if (space >= 100) printAt(900, 800, "YOU WON!!!");
	
		

		
		

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(1, 1, 1, 0.4);
	}
}

/*
* drawScene()
* ------
* Draws the scene with everything we need in it
*/
void drawScene(void)
{
	
	//drawAxes();
	
	drawParameters();
	drawLight();	

	

	//inicializ�lt kock�k rajzol�sa
	
	drawCube(cubes[10000]);
	drawPlatform(platform[0]);
	
	
	currentTexture = textures[TEX_DEFAULT];
}