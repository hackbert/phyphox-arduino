#include "phyphoxBleExperiment.h"

void PhyphoxBleExperiment::Graph::setUnitX(const char *ux){
	memset(&UNITX[0], 0, sizeof(UNITX));
	strcat(UNITX, ux);
}

void PhyphoxBleExperiment::Graph::setUnitY(const char *uy){
	memset(&UNITY[0], 0, sizeof(UNITY));
	strcat(UNITY, uy);
}

void PhyphoxBleExperiment::Graph::setLabelX(const char *lx){
	memset(&LABELX[0], 0, sizeof(LABELX));
	strcat(LABELX, lx);
}

void PhyphoxBleExperiment::Graph::setLabelY(const char *ly){
	memset(&LABELY[0], 0, sizeof(LABELY));
	strcat(LABELY, ly);
}

void PhyphoxBleExperiment::Graph::setChannel(int x, int y)
{
    INPUTX = x;
    INPUTY = y;
}

void PhyphoxBleExperiment::Graph::setStyle(const char *s){
	memset(&STYLE[0], 0, sizeof(STYLE));
	strcat(STYLE, s);
}

void PhyphoxBleExperiment::Graph::getBytes(char *buffArray)
{

	strcat(buffArray,"\t\t<graph label=\"");
	strcat(buffArray, LABEL);
	strcat(buffArray,"\" labelX=\"");
	strcat(buffArray,LABELX);
	strcat(buffArray,"\" labelY=\"");
	strcat(buffArray,LABELY);
	strcat(buffArray,"\" labelZ=\"\" unitX=\"");
	strcat(buffArray,UNITX);
	strcat(buffArray,"\" unitY=\"");
	strcat(buffArray,UNITY);
	strcat(buffArray,"\" style=\"");
	strcat(buffArray,STYLE);
	strcat(buffArray,"\">\n");

    char cINPUTX[5], cINPUTY[5];
	sprintf(cINPUTX, "CH%i", INPUTX);
	sprintf(cINPUTY, "CH%i", INPUTY);

	strcat(buffArray, "\t\t\t<input axis=\"x\">");
	strcat(buffArray, cINPUTX);
	strcat(buffArray, "</input>\n\t\t\t<input axis=\"y\">");
	strcat(buffArray, cINPUTY);
	strcat(buffArray, "</input>\n\t\t</graph>\n");

	
}

bool PhyphoxBleExperiment::Graph::usesChannel(int channel) {
    return INPUTX == channel || INPUTY == channel;
}
