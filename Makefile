fimg.o: free.c
	gcc -c -ggdb free.c -o fimg.o
wimg.o: wimg.c
	gcc -c -ggdb wimg.c
gauss.o: gauss.c
	gcc -c -ggdb gauss.c -o gauss.o
read.o:  rimg.c
	gcc -c -ggdb rimg.c -o read.o
grey.o: grey.c
	gcc -c -ggdb grey.c
sobel.o: sobel.c
	gcc -c -ggdb sobel.c -o sobel.o

main: read.o grey.o gauss.o sobel.o wimg.o fimg.o
	gcc main.c read.o grey.o gauss.o sobel.o wimg.o fimg.o -o proj -lm -ggdb
clean:
	rm proj read.o grey.o gauss.o sobel.o wimg.o fimg.o
