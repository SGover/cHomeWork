matcalc: mat.o main.o parser.o
	gcc -ansi -pedantic -Wall -g main.o mat.o parser.o -o matcalc
main.o: main.c mat.h
	gcc -c -pedantic -ansi -Wall main.c 
parser.o:parser.c parser.h mat.h
	gcc -c -pedantic -ansi -Wall parser.c 
mat.o: mat.c mat.h
	gcc -c -pedantic -ansi -Wall mat.c 

