#include <stdio.h>
#include <stdlib.h>
typedef struct _Bucket
{
	int top;
	int *level;
}Bucket;
void push(Bucket* B_num,int val)
{
	B_num->top++;
	*(B_num->level+B_num->top)=val;

}
int pull(Bucket* B_num)
{
	int reg=*B_num->level;
	B_num->top--;
	return reg;
}
void Raxid_Sort(int *set,int len)
{
	Bucket cc[len];
	//init Bucket
	for(int i=0;i<len;i++)
	{
		cc[i].top=0;
		cc[i].level=(int*)malloc(sizeof(int));
	}
	//find Raxid
	int Raxid=0;
	for(int i=1;Raxid/(10*i)!=0;i++);
	//first loop
	for(int i=0;i<len;i++)
	{
		push(&cc[*(set+i)%10],set[i]);
	}
	//
	for(int i=0;i<Raxid-1;i++)
	{
		for(int j=0;j<len;j++)
		{
			for(int k=0;k<(cc+j)->top;k++)
			{
				int reg=pull(cc+j);
				push(&cc[*(set+i)/Raxid%10],reg);
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		set[i];
	}
}
int main()
{
	
	return 0;
}
