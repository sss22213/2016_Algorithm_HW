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
void Raxid_Sort()
{


}
int main()
{
	
	return 0;
}
