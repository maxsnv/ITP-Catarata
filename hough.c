#include "imagem.h"
#define ARR(i,j,k) accu[i*w*accu_r+j*accu_r+k]  
Circle **HTransform(Imagem *img)
{ 
 int i,j,k,x,y,t,a,b,count = 0;
 int w = img->width, h = img->height;
 int th = 360;
 int mvalue[10],max[10][3];
 	mvalue[0] = 0;
	max[0][0] = 0;
 
 int rmax = sqrt(img->height*img->height+img->width*img->width)/4.0;
 int rmin = 80, accu_r = rmax-rmin+1, rfor = 0;
//unsigned int ***accu = CreateAcumulator(img->height,img->width,accu_r);
 unsigned int *accu = calloc(w*h*accu_r,sizeof(unsigned int)); 
 mvalue[0] = 0;
 Circle *Circulo = calloc(1,sizeof *Circulo);
// Circle *Circulo2 = calloc(1,sizeof *Circulo);
 Circle **Vec = calloc(2,sizeof(Circle*));
 printf("%d %d",w,w/5); 
 memset(accu,0,h*w*accu_r); 
/* for (i = 0; i < img->height; ++i) 
 {
  for (j = 0; j < img->width; ++j) 
  {
   for (k = 0; k < accu_r; ++k) 
   {
   	accu[i][j][k] = 0;
   }	
  }	
 } */
 double *sin = preCalcSin();
 double *cos = preCalcCos();  
 printf("Acumulador Inicializado com sucesso\n");
 for (y = 50; y < img->height-160; ++y){ 
  printf("Valor de y =  %d\n  ",y);	
  for (x = img->width/5; x < w - (w/5) ; ++x){
//  	printf("Valor de x = %d\n",x);
//	printf("Testando valores inteiros do ponteiro img->p[%d][%d]: %d\n",y,x,img->p[y][x].r);
     if(img->p[y][x].r == 0)
      {
      for (rfor = rmin; rfor <= rmax; rfor = rfor +10){
     	for (t = 0; t <= th; t = t+10){
     
   	  a = x - rfor * cos[t] ;
     	  b = y - rfor *sin[t] ;	
          
	   if((a >= 0 && a < img->height) && (b >= 0 && b < img->height))
    	    { 
  	     // accu[b][a][rfor-rmin] += 1;
	     // if(accu [b][a][rfor] == 65532   ) 
	//	      printf("Overflow Incoming\n"); 
               ARR(b,a,rfor-rmin)+= 1; 
		if(mvalue[0] < ARR(b,a,rfor-rmin)/* accu[b][a][rfor-rmin]*/)
		{
		 if(count != 10)
		  count++;		 
		    
		  	if(max[0][2] != rfor)
		 	{
			  for(i = count; i > 0; ++i){

		  	  mvalue[i] = mvalue[i-1];
		  	  max[i][0] = max[i-1][0];
		  	  max[i][1] = max[i-1][1];
		  	  max[i][2] = max[i-1][2];
			  }	  
		 	}
		 	 
		 mvalue[0] = ARR(b,a,rfor-rmin) /*accu[b][a][rfor-rmin]*/;
		 max[0][0] = a;
		 max[0][1] = b;
		 max[0][2] = rfor;
		  
		}
         
            }      
         }	
       }	 
      }
   }
 }
// fACCU(accu,img->height,img->width);
 printf("\n%d\n",mvalue[0]);
 printf("   %d\n",mvalue[1]);
 printf("%d %d %d\n",max[0][0],max[0][1],max[0][2]); 
 printf("%d %d %d\n",max[1][0],max[1][1],max[1][2]); 
 AccumCircle(Circulo,max[0][0],max[0][1],max[0][2]);
// AccumCircle(Circulo2,max[1][0],max[1][1],max[1][2]);
 Vec[0] = Circulo;
// Vec[1] = Circulo2;
 free(accu); 
 printf("Fim da transformada\n");
 return Vec; 
}
