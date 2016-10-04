#include <stdlib.h>
#include <stdio.h>
void swap(int *a,int *b)
{
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
}
void bubble_sortf(int *sets,int len)
{
        for(int i=0;i<len-1;i++)
        {
                for(int j=0;j<len-1-i;j++)
                {
                        if(sets[j]>sets[j+1])swap(sets+j,sets+j+1);
                }
        }

}
void print_array(int *arry,int len)
{
        for(int i=0;i<len;i++)printf(" %d ",arry[i]);
        printf("\n");
}
int main(int argc,char *argv[])
{
	int *sets=(int*)malloc((argc-1)*sizeof(int));
        if(sets==NULL)
        {
                perror("memory leak");
                exit(1);
        }
        for(int i=0;i<argc-1;i++)sets[i]=atoi(argv[i+1]);
      // print_array(sets,argc-1);
        //sorting
        bubble_sortf(sets,argc-1);
        //print_array(sets,argc-1);
	free(sets);
	return 0;
}
