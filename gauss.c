#include "imagem.h"

Imagem *Gauss(Imagem *Foto)
{
 int filter[7][7] = {{1, 1, 2, 2, 2, 1, 1}, {1, 3, 4, 5, 4, 3, 1}, {2, 4, 7, 8, 7, 4, 2}, {2, 5, 8, 10, 8, 5, 2}, {2, 4, 7, 8, 7, 4, 2}, {1, 3, 4, 5, 4, 3, 1}, {1, 1, 2, 2, 2, 1, 1}};
 double aux = 0;
 float filtro;
 float fator = 170;
 int i, j, k, l;
 Imagem *Gauss;
 Gauss = malloc(sizeof *Gauss);
 Gauss->p = malloc(Foto->height * sizeof(Pixel*));
 for (i = 0; i < Foto->height; ++i)
 {
   Gauss->p[i] = malloc(Foto->width * sizeof(Pixel));
 }
 strcpy(Gauss->header,Foto->header);
 Gauss->height = Foto->height;
 Gauss->width = Foto->width;
 Gauss->max = Foto->max;

  for (i = 0; i < Foto->height; ++i)
 {
 	for (j = 0; j < Foto->width; ++j)
 	{
        filtro = 0;
 		for (k = 0; k <7; ++k)
 		{
 			for (l = 0; l < 7; ++l)
 			{
			if ( ((i-3+k) >= 0 && (j-3+l) >= 0) && (i+3 < Gauss->height && j+3 < Gauss->width) )
			   {
			                filtro += Foto->p[i-3+k][j-3+l].r * filter[k][l]/fator;
			   }

 			 }
 		}

		Gauss->p[i][j].r = filtro;
		Gauss->p[i][j].g = filtro;
		Gauss->p[i][j].b = filtro;

 	}
 }
 return Gauss;
}
