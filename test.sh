#!/bin/bash
for (( i=1; i<="$1"; i=i+1 ))
do
	array1[$i]=${i}
done
#perf stat ./insertion_sort_sort ${array1[@]}
#perf stat ./bubble_sort ${array1[@]}
#perf stat ./merge_sort ${array1[@]}
#perf stat ./quick_sort ${array1[@]}
#perf stat ./quick_sort_non ${array1[@]}
#perf stat ./heap_sort ${array1[@]}
echo "insertion_sort"
time ./insertion_sort ${array1[@]}
echo "bubble_sort"
time ./bubble_sort ${array1[@]}
echo "merge_sort"
time ./merge_sort ${array1[@]}
echo "quick_sort"
time ./quick_sort ${array1[@]}
echo "quick_sort_non"
time ./quick_sort_non ${array1[@]}
echo "heap_sort"
time ./heap_sort ${array1[@]}
sleep 1
echo "/************************/"
for (( i="$1"; i>=0; i=i-1 ))
do
        array2[$1-$i]=${i}
done
#perf stat ./insertion_sort ${array2[@]}
#perf stat ./bubble_sort ${array2[@]}
#perf stat ./merge_sort ${array2[@]}
#perf stat ./quick_sort ${array2[@]}
#perf stat ./quick_sort_non ${array2[@]}
#perf stat ./heap_sort ${array2[@]}
echo "insertion_sort"
time ./insertion_sort ${array2[@]}
echo "bubble_sort"
time ./bubble_sort ${array2[@]}
echo "merge_sort"
time ./merge_sort ${array2[@]}
echo "quick_sort"
time ./quick_sort ${array2[@]}
echo "quick_sort_non"
time ./quick_sort_non ${array2[@]}
echo "heap_sort"
time ./heap_sort ${array2[@]}


