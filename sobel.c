#include "imagem.h"

Imagem *Sobel (Imagem *Foto)
{
	int x, y, i, j;
	double max = -DBL_MAX;
	Imagem *Sobel;
	Sobel = malloc (sizeof *Sobel);
	Sobel->p = malloc (Foto->height*sizeof (Pixel*));

	for (i=0; i<Foto->height;i++)
	{
		Sobel->p[i] = malloc(Foto->width * sizeof (Pixel));
	}

	strcpy (Sobel->header, Foto->header);
	Sobel->height = Foto->height;
	Sobel->width = Foto->width;
	Sobel->max = Foto->max;

	int kernelx [3][3] = {{-1,0,1 },
		      			{-2,0,2},
		      			{-1,0,1}};
	int kernely [3][3] = {{-1,-2,-1},
						{0,0,0},
						{1,2,1}};
    int pv, ph;



	for (i=1;i < Foto->height-1;i++)
	{
		for (j=1; j< Foto->width-1; j++)
		{
			pv = 0;
			ph = 0;
			for (x=0;x<3;x++)
			{
				for (y=0;y<3;y++)
				{
						pv += kernelx[x][y] * Foto->p[i-1+x][j-1+y].r;
					    ph += kernely[x][y] * Foto->p[i-1+x][j-1+y].r;
				}
			}

                    if (sqrt(pv*pv+ph*ph)>255)
                    {
                        Sobel->p[i][j].r =	255;
                        Sobel->p[i][j].g =	255;
                        Sobel->p[i][j].b =	255;

                    }
                    else
                    {
                    Sobel->p[i][j].r = (unsigned char)(sqrt(pv*pv+ph*ph));
            		Sobel->p[i][j].g = (unsigned char)(sqrt(pv*pv+ph*ph));
            		Sobel->p[i][j].b = (unsigned char)(sqrt(pv*pv+ph*ph));
                    }
		}
	}

	return Sobel;
}
