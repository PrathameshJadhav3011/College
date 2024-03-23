#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*left;
	struct node*right;
	
};
struct node*creat_node(int data)
{
	struct node*new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;
	return new_node;
}
struct node*insert(struct node*node,int data)
{
	if(node==NULL)
	{
		return creat_node(data);
	}
	else
	{
		if(data<=node->data)
		{
			node->left=insert(node->left,data);
		}
		else
		{
			node->right=insert(node->right,data);
		}
		return node;
	}
}
void inordertraversal(struct node*root)
{
	if(root!=NULL)
	{
		inordertraversal(root->left);
		printf("%d",root->data);
		inordertraversal(root->right);
	}
}
void preorderTraversal(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}
void postorderTraversal(struct node*root)
{
	if(root!=NULL)
	{
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d",root->data);
	}
}
int main()
{
	int n,i,data;
	struct node*root=NULL;
	printf("****Tree Traversal****\n\n");
	printf("Enter Numbers of nodes in binary tree:");
	scanf("%d",&n);
	printf("Enter Data for following elements:\n");
	for(i=0;i<n;i++)
	{
		printf("Node %d:",i+1);
		scanf("%d",&data);
		root=insert(root,data);
	}
	printf("Inorder traversal:");
	inordertraversal(root);
	printf("\nPreorder traversal:");
	preorderTraversal(root);
	printf("\nPostorder traversal:");
	postorderTraversal(root);
	return 0;
}
