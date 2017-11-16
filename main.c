#include "imagem.h"

int main(int argc, char *argv[])
{
 int i,j;

 FILE *file;
 file = fopen(argv[2],"w");
 if (file == NULL)
	printf("fail");

  Imagem Aux = rimg(argv[1]);
  Grey(&Aux);
  Imagem *img;
  img = Gauss(&Aux);
  img = Sobel(&Aux);
  wimg(file, img);
   fimg (img);

 fclose(file);

	return 0;
}
