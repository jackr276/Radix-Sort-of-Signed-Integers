# Jack Robbins
# A simple runner script for radix sort
#!/bin/bash

#Command line argument is number of ints to sort(always less than 100)
count=$1

#Program only can do 100 at a timae //TODO FIXME once submitted
if [[ $count -gt 100 ]]; then 
	echo "Too many arguments for this program"
	exit 0;
fi

# Delete all of the old files
rm integers
rm radix_sorted
rm standard_sorted
echo "================== input ======================"
echo ${count} | tee input

#Generate count random integers, print them to output and to integers file
for (( i=0; i < $count; i++ )); do
	echo $((RANDOM-16384))
done | tee -a input

echo "============= execution result ================"

cat input | ./radix_sort | tee radix_sorted

#Display sorted output
tail -n +2 input | sort -n > standard_sorted

#For testing purposes, show comparison
echo "====== differences from correct result ======="
diff radix_sorted standard_sorted

