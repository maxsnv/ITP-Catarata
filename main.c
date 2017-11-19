#include "imagem.h"

int main(int argc, char *argv[])
{
 int i,j;

 FILE *file;
 file = fopen(argv[2],"w");
 if (file == NULL)
	printf("fail");

  Imagem *img2,*img;
  Imagem *aux = rimg(argv[1]);
  Grey(aux);
  img2 = gauss_filter(aux,25);
  img = Sobel(img2);
   fimg (img2); 
  wpbm(file, img);
  printf("Começando a transformada\n"); 
  HTransform(img); 
   fimg (img);
   fimg(aux);
 fclose(file);
   
	return 0;
}
