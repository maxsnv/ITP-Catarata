#ifndef Imagem_h
#define Imagem_h


#ifndef libs_h
#define libs_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
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
	int histogram[256]; 
}Imagem;

Imagem *rimg(char * name); //Função de leitura
void Grey(Imagem *Foto); //Função para transformar em tons de cinza
Imagem *gauss_filter(Imagem *Foto,unsigned int repeats); //Função para o filtro de gauss
             // repeats definem a quantidade de vezes que o filtro será aplicado. iteraçoes = repeats+1
Imagem *Sobel (Imagem *Foto);
int Otsu(int data[]); // Func de threshold por histogram
void wimg(FILE  *file, Imagem *img);//Função de escrita
void wpbm(FILE *file,Imagem *img); // Escrita em pbm 
unsigned int **HTransform(Imagem *img); 
void fimg (Imagem *read);
#endif
