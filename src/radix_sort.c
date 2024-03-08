/**
 * Author: Jack Robbins
 * Homework 04, only problem(radix sort of integers)
 */


#include <stdlib.h>
#include <stdio.h>

/**
 * Main function takes in nothing
 */
int main(void){
	//Predeclare the radix_sort_unsigned function
	void radix_sort_unsigned(unsigned int* arr, int numInts);

	//We assume the first thing entered is the number of integers to be sorted
	int numInts;
	scanf("%d", &numInts);

	//allocate an appropriate amount of memory for our integers
	unsigned int* array = (unsigned int*)malloc(numInts * sizeof(int));
	
	int received;
	//Get everything that we need from standard input
	for(int i = 0; i < numInts; i++){
		scanf("%d", &received);
		//Save the number we got into our array
		array[i] = received;
	}

	//free when done
	free(array);
	return 0;
}

/**
 * Performs a radix sort, treating everything as unsigned
 * Using hexadecimal radix sort -- 16 buckets, 4 bits chunks each time
 */
void radix_sort_unsigned(unsigned int* arr, int numInts){
	//Declare the buffer array
	unsigned int* buffer = (unsigned int*)malloc(numInts * sizeof(int));
	
	//go through each 4 bit chunks, 32/4 = 8, so 8 iterations need
	for(int i = 0; i < 8; i++){
		//Go through each integer in the array
	}



	
	//free when done
	free(buffer);
}
