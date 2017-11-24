#include "imagem.h"
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

void fACCU (unsigned int ***accu,int h,int w)
{

  int i,j;
  for (i = 0; i < h; ++i) 
  {
   for (j = 0; j < w; ++j) 
   {
   	free(accu[i][j]); 
   }
   free(accu[i]); 
  }
  free(accu); 
} 
