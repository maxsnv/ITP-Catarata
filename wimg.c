#include "imagem.h"
void wimg(FILE *file, Imagem *img)
{
    int i, j;
//Imprime no arquivo o cabeçalho: header, largura, altura e pxl max
    fprintf(file,"%s\n%d %d\n%d\n",img->header,img->width,img->height,img->max);
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
            fprintf(file,"%d\n",img->p[i][j].r);
        }
    }
}
