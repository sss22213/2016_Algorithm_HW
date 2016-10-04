#include <stdlib.h>
#include <stdio.h>
void swap(int *a,int *b)
{
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
}
void quick_sortf(int *sets,int left,int right)
{
	if(left>=right)return (void) 0;
	int pivot=sets[left];
	int pivot_pos=left;
	int org_right=right;
	while(left<right)
	{
		while(sets[left]<pivot)left++;
		while(sets[right]>=pivot)right--;
		(left<right)?swap(sets+left,sets+right):0;
	}
	quick_sortf(sets,pivot_pos,left-1);
	quick_sortf(sets,left+1,org_right);
}
void print_array(int *arry,int len)
{
        for(int i=0;i<len;i++)printf(" %d ",arry[i]);
        printf("\n");
}
int main(int argc,char *argv[])
{
    /*   int *sets=(int*)malloc((argc-1)*sizeof(int));
        if(sets==NULL)
        {
                perror("memory leak");
                exit(1);
        }*/
	int sets[argc-1];
        for(int i=0;i<argc-1;i++)sets[i]=atoi(argv[i+1]);
//      print_array(sets,argc-1);
        //sorting
        quick_sortf(sets,0,argc-1-1);
//      print_array(sets,argc-1);
        return 0;
}

