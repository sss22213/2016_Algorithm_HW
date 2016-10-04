CC=gcc
all: insert_sort bubble_sort select_sort quick_sort merge_sort heap_sort quick_sort_non Radix_Sort clean
insert_sort: insertion_sort.c
	${CC} -c insertion_sort.c -g -Wall
	${CC} -o insertion_sort insertion_sort.o
bubble_sort: bubble_sort.c
	${CC} -c bubble_sort.c -g -Wall
	${CC} -o bubble_sort bubble_sort.o
select_sort: select_sort.c
	${CC} -c select_sort.c -g -Wall
	${CC} -o select_sort select_sort.o
quick_sort: quick_sort.c
	${CC} -c quick_sort.c -g -Wall
	${CC} -o quick_sort quick_sort.o
merge_sort: merge_sort.c
	${CC} -c merge_sort.c -g -Wall
	${CC} -o merge_sort merge_sort.o
heap_sort: heap_sort.c
	${CC} -c heap_sort.c -g -Wall
	${CC} -o heap_sort heap_sort.o -lm
quick_sort_non: quick_sort_non.c
	${CC} -c quick_sort_non.c -g -Wall
	${CC} -o quick_sort_non quick_sort_non.o
Radix_Sort: Radix_Sort.c
	${CC} -c Radix_Sort.c -g -Wall
	${CC} -o Radix_Sort Radix_Sort.o
clean:
	rm *.o
	
 
