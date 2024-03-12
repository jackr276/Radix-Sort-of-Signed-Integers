# Author: Jack Robbins
# A simple runner script for radix sort

#!/bin/bash

#Command line argument is number of ints to sort(always less than 100)
count=$1

gcc -Wall -Wextra ./radix_sort.c -o radix_sort

#Warn users about large file sizes 
if [[ $count -gt 249 ]]; then 
	echo "Warning: using ${count} integers will generate 3 files each of approximate size $(($count*(4)/1000))KB"
	read -p "Are you sure you want to proceed?[Y/N]: " ANSWER
	
	#Abort if user does not agree
	if [[ $ANSWER != "Y" ]] && [[ $ANSWER != "y" ]]; then 
		echo "Aborting"
		exit 0;
	fi
fi

# Delete all of the old files
rm integers
rm radix_sorted
rm standard_sorted
echo "================== input ======================"
echo ${count} | tee integers

#Generate count random integers, print them to output and to integers file
for (( i=0; i<${count}; i++ )); do
	echo $((RANDOM-16384))
done | tee -a integers 

echo "============= execution result ================"

cat integers | ./radix_sort | tee radix_sorted

#Display sorted output
tail -n +2  integers | sort -n > standard_sorted

#For testing purposes, show comparison
echo "====== differences from correct result ======="
diff radix_sorted standard_sorted

