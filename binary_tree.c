tree* Create_tree(int *sets,int len)
{
        tree *root=new_node();
        root->val=*sets;
        root->right=NULL;
        root->left=NULL;
        //create binary search tree
        for(int i=1;i<len;i++)
        {
                tree *ptr_root=root;
                while(ptr_root!=NULL)
                {
                        if(sets[i]>=ptr_root->val)
                        {
                                if(ptr_root->right!=NULL)ptr_root=ptr_root->right;
                                else break;
                        }
                        if(sets[i]<ptr_root->val)
                        {
                                if(ptr_root->left!=NULL)ptr_root=ptr_root->left;
                                else break;
                        }
                }
                tree *nod=new_node();
                nod->val=sets[i];
                if(sets[i]>=ptr_root->val)
                {
                        nod->val=sets[i];
                        ptr_root->right=nod;
                }
                else
                {
                        ptr_root->left=nod;
                }
                nod->right=NULL;
                nod->left=NULL;
        }
        return root;
}
 tree *ptr_max=\
                ((new_tree+i)->val > (new_tree+i)->parent->val)?\
                (((new_tree+i)->val > (new_tree+i)->parent->left->val)?(new_tree+i):(new_tree+i)->parent->left):\
                (((new_tree+i)->parent->val > (new_tree+i)->parent->left->val)?\
                (new_tree+i)->parent:(new_tree+i)->parent->left);
                Swap_tree(ptr_max,ptr_max->parent);

