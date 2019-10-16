//#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>

Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->key = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->color = "black";
	
	return node;	
}



