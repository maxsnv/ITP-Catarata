#include "imagem.h"

int main(int argc, char *argv[])
{
 int i,j,th,decrementation;

 FILE *file;
// file = fopen(argv[2],"w");
// if (file == NULL)
//	printf("fail");

  Imagem *img2,*img3,*img;
  Imagem *aux = rimg(argv[1]);
  Grey(aux);
  img2 = gauss_filter(aux,3);
  img3 = Sobel(img2);
   fimg (img2); 
  img = gauss_filter(img3,1);
  printf("Choose otsu decrementation value: ");
  scanf(" %d",&decrementation);
  th = Otsu(img)-decrementation;
  binarization(img,th);
 // wpbm(file, img);
  printf("Começando a transformada\n"); 
  Circle *Hough = HTransform(img); 
   fimg (img); 
 /* printf("Imprimindo gambiarra");

  file = fopen("Gambiarra.txt","w");
  
   fprintf(file,"%d %d %d",Hough->b,Hough->a,Hough->r); 
 
   fclose(file);
  */  
   
   Eye *Olho = malloc(sizeof *Olho);
   printf("Filling eye"); 
   Eye_fill(Olho,Hough);
   printf("Eye Filled"); 
   Imagem *img4 = rimg(argv[1]);
   printf("Reddening Eye"); 
   red_fill(Olho,img4);
   printf("Image Complete, proceeding to write"); 

   file = fopen(argv[2],"w");
  
   wimg(file,img4); 
   
   fclose(file); 
	return 0;
}
