#include "screencasts.h"
using namespace std;


// parameters for equations
double dt = 0.01;
double t = 0;
double K = -0.07;
double Ce = 0.18;
double tav = 343;
double taue = 1.51;
double Cp = 0.153;
double taup = 5.7;

double U = 0;
double Ce1 = 0.008;
double Ce2 = 180;
double Cp1 = 0.037;
double Cp2 = 153;



// handle movement and rotation
void windowPmotion(int x, int y)
{
	mouseX = x;
	mouseY = y;
	
	//light rotation
	if (Shift == "light")
	{
		if (mouseBtnPressed == "Left")
		{
			xcoord = mouseX;
			ycoord = mouseY;
			lightTh2 = lightTh;
			lightPh2 = lightPh;
			ecX2 = ecX;
			ecY2 = ecY;
			th2 = th;
			ph2 = ph;
		}

		if (mouseBtnPressed == "Right")
		{
			lightTh = (lightTh2 + (mouseX - xcoord));
			lightPh = (lightPh2 + (mouseX - xcoord));
		}
	}

	//structure rotation
	else if (Shift=="rotation")
	{
		if (mouseBtnPressed == "Left")
		{
			xcoord = mouseX;
			ycoord = mouseY;
			lightTh2 = lightTh;
			lightPh2 = lightPh;
			th2 = th;
			ph2 = ph;
			cubesy = cubes[10000].tsr.r.y;
			ecX2 = ecX;
			ecY2 = ecY;
		}

		if (mouseBtnPressed == "Right")
		{
			th = (th2 + (mouseX - xcoord));
			ph = (ph2 + (mouseY - ycoord));
			
		//	cubes[10000].tsr.r.x += (mouseY - ycoord);
			cubes[10000].tsr.r.y =cubesy- (mouseX - xcoord);
		}
	}

	//structure movement
	else if (Shift=="movement")
	{
		if (mouseBtnPressed == "Left")
		{
			xcoord = mouseX;
			ycoord = mouseY;
			lightTh2 = lightTh;
			lightPh2 = lightPh;
			ecX2 = ecX;
			ecY2 = ecY;
			th2 = th;
			ph2 = ph;
		}

		if (mouseBtnPressed == "Right")
		{
			ecX = ecX2 + (-mouseX + xcoord)/10;
			ecY = ecY2 + (mouseY - ycoord)/10;
		}
	}

	th %= 360;
	ph %= 360;
	int lul1 = 0;
	lul1 = cubes[10000].tsr.r.y;
	lul1 %= 360;
	cubes[10000].tsr.r.y = lul1;
	redisplayAll();
}

//zoom
void mouseWheel(int scroll, int dir, int x, int y)
{
	dim -= 5*(double)dir;
	redisplayAll();
}



//handle mouse presses
void windowMouse(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON) mouseBtnPressed = "Left";
	else if (btn == GLUT_RIGHT_BUTTON) mouseBtnPressed = "Right";

	if (state == GLUT_UP)
	{
		mouseState = "up";
	}

	if (state == GLUT_DOWN)
	{
		mouseState = "down";
	}

	redisplayAll();
}


