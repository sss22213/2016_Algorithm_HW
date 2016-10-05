#include <stdio.h>
#include <stdlib.h>
void merge_sort(int *sets,int *reg,int start,int end)
{
	if(start>=end)return (void)0;
	//divid two part
	int mid=(start+end)/2;
	int start1=start;
	int end1=mid;
	int start2=mid+1;
        int end2=end;
	merge_sort(sets,reg,start1,end1);
	merge_sort(sets,reg,start2,end2);
	//merge
	int start_temp=start;
	//middle 
	while(start1<=end1 && start2<=end2)
	{
		reg[start_temp++]=(*(sets+start1)<*(sets+start2))?sets[start1++]:sets[start2++];
	}
	//left
	while(start1<=end1)reg[start_temp++]=sets[start1++];
	//right
	while(start2<=end2)reg[start_temp++]=sets[start2++];
	//
	for(int i=start;i<=end;i++)sets[i]=reg[i];

}
void print(int *set,int len)
{
	for(int i=0;i<len;i++)printf("%d,",set[i]);
	printf("\n");
}
int main(int argc,char* argv[])
{
	int *reg=(int*)malloc((argc-1)*sizeof(int));
	int *arry=(int*)malloc((argc-1)*sizeof(int));
	for(int i=1;i<argc;i++)arry[i-1]=atoi(argv[i]);
//print(arry,argc-1);
	merge_sort(arry,reg,0,argc-2);
//	print(arry,argc-1);	
	free(reg);
	reg=NULL;
	free(arry);
        arry=NULL;	
	return 0;
}
