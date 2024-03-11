/**
 * Author: Jack Robbins
 * This C program implements a hexadecimal radix sort of signed integers, using a hexadecimal
 * radix sort algorithm. Memory allocation is done manually using malloc. The program has been
 * tested and is memory safe. Radix Sort results in an O(n) running time, making it the most efficient
 * known sorting algorithm when dealing with data that can be sorted using its binary format
 */

#include <stdlib.h>
#include <stdio.h>


/**
 * The main function simply makes calls to the radix_sort_unsigned and
 * to_signed_order functions, after it gets input from stdin
 */
int main(void){
	//Predeclare radix_sort_unsigned and to_signed_order functions
	void radix_sort_unsigned(unsigned int* arr, int size);
	void to_signed_order(unsigned int* arr, int size);

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

	//after doing this, array is sorted in unsigned order, meaning all of the negative
	//values will appear after the positive values
	to_signed_order(array, numInts);	

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
void radix_sort_unsigned(unsigned int* arr, int size){
	//Predeclare swap and resetArr functions
	void swap(unsigned int** arr1, unsigned int** arr2);
	void resetArr(int* arr, int size);
	
	//The buffer array will be saved to when we do our bucket sort
	unsigned int* buffer = (unsigned int*)malloc(size * sizeof(int));

	//We need this for in the loop. Each 4 bits will be a "chunk"
	unsigned int chunk;
	//This mask will be used for extracting chunks from the ints in arr
	unsigned int mask = 0xF;

	//declare counters and offset arrays
	//We need an array of counters every(this will be reset to 0 every iteration)
	int* counters = (int*)malloc(16*sizeof(int));
	//We also need an array of offsets, to represent bucket locations
	int* offsets = ( int*)malloc(16*sizeof(int));

	//Using hexadecimal radix sort, 4 bit chunks, 32/4=8, so 8 overall iterations needed
	for(int i = 0; i < 8; i++){
		//Every time we iterate, we want offsets and counters to be completely reset
		resetArr(counters, 16);
		resetArr(offsets, 16);

		//first go through arr, building up the counters array(number of elements per bucket 0-F)
		for(int j = 0; j < size; j++){
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
		for(int j = 0; j < size; j++){
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
 * A simple simply swaps arr1 and arr2. To do this, we need pointers
 * to the arrays, not just pointers that represent the array
 */
void swap(unsigned int** arr1, unsigned int** arr2){
	//Used to temporarily hold arr1
	unsigned int* temp;
	//store arr1 in temp, set arr1 to arr2, then set arr2 to temp(old arr1)
	temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}


/**
 * A simple helper function that resets every element in an array to 0
 */
void resetArr(int* arr, int size){
	for(int i = 0; i < size; i++){
		arr[i] = 0;
	}
}


/**
 * A helper function that takes a sorted array of unsigned integers, and puts them
 * in signed order. This function relies on the two's complement representation of
 * signed integers. We know that the MSB will be 1 for a negative number, meaning
 * that the negatives will appear AFTER the positives in unsigned order
 */
void to_signed_order(unsigned int* arr, int size){
	//First, we need to find the index of the first negative number
	int firstNeg = 0;
	for(; firstNeg < size; firstNeg++){
		//break out once we find the first negative
		if((int)arr[firstNeg] < 0){
			break;
		}
	}

	//Get the subset of all positive integers
	unsigned int* posSubset = (unsigned int*)malloc(firstNeg * sizeof(int));
	for(int i = 0; i < firstNeg; i++){
		posSubset[i] = arr[i];
	}
	
	//Get the subset of all negative numbers
	unsigned int* negSubset = (unsigned int*)malloc((size - firstNeg)*sizeof(int));
	for(int i = firstNeg; i < size; i++){
		//We'll need to adjust the index accordingly here
		negSubset[i - firstNeg] = arr[i];
	}
	
	//both subsets should already be fully in order, so we can now rearrange them
	for(int i = 0; i < size; i++){
		//The first size-firstNeg numbers will be negative
		if(i < size - firstNeg){
			arr[i] = negSubset[i];
		//the remaining numbers will be positive
		} else {
			//Positive subset index must be adjusted like such
			arr[i] = posSubset[i-(size - firstNeg)];
		}
	}

	//Once we're done with these free them
	free(negSubset);
	free(posSubset);
}
