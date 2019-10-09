#include<stdio.h>
#include<stdlib.h>



//Strucuture declaration
typedef struct Node
{
	struct Node* parent; 
	struct Node* left; 
	struct Node* right; 
	char color[4];
	int key;	
}
Node;

#include "search.h"
#include "display.h"
#include "print.h"
#include "node.h"



Node* getParent(Node* node)
{
	return (node==NULL)? NULL : node->parent;
}

Node* getGrandParent(Node* node)
{
 	return (node==NULL || node->parent==NULL)? NULL : node->parent->parent;
}

Node* getUncle(Node* node)
{
	Node* result = getGrandParent(node);
	if(result==NULL)
		{return NULL;}
	else
//		{return (node==result->)}
//return NULL;
}

Node* getSibling(Node* node)
{
	if(node==NULL || node->parent==NULL)
		{return(NULL);}
	else
		{return	(node==node->parent->left)? node->parent->right : node->parent->left;}
}



int main()
{
	Node* test, *test2, *test3;
	
	//Creation
	test = (Node*)malloc(sizeof(Node));
	test2 = (Node*)malloc(sizeof(Node));
	test3 = (Node*)malloc(sizeof(Node));
	
	//Keys
	test->key=3;
	test2->key=9;
	test3->key=8;
	
	//Colors
	test->color[0]='b';
		test->color[1]='l';
			test->color[2]='a';
				test->color[3]='c';
					test->color[4]='k';
	
	test2->color[0]='r';
		test2->color[1]='e';
			test2->color[2]='d';
				test2->color[3]='\0';
	
	test3->color[0]='r';
		test3->color[1]='e';
			test3->color[2]='d';
					test3->color[3]='\0';
	
	//Root
	test->left=test2;
	test->right=test3;
	
	//Nodes
	test2->left=NULL;
	test2->right=NULL;
	test3->left=NULL;
	test3->right=NULL;
	
	//Loop
	menu(test);
	
	return 0;
}
