#include "../inc/imagem.h"

Imagem *Sobel (Imagem *Foto)
{
	int x, y, i, j,th;
	th = Otsu(Foto->histogram)-78; 
	double max = -DBL_MAX;
	Imagem *Sobel;
	Sobel = malloc (sizeof *Sobel);
	Sobel->p = malloc (Foto->height*sizeof (Pixel*));
	for (i=0; i<Foto->height;i++)
	{
		Sobel->p[i] = malloc(Foto->width * sizeof (Pixel));
	}

        for (int i = 0; i < 256; ++i) 
        {
        	Sobel->histogram[i] = 0; 
        }
	strcpy (Sobel->header, Foto->header);
	Sobel->height = Foto->height;
	Sobel->width = Foto->width;
	Sobel->max = Foto->max;

	int kernelx [3][3] = {{-1,0,1 },
		      			{-2,0,2},
		      			{-1,0,1}};
	int kernely [3][3] = {{-1,-2,-1},
						{0,0,0},
						{1,2,1}};
    int pv, ph;
  


	for (i=1;i < Foto->height-1;i++)
	{
		for (j=1; j< Foto->width-1; j++)
		{ 
			pv = 0;
			ph = 0;
			for (x=0;x<3;x++)
			{
				for (y=0;y<3;y++)
				{
						pv += kernelx[x][y] * Foto->p[i-1+x][j-1+y].r;
					    ph += kernely[x][y] * Foto->p[i-1+x][j-1+y].r;
				}
			}

                    if (sqrt(pv*pv+ph*ph)>255)
                    {
                        Sobel->p[i][j].r =	1;

                    }
                    else
                    {
                    Sobel->p[i][j].r = (unsigned char)(sqrt(pv*pv+ph*ph));
            		Sobel->p[i][j].g = (unsigned char)(sqrt(pv*pv+ph*ph));
            		Sobel->p[i][j].b = (unsigned char)(sqrt(pv*pv+ph*ph));
		    
		    if(Sobel->p[i][j].r < th  )
		     {
  			Sobel->p[i][j].r = 1;  
		     } 
		    else if (Sobel->p[i][j].r >= th  ) {
		    	Sobel->p[i][j].r = 0;  
		     }
                    }
		}
	}
	return Sobel;
}


 int Otsu(int data[]) {
        // Otsu's threshold algorithm
        // C++ code by Jordan Bevik <Jordan.Bevic@qtiworld.com>
        // ported to ImageJ plugin by G.Landini
        int k,kStar;  // k = the current threshold; kStar = optimal threshold
        double N1, N;    // N1 = # points with intensity <=k; N = total number of points
        double BCV, BCVmax; // The current Between Class Variance and maximum BCV
        double num, denom;  // temporary bookeeping
        double Sk;  // The total intensity for all histogram points <=k
        double S, L=256; // The total intensity of the image

        // Initialize values:
        S = N = 0;
        for (k=0; k<L; k++){
            S += (double)k * data[k];   // Total histogram intensity
            N += data[k];       // Total number of data points
        }

        Sk = 0;
        N1 = data[0]; // The entry for zero intensity
        BCV = 0;
        BCVmax=0;
        kStar = 0;

        // Look at each possible threshold value,
        // calculate the between-class variance, and decide if it's a max
        for (k=1; k<L-1; k++) { // No need to check endpoints k = 0 or k = L-1
            Sk += (double)k * data[k];
            N1 += data[k];

            // The float casting here is to avoid compiler warning about loss of precision and
            // will prevent overflow in the case of large saturated images
            denom = (double)( N1) * (N - N1); // Maximum value of denom is (N^2)/4 =  approx. 3E10

            if (denom != 0 ){
                // Float here is to avoid loss of precision when dividing
                num = ( (double)N1 / N ) * S - Sk;  // Maximum value of num =  255*N = approx 8E7
                BCV = (num * num) / denom;
            }
            else
                BCV = 0;

            if (BCV >= BCVmax){ // Assign the best threshold found so far
                BCVmax = BCV;
                kStar = k;
            }
        }
        // kStar += 1;  // Use QTI convention that intensity -> 1 if intensity >= k
        // (the algorithm was developed for I-> 1 if I <= k.)
	printf("Sobel Threshold = %d\n",kStar); 
        return kStar;
    }
