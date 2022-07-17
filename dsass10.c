//Q.)Implement the following function in context to a binary search tree
//a.) insertion of element
//b.)deletion of element
//c.)updation of element
//d.) Calculate height of tree


# include <stdio.h>
#include <stdlib.h>

struct binarytree
{
 int data;
 struct binarytree *l;
 struct binarytree *r;
};


struct binarytree* create(int data)
{
 struct binarytree *create;
 create=(struct binarytree* )malloc(sizeof(struct binarytree));
 create->data=data;
 create->l=NULL;
 create->r=NULL;
 return create;
}


struct binarytree* insert(struct binarytree *root, int data)
{
 if(root==NULL)//if the tree is empty
 {
 root=create(data);
 return root;
 }
 else if(data<=root->data)
 {
 root->l=insert(root->l,data);
 }
 else
 {
 root->r=insert(root->r,data);
 }
 return root;
}

//update
void update(struct binarytree *root, int olddata, int newdata)
{ 
 if(root==NULL)
 {
 printf("\nBST empty. Cannot update.");
 }
 else if(root->data==olddata)
 {
 root->data=newdata;
 printf("\nUpdated.");
 }
 else if(olddata<=root->data)
 update(root->l,olddata,newdata);
 else
 update(root->r,olddata,newdata);
}

//find min
struct binarytree* findmin(struct binarytree* root)
{
 while(root->l != NULL) root = root->l;
 return root;
}


struct binarytree* delete(struct binarytree *root, int data)
{
 if(root==NULL)
 {
 printf("\nBst empty. Cannot delete.");
 }
 else if(data<root->data)
 root->l=delete(root->l,data);
 else if(data>root->data)
 root->r=delete(root->r,data);
 else
 {
 if(root->l==NULL && root->r==NULL)
 free(root);
 else if(root->l==NULL)
 {
 struct binarytree *temp=root;
 root=root->r;
 free(temp);
 }
 else if(root->r==NULL)
 {
 struct binarytree *temp=root;
 root=root->l;
 free(temp);
 }
 else
 {
 struct binarytree *temp=findmin(root->r);
 root->data=temp->data;
 root->r=delete(root->r,temp->data);
 }
 }
 return root;
} 


#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
int height(struct binarytree *root)
{
 if(root==NULL)
 return -1;
 else
 return MAX(height(root->l), height(root->r))+1;
}


void Display(struct binarytree* root)
{
 if (root==NULL)
 return;
 printf("\n%d ",root->data);
 Display(root->l);
 Display(root->r);
 
}



int main()
{
 struct binarytree *root=NULL;

int i,k,n;
printf("Total no of node:-");
scanf("%d",&n);
printf("\nEnter the value you want to insert:-\n");
for(i=0;i<n;i++){
	scanf("%d",&k);
	root=insert(root,k);
	}
 printf("Binary Tree:\n");
 Display(root);
 printf("\nEnter the value you want to delete:-\n");
 scanf("%d",&k);
 root=delete(root,k);
 printf("Binary Tree after deletion of %d:",k);
 Display(root);
 printf("\nEnter the value you want to update:\n");
 scanf("%d",&n);
 scanf("%d",&k);
 update(root,n,k);
 printf("Binary Tree after updation of %d to %d:\n",n,k);
 Display(root);
 int ht=height(root);
 printf("\nheight of tree:%d",ht);
 return 0;
}
