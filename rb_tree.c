#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>

/*
|--------------|
 Define colors
|-------------| 
*/

#define RED   "\x1B[31m"
#define GRN   "\x#endif1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1b[30m"


/*
|----------------------------|
  Node structure declaration
|---------------------------|
*/

typedef struct Node
{
	struct Node* parent; 
	struct Node* left; 
	struct Node* right; 
	char* color;
	int key;
}
Node;

/*
|---------------------------------------------|
  Point structure declaration (see display.h) 
|--------------------------------------------|
*/
typedef struct Point
{
	int LastX;
	int step;
}
Point;


/*
|------------|
 Header files
|-----------|
*/

#include "search.h"
#include "display.h"
#include "menu.h"
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
	Node* test, *test2, *test3, *test4, *test5, *test6, *test7, *test8, *test9, *test10, *test11;
	
	/* ------- Test nodes creation -------- */
	
	/* ----- Root ------ */
	test = (Node*)malloc(sizeof(Node));
	test->left = NULL;
	test->right = NULL; 
	test->parent = NULL;
	
	/* --------- First level nodes ------- */ 
	test2 = (Node*)malloc(sizeof(Node));
	test3 = (Node*)malloc(sizeof(Node));
	
	/* --------- Second level nodes ------- */ 
	test4 = (Node*)malloc(sizeof(Node));
	test5 = (Node*)malloc(sizeof(Node));
	test6 = (Node*)malloc(sizeof(Node));
	test7 = (Node*)malloc(sizeof(Node));

	/* ------ Third level nodes ----------*/
	test8 = (Node*)malloc(sizeof(Node));
	test9 = (Node*)malloc(sizeof(Node));
	test10 = (Node*)malloc(sizeof(Node));
	test11= (Node*)malloc(sizeof(Node));
	
			
	
	/* ------- Test nodes keys ------- */
	
	test->key=8;
	
	test2->key=6;
	test3->key=10;
	
	test4->key=5;
	test5->key=7;
	
	test6->key=9;
	test7->key=11;
	
	
	
	/* --------- Test nodes colors ---------- */
					
	test->color = "black";
	test2->color = "black";
	test3->color = "black";
	test4->color = "red";
	test5->color = "red";
	test6->color = "red";
	test7->color = "red";

	//Root 
	test->left=test2;
	test->right=test3;
	test->parent=NULL;
	
	//Nodes : 6 = test2
	test2->parent = test;
	test2->left = test4;
	test2->right = test5;
	
//	//Nodes : 5 = test4
	test4->parent = test2;
	test4->left = NULL;
	test4->right = NULL;
	
	//Nodes : 7 = test5
	test5->parent = test2;
	test5->left = NULL;
	test5->right = NULL;
	
	//Nodes : 10 = test3
	test3->parent = test;
	test3->left = test6;
	test3->right = test7;
	
	//Nodes : 9 = test6 
	test6->parent = test3;
	test6->left = NULL;
	test6->right = NULL;
	
	//Nodes : 11 = test7
	test7->parent = test3;
	test7->left = NULL;
	test7->right = NULL;
	
	
	//Screen size
	system("COLOR F0");
	system("mode con: cols=120 lines=38");
	
	//Loop
	menu(test);
	
	

	
	return 0;
}
