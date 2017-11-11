#include "imagem.h"
void fimg (Imagem *read)
{
    int i;
    for (i = 0; i < read->height; ++i)
    {
        free(read->p[i]);
    }
        free (read->p);
}
