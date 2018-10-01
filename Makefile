OBJDIR = ./obj
SRCDIR = ./src
INCDIR = ./inc
BINDIR = ./bin

all: main

hough.o: $(SRCDIR)/hough.c
	gcc -c $(SRCDIR)/hough.c -lm
fimg.o: $(SRCDIR)/free.c
	gcc -c -ggdb $(SRCDIR)/free.c -o fimg.o
wimg.o: $(SRCDIR)/wimg.c
	gcc -c -ggdb $(SRCDIR)/wimg.c
gauss.o: $(SRCDIR)/gauss.c
	gcc -c -ggdb $(SRCDIR)/gauss.c -o gauss.o
read.o: $(SRCDIR)/rimg.c
	gcc -c -ggdb $(SRCDIR)/rimg.c -o read.o
grey.o: $(SRCDIR)/grey.c
	gcc -c -ggdb $(SRCDIR)/grey.c
sobel.o: $(SRCDIR)/sobel.c
	gcc -c -ggdb $(SRCDIR)/sobel.c -o sobel.o

main: read.o grey.o gauss.o sobel.o wimg.o fimg.o hough.o
	gcc $(SRCDIR)/main.c read.o grey.o gauss.o sobel.o wimg.o fimg.o hough.o -o proj -lm -ggdb
clean:
	rm proj read.o grey.o gauss.o sobel.o wimg.o fimg.o hough.o
