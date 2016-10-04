#include <stdlib.h>
#include <stdio.h>
void Swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void max_heapify(int *sets,int start,int end)
{
	int dad=start;
	int son=dad*2+1;
	while(son<=end)
	{
		//
		if(son+1<=end && (*(sets+son)<*(sets+son+1)))son++;
		if(*(sets+dad)>*(sets+son))return ;
		else 
		{
			Swap(sets+dad,sets+son);	
			dad=son;
			son=dad*2+1;
		}
	}
}
void heap_sort(int *sets,int len)
{
	//Create heap tree
	for(int i=len/2-1;i>=0;i--)max_heapify(sets,i,len-1);
	//tweak 
	for(int i=len-1;i>0;i--)
	{
		Swap(sets,sets+i);
		max_heapify(sets,0,i-1);
	}
}
int main(int argc,char *argv[])
{
	int sets[argc-1];
	for(int i=1;i<argc;i++)
	{
		sets[i-1]=atoi(argv[i]);
	}
	heap_sort(sets,argc-1);
	return 0;
}
