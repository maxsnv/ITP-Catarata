#include "../inc/imagem.h"
#define rad(A)  (M_PI*((double)(A))/180.0) 
unsigned int **HTransform(Imagem *img) 
{
 /* formulas: r = x.cos(theta)+y.sin(theta);
  * x = r - y.sin(thetha)/cos(theta)
  * y = r - x.cos(theta)/sin(theta)
  * */
 int  w = img->width, h = img->height;
 double  hough_h = sqrt(w*w + h*h)/2.0;
 double r;
 int  img_d = hough_h *2.0; // de -r para +r; diagonal da imagem
 int  i,j,t,th = 360; //max theta
 unsigned int **accu;
 accu = malloc(img_d*sizeof(unsigned int*));
 for (i = 0; i < img_d; ++i) 
 {
 	accu[i] = malloc(th*sizeof(unsigned int) );  
 }
 
 for (r = 0; r< img_d;r++) 
 {
  for (t = 0;t  < 360;t ++) 
  {
  	accu[r,t] = 0; 
  }	
 }
 int mid_x = w/2,mid_y = h/2; // pontos do centro da imagem

 for (i = 0; i < h; ++i) // pense no i e j como y e x 
 {
 	for (j = 0; j < w; ++j) 
 	{
	 if (img->p[i][j].r == 1) 
	 {
	  for (t = 0;t < th;t++) 
	  {
 	   r = (j*(cos(rad(t))+i*sin(rad(t))));
	   accu[r,t]++;
	  }
	 }
 	}
 }
 return accu;
} 
