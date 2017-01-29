#include "screencasts.h"
using namespace std;
//globális változók inicializálása
void initializeGlobals(void)

{
	/* WINDOW */
	windowHeight = DEF_WINDOW_HEIGHT;
	windowWidth = DEF_WINDOW_WIDTH;

	/* TOGGLE */
	toggleAxes = DEF_AXES;
	toggleParams = DEF_PARAMS;

	/* PROJECTION */
	dim = DEF_DIM;
	th = DEF_TH;
	ph = DEF_PH;
	fov = DEF_FOV;
	asp = DEF_ASP;
	ecX = DEF_ECX;
	ecY = DEF_ECY;
	ecZ = DEF_ECZ;

	/* LIGHTING */
	toggleLight = DEF_LIGHT;
//	distance = DEF_DISTANCE;
	ambient = DEF_AMBIENT;
	diffuse = DEF_DIFFUSE;
	emission = DEF_EMISSION;
	specular = DEF_SPECULAR;
	shininess = DEF_SHININESS;
	lightY = DEF_L_Y;
	lightPh = DEF_L_PH;
	lightTh = DEF_L_TH;

	/* TEXTURES */
	currentTexture = TEX_DEFAULT;

	//ugyanazok mint screencasts.h-ban
	toggleAnimation = DEF_ANIMATE;
	mouseBtnPressed = "Press the left mouse button before pressing the right one when using the q,w,e keys!";
	mouseState = "";
	Shift = "rotation";
	jobbx = 0;
	mouseX = 0, mouseY = 0;
	xcoord = 0, ycoord = 0;
	th2 = 0, ph2 = 0;
	lightTh2 = 0, lightPh2 = 0;
	fely = 0, timed = 0;
	cubesy = 0;
	ecX2 = 0, ecY2 = 0;
	main_window = 0;
	szamlalo = 0;
	ter = 0;
	enter = "pressed";
	valto = "parameters";
	kimenetek_szama = 6;
	bemenetek_szama = 3;
	space = 0;
	speed = 0;

	

}

/*
* initializeObjs(void)
* ------
* Initializes all of our objects
*/
void initializeObjs(void)

{

	string sor;
	ifstream filebe;
	filebe.open("highscore.txt");
	while (getline(filebe, sor))
	{
		highscore = stoi(sor);
	}
	filebe.close();

	int hely=0;
	int szam = szamok[0] * 1296 + szamok[1] * 36 + szamok[2];
	cubes[10000] = { { { 0, 1, 0 },{ 1,1,1 },{ 90,0,0 } ,{ 1,1,1} } };
	platform[0] = { {{0,0,0},{1,1,1},{90,0,0}, {0,0,0},{36,0,0}} };

	//ha beírunk 3 koordinátát ez lefut és egy piros vagy zöld (térrel terhelt) kockát létrehozz az adott koordinátára
	
}


//textúrák inicializálása
void initializeTextures(void)
{
	/*
	TEX_DEFAULT 0
	TEX_BRICK 1
	TEX_CRATE 2
	TEX_ICE 3
	TEX_FIRE 4
	TEX_EARTH 5
	TEX_WOOD 6
	TEX_VENUS 7
	*/
	

	textures[0] = loadTexBMP("0.bmp");
	textures[1] = loadTexBMP("1.bmp");
	
}