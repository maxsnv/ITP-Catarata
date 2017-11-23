#include "imagem.h"
void wimg(FILE *file,Imagem *img)
{
    int i, j;
//Imprime no arquivo o cabeçalho: header, largura, altura e pxl max
    fprintf(file,"%s\n%i %i\n%i\n",img->header,img->width,img->height,img->max);
//Imprime no arquivo os pixels
    for (i = 0; i < img->height; ++i)
    {
        for (j = 0; j < img->width; ++j)
        {
            fprintf(file,"%d\n%d\n%d\n",img->p[i][j].r,img->p[i][j].g,img->p[i][j].b);
        }
    }
}
void wpbm(FILE *file, Imagem *img)
{
    int i, j;
//Imprime no arquivo o cabeçalho: header, largura, altura e pxl max
    fprintf(file,"%s\n%d %d\n","P1",img->width,img->height);
//Imprime no arquivo os pixels
    for (i = 0; i < img->height; ++i)
    {
        for (j = 0; j < img->width; ++j)
        {
            fprintf(file,"%i\n",img->p[i][j].r);
        }
    }
}
void binarization(Imagem *img,unsigned int th)
{
 int i,j;
 for (i=0;i < img->height;i++)
	{
	for (j=0; j< img->width; j++)
		{ 
            if(img->p[i][j].r < th  )
            {
            img->p[i][j].r = 1;  
            } 
            else if (img->p[i][j].r >= th  ) 
            {
            img->p[i][j].r = 0;  
            }
        }
    }       
}
ushort ***CreateAcumulator(int height,int width, int radius)
{
	ushort ***Accu = (ushort ***) calloc(height, sizeof(ushort **));
	for (int i = 0; i < height; ++i) {
		Accu[i] = (ushort **) calloc(width, sizeof(ushort *));
		for (ushort j = 0; j < width; j++){
			Accu[i][j] = (ushort *) calloc(radius, sizeof(ushort));
		}
	}
	return Accu;
}

void AccumCircle(Circle *Circulo,int a,int b, int r)
{
 Circulo->a = a;
 Circulo->b = b;
 Circulo->r = r;
}

void Eye_fill(Eye *Olho,Circle *Circulo)  
{
  for (int i = 0; i < 360; ++i) 
  {
   Olho->x[i]  = Circulo->a + Circulo->r * cos(i * M_PI/180);
   Olho->y[i]  = Circulo->b + Circulo->r * sin(i * M_PI/180);  
  }
}
void red_fill(Eye *Olho,Imagem *img)
{
  for (int i = 0; i < 360; ++i) 
  {
   img->p[Olho->y[i]][Olho->x[i]].r = 255;   	
   img->p[Olho->y[i]][Olho->x[i]].g = 10;   	
   img->p[Olho->y[i]][Olho->x[i]].b = 10;   	
  }
}
double *preCalcSin()
{
	double *Sin = malloc(360 * sizeof(double));
	for (int i = 0; i <= 360; ++i) 
	{
	 Sin[i] = sin(i*M_PI/180) ; 
	}
	return(Sin); 
}
double *preCalcCos()
{
	double *Cos = malloc(360 * sizeof(double));
	for (int i = 0; i <= 360; ++i) 
	{
	 Cos[i] = cos(i*M_PI/180) ; 
	}
	return(Cos); 
}
