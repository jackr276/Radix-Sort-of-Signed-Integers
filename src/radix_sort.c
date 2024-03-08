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

	//Call the radix_sort_unsigned function to perform the sorting
	radix_sort_unsigned(array, numInts);

	//print out the array
	for(int i = 0; i < numInts; i++){
		printf("%d\n", array[i]);
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
	//predeclare the swap function	
	void swap(unsigned int** arr1, unsigned int** arr2);
}


/**
 * A simple simply swaps arr1 and arr2
 */
void swap(unsigned int** arr1, unsigned int** arr2){
	unsigned int* temp;

	//store arr1 in temp, set arr1 to arr2, then set arr2 to temp(old arr1)
	temp = *arr1;
	//set the array 1 pointer to the array 2 pointer
	*arr1 = *arr2;
	*arr2 = temp;
}
