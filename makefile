#-----------------------------------------------------------
# Name: Manirul Islam 
#-----------------------------------------------------------
# Date: 15th April, 2025
#-----------------------------------------------------------

apc : main.o apc.o addition.o subtraction.o multiplication.o division.o
	gcc -o apc main.c apc.c addition.c subtraction.c multiplication.c division.c

main.o : main.c
	gcc -c main.c

apc.o : apc.c
	gcc -c apc.c

addition.o : addition.c
	gcc -c addition.c

subtraction.o : subtraction.c
	gcc -c subtraction.c

multiplication.o : multiplication.c
	gcc -c multiplication.c

division.o : division.c
	gcc -c division.c

clean:
	rm -f *apc *.o

#Input:   ./apc 12653 + 12542  Output: 25195
#Input:   ./apc 12653 - 12542  Output: 111
#Input:   ./apc 12653 * 12542  Output: 158693926
#Input:   ./apc 12653 / 12542  Output: 1