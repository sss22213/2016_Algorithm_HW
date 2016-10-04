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
        //int pivot=sets[left];
	int *ptr_pivot=sets+left;
	int temp_left=left;
        //int pivot_pos=left;
        int temp_right=right;
	for(int i=0;i<=(right-left)/2;i++)
	{
		while(temp_left<temp_right)
		{
			while(sets[temp_left]<*ptr_pivot)temp_left++;
                	while(sets[temp_right]>=*ptr_pivot)temp_right--;
                	(temp_left<temp_right)?swap(sets+temp_left,sets+temp_right):0;
                	//if(temp_left>=temp_right)break;
		}
		temp_left=left;
		temp_right=right;
		ptr_pivot++;
	}
}
void print_array(int *arry,int len)
{
        for(int i=0;i<len;i++)printf(" %d ",arry[i]);
        printf("\n");
}
int main(int argc,char *argv[])
{
   	//    int *sets=(int*)malloc((argc-1)*sizeof(int));
        /*if(sets==NULL)
        {
                perror("memory leak");
                exit(1);
        }*/
        int sets[argc-1];
	for(int i=0;i<argc-1;i++)sets[i]=atoi(argv[i+1]);
       	//print_array(sets,argc-1);
        //sorting
        quick_sortf(sets,0,argc-2);
 //      print_array(sets,argc-1);
	return 0;
}
