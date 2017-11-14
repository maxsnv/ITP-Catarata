#ifndef Imagem_h
#define Imagem_h


#ifndef libs_h
#define libs_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif
 //Define a struct das cores, com 3 inteiros unsigned
typedef struct{
	unsigned char r,g,b;
}Pixel;
//Define a struct para os pixels
typedef struct {
	Pixel **p;
	int width,height,max;
	char header[2];
}Imagem;

Imagem rimg(char * name); //Função de leitura
void Grey(Imagem *Foto); //Função para transformar em tons de cinza
Imagem *Gauss(Imagem *Foto); //Função para o filtro de gauss
void wimg(FILE  *file, Imagem *img);//Função de escrita 
void fimg (Imagem *read);
#endif
