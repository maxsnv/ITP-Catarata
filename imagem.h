#ifndef Imagem_h
#define Imagem_h


#ifndef libs_h
#define libs_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif

typedef struct{
	unsigned int r,g,b;
}Pixel;

typedef struct {
	Pixel **p;
	int width,height,max;
	char header[2];
}Imagem;

Imagem rimg(char * name);
void Grey(Imagem *Foto);
Imagem *Gauss(Imagem *Foto);

void wimg(FILE  *file, Imagem *img);
#endif
