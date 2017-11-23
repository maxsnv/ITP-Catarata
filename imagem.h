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

#define ushort unsigned short

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

typedef struct{
  int a,b,r;
}Circle;
typedef struct{
  ushort x[360] ;
  ushort y[360] ;
}Eye;

void AccumCircle(Circle *Circulo,int a,int b, int r);

void red_fill(Eye *Olho,Imagem *img);

void Eye_fill(Eye *Olho,Circle *Circulo);

double *preCalcCos();

double *preCalcSin(); 

Imagem *rimg(char * name); //Função de leitura

void Grey(Imagem *Foto); //Função para transformar em tons de cinza

Imagem *gauss_filter(Imagem *Foto,unsigned int repeats); //Função para o filtro de gauss
             // repeats definem a quantidade de vezes que o filtro será aplicado. iteraçoes = repeats+1

Imagem *Sobel (Imagem *Foto);

int Otsu(Imagem *img); // Func de threshold por histogram

void binarization(Imagem *img,unsigned int th); // Conversão para pbm antes da wpbm

void wimg(FILE  *file, Imagem *img);//Função de escrita

void wpbm(FILE *file,Imagem *img); // Escrita em pbm 

Circle *HTransform(Imagem *img); 

int ***CreateAcumulator(int height,int width, int radius);

void fimg (Imagem *read);

void fACCU (int ***accu,int h,int w); // free acumulator
#endif
