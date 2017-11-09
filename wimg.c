#include "imagem.h"
void wimg(FILE *file, Imagem *img)
{
    int i, j;

    fprintf(file,"%s\n%d %d\n%d\n",img->header,img->width,img->height,img->max);
    for (i = 0; i < img->height; ++i)
    {
        for (j = 0; j < img->width; ++j)
        {
            fprintf(file,"%d\n%d\n%d\n",img->p[i][j].r,img->p[i][j].g,img->p[i][j].b);
        }
    }
}
