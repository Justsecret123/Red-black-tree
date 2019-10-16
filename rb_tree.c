#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1b[30m"


//Strucuture declaration
typedef struct Node
{
	struct Node* parent; 
	struct Node* left; 
	struct Node* right; 
	char* color;
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
		{return (node->parent==result->left)? result->right : result->left;}
return NULL;
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
	Node* test, *test2, *test3, *test4, *test5, *test6, *test7;
	
	//Creation
	test = (Node*)malloc(sizeof(Node));
	test->left = NULL;
	test->right = NULL; 
	test->parent = NULL;
	test2 = (Node*)malloc(sizeof(Node));
	test3 = (Node*)malloc(sizeof(Node));
	test4 = (Node*)malloc(sizeof(Node));
	test5 = (Node*)malloc(sizeof(Node));
	test6 = (Node*)malloc(sizeof(Node));
	test7 = (Node*)malloc(sizeof(Node));
	
	//Keys
	test->key=8;
	test2->key=6;
	test3->key=10;
	
	test4->key=5;
	test5->key=7;
	
	test6->key=9;
	test7->key=11;
	
	
	//Colors
					
	test->color = "black";
	test2->color = "red";
	test3->color = "red";
	test4->color = "black";
	test5->color = "black";
	test6->color = "black";
	test7->color = "black";

	//Root 
	test->left=test2;
	test->right=test3;
	
	//Nodes
	test2->left = test4;
	test2->right=test5;
	test2->parent = test;
	
	test3->left=test6;
	test3->right=test7;
	test3->parent = test;
	
	test4->left=NULL;
	test4->right=NULL;
	test4->parent= test2;
	
	test5->left=NULL;
	test5->right=NULL;
	test5->parent = test2;
	
	test6->left=NULL;
	test6->right=NULL;
	test6->parent = test3;
	
	test7->left=NULL;
	test7->right=NULL;
	test7->parent = test3;
	
	//Screen size
	system("COLOR F0");
	system("mode con: cols=100 lines=30");
	
	//Loop
	menu(test);
	
	

	
	return 0;
}
