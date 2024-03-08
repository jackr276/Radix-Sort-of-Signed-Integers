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
	//predeclare the swap and resetArr functions
	void swap(unsigned int** arr1, unsigned int** arr2);
	void resetArr(unsigned int* arr, int size);
	
	//The buffer array will be saved to when we do our bucket sort
	unsigned int* buffer = (unsigned int*)malloc(numInts * sizeof(int));

	//We need this for in the loop. Each 4 bits will be a "chunk"
	unsigned int chunk;
	//This mask will be used for extracting chunks from the ints in arr
	unsigned int mask = 0xF;

	//declare counters and offset arrays
	//We need an array of counters every time this for loop runs
	unsigned int* counters = (unsigned int*)malloc(16*sizeof(int));
	//We also need an array of offsets, to represent bucket locations
	unsigned int* offsets = (unsigned int*)malloc(16*sizeof(int));

	//Using hexadecimal radix sort, 4 bit chunks, 32/4=8, so 8 overall iterations needed
	for(int i = 0; i < 8; i++){
		//Every time we iterate, we want offsets and counters to be completely reset
		resetArr(counters, 16);
		resetArr(offsets, 16);

		//first go through arr, building up the counters array(number of elements per bucket 0-F)
		for(int j = 0; j < numInts; j++){
			//Grab the "ith" 4 bits
			chunk = (arr[j] >> (4*i)) & mask;
			//This chunk ranges from 0-15, so it can be used as an index
			counters[chunk]++;
		}

		//Next, build up the offsets array as a partial sum of counters
		for(int k = 1; k < 16; k++){
			//How far we already are plus how big the previous bucket is
			offsets[k] = offsets[k-1] + counters[k-1];
		}

		//Now, we can use offsets to appropriately place each element
		for(int j = 0; j < numInts; j++){
			//Grab the "ith" 4 bits
			chunk = (arr[j] >> (4*i)) & mask;
			//the position is the offset at this chunk
			//set the buffer at pos to be arr[j]
			buffer[offsets[chunk]] = arr[j];
			//Increment offsets at that chunk to move the start of this bucket up by 1
			offsets[chunk]++;

		}

		//We now swap array and buffer, as buffer is now the most properly sorted one
		swap(&arr, &buffer);
	}


	//we won't need these once everything is sorted
	free(buffer);
	free(counters);
	free(offsets);
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


//reset the entirety of the given array to be 0s
void resetArr(unsigned int* arr, int size){
	for(int i = 0; i < size; i++){
		arr[i] = 0;
	}
}
