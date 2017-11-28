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

void AccumCircle(Circle *Circulo,int a,int b, int r)
{
 Circulo->a = (int) a;
 Circulo->b = (int) b;
 Circulo->r = (int) r;
}

void Eye_fill(Eye *Olho,Circle *Circulo)  
{
  for (int i = 0; i <=360; ++i) 
  {
   Olho->x[i]  = Circulo->a + Circulo->r * cos(i * M_PI/180);
   Olho->y[i]  = Circulo->b + Circulo->r * sin(i * M_PI/180);  
  }
}
int *Limits(Eye *Olho)
{
 int *xy,maxx = 0,minx = 100000,maxy = 0,miny = 1000000;
 xy = calloc(4,sizeof(int));
 for (int i = 0; i <= 360; ++i) 
 {
  if(Olho->x[i] > maxx)
	  maxx = Olho->x[i];
  if(Olho->x[i] < minx)
	  minx = Olho->x[i];
  if(Olho->y[i] > maxy)
	  maxy = Olho->y[i];
  if(Olho->y[i] < miny)
	  miny = Olho->y[i];
 }
  xy[0] = minx;
  xy[1] = maxx;
  xy[2] = miny;
  xy[3] = maxy;
  return xy;
}

void StripImage(Imagem *img,int *xy)
{
 for (int i = 0; i < img->height; ++i) 
 {
 	for (int j = 0; j < img->width; ++j) 
 	{
 		if((j < xy[0] || j > xy[1])||(i< xy[2]|| i > xy[3] ))
		{
					img->p[i][j].r = 0;
					img->p[i][j].g = 0;
					img->p[i][j].b = 0;
		}
 	}
 }
}
void red_fill(Eye *Olho,Imagem *img)
{
  for (int i = 0; i <=360; ++i) 
  {
   if((Olho->y[i] >= 0 && Olho->y[i] < img->height) && (Olho->x[i] >= 0 && Olho->x[i] < img->width)) 
   {
   img->p[Olho->y[i]][Olho->x[i]].r = 255;   	
   img->p[Olho->y[i]][Olho->x[i]].g = 10;   	
   img->p[Olho->y[i]][Olho->x[i]].b = 10;   	
   }
  }
}
double *preCalcSin()
{
	double *Sin = malloc(361 * sizeof(double));
	for (int i = 0; i <= 360; ++i) 
	{
	 Sin[i] = sin(i*M_PI/180) ; 
	}
	return(Sin); 
}
double *preCalcCos()
{
	double *Cos = malloc(361 * sizeof(double));
	for (int i = 0; i <= 360; ++i) 
	{
	 Cos[i] = cos(i*M_PI/180) ; 
	}
	return(Cos); 
}

Circle **AllocateCircles(int amount)
{
 Circle **Circulo = calloc(amount,sizeof(Circle*));
 for (int i = 0; i < amount; ++i) 
 {
   Circulo[i] = calloc(1,sizeof(Circle));	
 }
 return Circulo;
}

Eye **AllocateEye(int amount)
{
 Eye **olho = calloc(amount,sizeof(Eye*));
 for (int i = 0; i < amount; ++i) 
 {
   olho[i] = calloc(1,sizeof(Eye));	
 }
 return olho;
}
void fimg (Imagem *read)
{
    int i;
    for (i = 0; i < read->height; ++i)
    {
        free(read->p[i]);
    }
        free (read->p);
	free(read); 
}

// remove the filepath from the string
char *stripFilepath(char *filepath)
{
	// if the argument is the file itself, return it
	if (!strstr(filepath, "/")) {
		return filepath;
	}

	char *strippedFilepath = (char *) calloc(strlen(filepath), sizeof(char));

	// strip folder name from the filepath
	ushort m = strlen(filepath);
	ushort n = 0;
	while (filepath[m] != '/') {
		strippedFilepath[n] = filepath[m];
		--m;
		++n;
	}
	strippedFilepath[n] = '\0';

	// here we have to invert the string because it is reversed (Catarata.ppm is mpp.atarataC)
	for (int i = 0, j = n - 1; i < j; ++i, --j) {
		char aux = strippedFilepath[i];
		strippedFilepath[i] = strippedFilepath[j];
		strippedFilepath[j] = aux;
	}

	return strippedFilepath;
}

// generate the output filepath
char *outFilepath(char *folder, char *filename, char *toCat, char *format)
{ 
	char *outFilepath;
	outFilepath = (char *) calloc(strlen(folder) + strlen(filename) + strlen(toCat) + strlen(format), sizeof(char));

	strcpy(outFilepath, folder);

	// strip image format from the filename
	uchar i = 0;
	uchar j = strlen(outFilepath);
	while (filename[i] != '.') {
		outFilepath[j] = filename[i];
		++i;
		++j;
	}

	strcat(outFilepath, toCat);
	// add the '.' for the format
	outFilepath[strlen(outFilepath)] = '.';
	strcat(outFilepath, format);

	return outFilepath;
}
