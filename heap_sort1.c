#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct _tree
{
	int val;
	struct _tree *parent;
	struct _tree *left;
	struct _tree *right;
}tree;
void Swap_tree(tree* node1,tree *node2)
{
	int temp;
	temp=node1->val;
	node1->val=node2->val;
	node2->val=temp;
}
tree* Create_tree(int *sets,int len)
{
	tree *new_tree=(tree*)malloc((len+1)*sizeof(tree));
	if(new_tree==NULL)
	{
		perror("memory leak");
		exit(1);
	}
	int temp=pow(2,(int)log2((double)len));
	//create binary tree
	for(int i=1;i<len+1;i++)new_tree[i].val=sets[i-1];
	for(int i=1;i<temp;i++)
	{
		new_tree[i].left=new_tree+(i*2);
		new_tree[i].right=new_tree+(i*2+1);
		new_tree[i].parent=new_tree+(i/2);
	}
	//
	for(int i=temp;i<len+1;i++)new_tree[i].parent=new_tree+(i/2);
	//create heap tree
	//find Max to first location
	tree *Max=new_tree+1;
	for(int i=1;i<len+1;i++)
        {
		Max=(Max->val>(new_tree+i)->val)?Max:new_tree+i;
        }
	Swap_tree(Max,new_tree+1);
	//
	Max=new_tree+2;
	for(int i=2;i<len+1;i++)
        {
		Max=(Max->val>(new_tree+i)->val)?Max:new_tree+i;
		if(Max->val > Max->parent->val)Swap_tree(Max,Max->parent);
        }
	return new_tree;
}
void heap_sort(tree* head,int* result,int len)
{
	tree *ptr_head=head+1;
	int sets[len+1]; 
	for(int i=0;i<len;i++)		
	{
		result[i]=(ptr_head+1)->val;
		//Swap_tree((ptr_head+len-i-1),ptr_head);
		//Tweak tree
		(ptr_head)->val=0;
		for(int j=0;j<len;j++)sets[j]=(ptr_head+j)->val;
		ptr_head=Create_tree(sets,len);
		//ptr_head=ptr_head+1;
	}
}
int main(int argc,char *argv[])
{
	int sets[argc-1];
	int result[argc-1];
	for(int i=1;i<argc;i++)
	{
		sets[i-1]=atoi(argv[i]);
	}
	tree *roots=Create_tree(sets,argc-1);
	heap_sort(roots,result,argc-1);
	return 0;
}
