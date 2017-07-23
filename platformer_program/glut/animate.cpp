using namespace std;

#include "screencasts.h"

/*
* moveCube()
* ------
* Rotates a cube if animations are on
*/
int moveCube(int i)
{
	
	cubes[i].tsr.r.y = fmod(cubes[i].tsr.r.y + 1.0, 360.0);
	
	return 0;
}

/*
* moveLight()
* ------
* Moves the light if it is on
*/
void moveLight(void)
{
	if (toggleLight) lightPh = (lightPh + 10) % 360;
}

double ugras(double t)
{
	cubes[10000].tsr.t.y = cubes[10000].tsr.t.y + t;

	return 0;
}
//TODO: make this better
void fougras()
{
	
	if (fel != "fel")
	{
		timed = 0;
		fely = cubes[10000].tsr.t.y;
	}
	if (fel == "fel")
	{
		
		if (cubes[10000].tsr.t.y >= fely)
		{
			ugras(-1 * timed + 0.7);

		}
		if ((-cubes[10000].tsr.t.y + fely < 0.1 && cubes[10000].tsr.t.y - fely < 0.1) && timed > 0.3) {
			cubes[10000].tsr.t.y = fely; 
			cout << ++space << endl;
		}

	}
	timed = timed + 0.01;
	if (fely == cubes[10000].tsr.t.y) {
		fel = ""; timed = 0;
		fely = cubes[10000].tsr.t.y;
	}
}
/*
* timer()
* ------
* Timer called periodically
*/
int jobbrabalra = 0;



void timer(int value)
{	//write here stuff for animation
	fougras();

	//velocity
	if (space <= 100) speed = 11.8;
	if (space <= 90) speed = 9.8;
	if (space <= 80) speed = 8;
	if (space <= 70) speed = 6.4;
	if (space <= 60) speed = 5;
	if (space <= 50) speed = 3.8;
	if (space <= 40) speed = 2.8;
	if (space <= 30) speed = 2;
	if (space <= 20) speed = 1.4;
	if (space <= 10) speed = 1;
	if (space == 100) cout << "YOU WON" << endl;
	//is there up-down movement
	int lefel = 0;
	//is there left-right movement
	bool lenyomva = false;
	
	//up
	if (GetAsyncKeyState(0x57) & 0x8000) { 
		lenyomva = true;
		double ok = 1;
		if (jobbrabalra) ok = 1 / sqrt(2);
		cubes[10000].tsr.t.z = cubes[10000].tsr.t.z- ok*speed*cos((double)cubes[10000].tsr.r.y/180*PI);
	cubes[10000].tsr.t.x = cubes[10000].tsr.t.x - ok*speed*sin((double)cubes[10000].tsr.r.y/180*PI); 
	ecZ =ecZ- ok*speed*cos((double)cubes[10000].tsr.r.y/180*PI);
	ecX = ecX - ok*speed*sin((double)cubes[10000].tsr.r.y/180*PI);
	lefel++;
	}
	//down
	if (GetAsyncKeyState(0x53) & 0x8000) {
		lenyomva = true;
		double ok = 1;
		if (jobbrabalra) ok = 1 / sqrt(2);
		cubes[10000].tsr.t.z = cubes[10000].tsr.t.z + ok*speed*cos((double)cubes[10000].tsr.r.y / 180 * PI);
		cubes[10000].tsr.t.x = cubes[10000].tsr.t.x + ok*speed*sin((double)cubes[10000].tsr.r.y / 180 * PI);
		ecZ = ecZ + ok*speed*cos((double)cubes[10000].tsr.r.y / 180 * PI);
		ecX = ecX + ok*speed*sin((double)cubes[10000].tsr.r.y / 180 * PI);
		lefel++;
	}
	jobbrabalra = 0;
	//left
	if (GetAsyncKeyState(0x41)&0x8000) {
		lenyomva = true;
		double ok = 1;
		if (lefel) ok = 1 / sqrt(2);
		cubes[10000].tsr.t.z = cubes[10000].tsr.t.z + ok*speed*sin((double)cubes[10000].tsr.r.y / 180 * PI);
		cubes[10000].tsr.t.x = cubes[10000].tsr.t.x - ok*speed*cos((double)cubes[10000].tsr.r.y / 180 * PI);
		ecZ = ecZ + ok*speed*sin((double)cubes[10000].tsr.r.y / 180 * PI);
		ecX = ecX - ok*speed*cos((double)cubes[10000].tsr.r.y / 180 * PI);
		jobbrabalra++;
	}
	//right
	if (GetAsyncKeyState(0x44) & 0x8000) {
		lenyomva = true;
		double ok = 1;
		if (lefel) ok = 1 / sqrt(2);
		cubes[10000].tsr.t.z = cubes[10000].tsr.t.z - ok*speed*sin((double)cubes[10000].tsr.r.y / 180 * PI);
		cubes[10000].tsr.t.x = cubes[10000].tsr.t.x + ok*speed*cos((double)cubes[10000].tsr.r.y / 180 * PI);
		ecZ = ecZ - ok*speed*sin((double)cubes[10000].tsr.r.y / 180 * PI);
		ecX = ecX + ok*speed*cos((double)cubes[10000].tsr.r.y / 180 * PI);
		jobbrabalra++;
	}

	if ((lefel == 2) || (jobbrabalra == 2 && lefel == 0))
	{
		if (space > highscore)
		{
			highscore = space;

			string sor;
			ofstream fileki;
			fileki.open("highscore.txt");
			fileki << highscore;
			fileki.close();

		}
		space = 0;
		cubes[10000].tsr.t.z = 0;
		cubes[10000].tsr.t.x = 0;
		ecX = 0;
		ecZ = 0;
	}

	if (!lenyomva) {
		if (space > highscore)
		{
			highscore = space;
			
			string sor;
			ofstream fileki;
			fileki.open("highscore.txt");
			fileki << highscore;
			fileki.close();

		}
		space = 0;
		cubes[10000].tsr.t.z = 0;
		cubes[10000].tsr.t.x = 0;
		ecX = 0;
		ecZ = 0;
	}

	//TODO: make bounds more exact
	if (cubes[10000].tsr.t.y < 1.1 && ((cubes[10000].tsr.t.z <= -18 || cubes[10000].tsr.t.z >= 18) || (cubes[10000].tsr.t.x <= -18 || cubes[10000].tsr.t.x >= 18))) {
		
		if (space > highscore)
		{
			highscore = space;

			string sor;
			ofstream fileki;
			fileki.open("highscore.txt");
			fileki << highscore;
			fileki.close();

		}
		space = 0;
		cubes[10000].tsr.t.z = 0;
		cubes[10000].tsr.t.x = 0;
		ecX = 0;
		ecZ = 0;
	}
	/*
	if (lefel &&jobbrabalra) {
		cubes[10000].tsr.t.z = cubes[10000].tsr.t.z / sqrt(2);
		cubes[10000].tsr.t.x = cubes[10000].tsr.t.x / sqrt(2);
		ecZ = ecZ/ sqrt(2);
		ecX = ecX / sqrt(2);
	}
	*/
	if (GetAsyncKeyState(0x20)&0x8000) fel = "fel";
	/*
	* glutTimerFunc(millisecs, timerCallback, value)
	*   millisecs = how long until you want the callback to be called
	*   timerCallback = the function to be called when time is up
	*   value = can be used for whatever. I'm using it toggle the animation
	*/
	glutTimerFunc(10, timer, toggleAnimation);

	redisplayAll();
}