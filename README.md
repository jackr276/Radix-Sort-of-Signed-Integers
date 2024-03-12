# Radix Sort of Unsigned Integers
Author: [Jack Robbins](https://www.github.com/jackr276)

This project contains a C program that uses a hexadecimal radix sort to sort signed integers taken in from standard input. A simple runner script is also provided for user convenience and ease of testing.

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
