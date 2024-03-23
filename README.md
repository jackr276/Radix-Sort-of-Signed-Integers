# Radix Sort of Signed Integers
Author: [Jack Robbins](https://www.github.com/jackr276)

This project contains a C program that uses a hexadecimal radix sort to sort signed integers taken in from standard input. A simple runner script is also provided for user convenience and ease of testing.
## What is Radix Sort?
### Background
Most generic sorting algorithms like insertion sort, shell sort, quicksort, etc., work by comparing two values in an array and swapping them accordingly. Some methods of doing this are more efficient than others. Algorithms like Bubble Sort, the oldest and most basic algorithm, have a runtime of $`O(n^2)`$, and the most efficient known generic sorting algorithm, QuickSort, has an average runtime complexity of $`O(nlogn)`$. However, there is currently no known generic sorting algorithm that has a runtime complexity of $`O(n)`$, or linear runtime. 

This is because, for an algorithm to be generic, at some point the algorithm must compare two items and swap them. An interesting question then arises if we remove the requirement that the algorithm must be generic. When this requirement is dropped, it turns out that there are more efficient ways of sorting **some** kinds of data, specifically primitive kinds of data, whose binary represenation in memory we can manipulate. This is where Radix sort comes in.

### How does Radix Sort work?
Before answering this question it is important to recall how data is organized in memory. At its most fundamental level, all data are 1's and 0's. Both signed and unsigned integers are 4 Bytes, or 4*8 bits, of contiguous 1's and 0's in memory. With this we know that for each bit, there are only 2 possible values, 1 or 0, of which 1 is the largest and 0 is the smallest. We can leverage this fact to arrange data into "buckets", based on their values at a certain bit, Here is a simplified example, sorting 4 nibbles(half bytes):



![Untitled Diagram drawio](https://github.com/jackr276/Radix-Sort-of-Signed-Integers/assets/113046361/aac1c146-3f7d-46b4-8ca9-b175922a3fc9)


## Using the runner script
The runner script [run.sh](https://github.com/jackr276/Radix-Sort-of-Signed-Integers/blob/main/src/run.sh) provides a convenient way to run the **radix_sort.c** program. The script takes in a positive integer value and generates the appropriate number of integers, saving them into a file named `integers`. It will then pass the
values in this file into **radix_sort.c** and into the standard `sort` command in Bash. The results of both of these procedures are stored in individual files, and compared using the `diff` command to demonstrate the correct functionality of **radix_sort.c**. An example of how to use this script is given below.

>[!NOTE]
>Be sure to grant executable permissions to `run.sh` by running `chmod +x run.sh`

```console
example@bash:~$ ./run.sh 500
Warning: using 500 integers will generate 3 files each of approximate size 2KB
Are you sure you want to proceed?[Y/N]: Y
# Program output follows this
```
