#include "MCoord.h"

MCoord::MCoord(double xx, double yy) {
	pcoord[0] = xx;
	pcoord[1] = yy;
}

MCoord::~MCoord() {
	if (pcoord != NULL) {
		delete[] pcoord;
		pcoord = NULL;
	}
}