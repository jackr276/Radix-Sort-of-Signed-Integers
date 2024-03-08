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
	//We assume the first thing entered is the number of integers to be sorted
	int numInts;
	scanf("%d", &numInts);

	//allocate an appropriate amount of memory for our integers
	unsigned int* array = (unsigned int*)malloc(numInts*sizeof(int));
	unsigned int* buffer = (unsigned int*)malloc(numInts*sizeof(int));
	
	int received;
	//Get everything that we need from standard input
	for(int i = 0; i < numInts; i++){
		scanf("%d", &received);
		//Save the number we got into our array
		array[i] = received;
	}

	printf("\n\n");
	//testing
	for(int i = 0; i < numInts; i++){
		printf("%d ", array[i]);
	}
	printf("\n\n");
	



	//free when done
	free(array);
	free(buffer);
}
