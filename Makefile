wimg.o: wimg.c
	gcc -c wimg.c
gauss.o: gauss.c
	gcc -c gauss.c -o gauss.o
read.o:  rimg.c
	gcc -c rimg.c -o read.o
grey.o: grey.c
	gcc -c grey.c

main: read.o grey.o gauss.o wimg.o
	gcc main.c read.o grey.o gauss.o wimg.o -o proj
clean:
	rm proj read.o grey.o gauss.o
