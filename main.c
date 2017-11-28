#include "imagem.h"

int main(int argc, char *argv[])
{
 int i,j,th,decrementation;

 FILE *file;
 file = fopen(argv[2],"w");
 if (file == NULL)
	printf("fail"); 

  Imagem *img2,*img3,*img;
  Imagem *aux = rimg(argv[1]);
//  img = rpbm(argv[1]);
  Grey(aux);
  img2 = gauss_filter(aux,7);
  img3 = Sobel(img2);
   fimg (img2); 
  img = gauss_filter(img3,3);
 /* char *path = stripFilepath(argv[1]);
  char *bin_path = ("\0",path,"bin","pbm"); */
  printf("Choose otsu decrementation value: ");
  scanf(" %d",&decrementation);
  th = Otsu(img)-decrementation;
  binarization(img,th);
 // wpbm(file, img); 
  printf("Começando a transformada\n"); 
  Circle **Hough = HTransform(img); 
   fimg (img); 
   printf("\nIndo pra segunda transformada\n");
   Eye *Olho = calloc(1,sizeof *Olho);
   Eye_fill(Olho,Hough[0]);
   int *xy = Limits(Olho);
  /* Imagem *img4 = rimg("Catarata2.ppm");     //LINHAS PARA IMPLEMENTAÇÕES FUTURAS
   StripImage(img4,xy);
   img = gauss_filter(img4,1);
   Imagem *img6 = Sobel(img);
   img3 = gauss_filter(img6,3);
   th = Otsu(img3);
   binarization(img3,th-20);
   wpbm(file,img3);
   fclose(file); */
   //Circle **Stripped = HTransform(img4);
   //
//   Eye *Olho2 = calloc(1,sizeof *Olho2);
   printf("Filling eye\n"); 
   Eye_fill(Olho,Hough[0]);
//   Eye_fill(Olho2,Hough[1]);
   
   printf("Eye Filled\n"); 
   Imagem *img4 = rimg(argv[1]);
   printf("Reddening Eye\n"); 
   red_fill(Olho,img4);
//   red_fill(Olho2,img4);
   printf("Image Complete, proceeding to write\n"); 
   wimg(file,img4); 
   free(Olho);
   fimg(img4); 
   fclose(file); 
	return 0;
}
