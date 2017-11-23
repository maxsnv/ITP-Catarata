#include "imagem.h"
#define ARR(i,j,k) accu[i*w*accu_r+j*accu_r+k]  
Circle *HTransform(Imagem *img)
{
 int i,j,k,x,y,t,a,b;
 int w = img->width, h = img->height;
 int th = 360;
 int mvalue[3],max[3];
 int rmax = sqrt(img->height*img->height+img->width*img->width)/4.0;
 int rmin = 80, accu_r = rmax-rmin+1, rfor = 0;
 ushort ***accu = CreateAcumulator(img->height,img->width,accu_r);
// unsigned int *accu = malloc(w*h*accu_r); 
 mvalue[0] = 0;
 Circle *Circulo = malloc(sizeof *Circulo); 
 printf("%d %d",w,w/5); 
// memset(accu,0,h*w*accu_r); 
 for (i = 0; i < img->height; ++i) 
 {
  for (j = 0; j < img->width; ++j) 
  {
   for (k = 0; k < accu_r; ++k) 
   {
   	accu[i][j][k] = 0;
   }	
  }	
 }
 double *sin = preCalcSin();
 double *cos = preCalcCos();  
 printf("Acumulador Inicializado com sucesso\n");
 for (y = 50; y < img->height-160; ++y){ 
  printf("Valor de y =  %d\n  ",y);	
  for (x = img->width/5; x < w - (w/5) ; ++x){
//  	printf("Valor de x = %d\n",x);
//	printf("Testando valores inteiros do ponteiro img->p[%d][%d]: %d\n",y,x,img->p[y][x].r);
     if(img->p[y][x].r == 1)
      {
      for (rfor = rmin; rfor < rmax; rfor = rfor +5){
     	for (t = 0; t <= th; t = t+60){
     
   	  a = x - rfor * cos[t] ;
     	  b = y - rfor *sin[t] ;	
          
	   if((a >= 0 && a < img->height) && (b >= 0 && b < img->height))
    	    { 
  	      accu[b][a][rfor] += 1;
    //        ARR(b,a,rfor-rmin)+= 1; 
		if(mvalue[0] < accu[b][a][rfor-rmin])
		{
		 mvalue[0] = accu[b][a][rfor-rmin];
		 max[0] = a;
		 max[1] = b;
		 max[2] = rfor-rmin; 
		}
         
            }      
         }	
       }	 
      }
   }
  } 
 fACCU(accu,img->height,img->width);
// free(accu); 
 printf("%d\n",mvalue[0]);
 printf("%d %d %d\n",max[0],max[1],max[2]); 
 AccumCircle(Circulo,max[0],max[1],max[2]); 
 printf("Fim da transformada\n");
 //printf("%d",mvalue[0]);
 return Circulo; 
}
