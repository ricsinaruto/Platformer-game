#include "screencasts.h"

//error handling stuff
void errCheck(char* where)
{
	int err = glGetError();
	if (err) fprintf(stderr, "ERROR: %s [%s]\n", gluErrorString(err), where);
}