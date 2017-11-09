#include "imagem.h"

Imagem rimg(char * name)
{
 int i = 0, j = 0;
 Imagem read;
 char dump[100];

 FILE *file;
 file = fopen(name, "r");
 if (file == NULL)
  printf("Falha ao abrir arquivo");
 else
 {
  fscanf(file,"%s",read.header);
  if(strcmp(read.header, "P3"))
	  printf("Header incorreto");
  else
  {
  // PASSANDO DIRETO DO COMENTARIO NO ARQUIVO
  fgets(dump,sizeof dump-1,file);
  fgets(dump,sizeof dump-1,file);
  //
  fscanf(file, "%d %d %d\n", &read.width, &read.height, &read.max);
  read.p = malloc(read.height * sizeof (Pixel*));
   for (i = 0; i < read.height; ++i)
   {
    read.p[i] = malloc(read.width * sizeof (Pixel));
   }

   for (i = 0; i < read.height; ++i)
   {
     for (j = 0; j < read.width; ++j)
     {
       fscanf(file, "%d%d%d",&(read.p[i][j]).r, &(read.p[i][j]).g,&(read.p[i][j]).b);
     }
   }
  }
  fclose(file);
 }
 return read;
}
