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
#include<assert.h>




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

#include "node.h"
#include "menu.h"

int main()
{
	Node* test, *test2, *test3, *test4, *test5, *test6, *test7, *test8, *test9, *test10, *test11;
	
	/* ------- Test nodes creation -------- */
	
	/* ----- Root ------ */
	test = (Node*)malloc(sizeof(Node));
	test->key = 8;
	test->color = "black";
	test->left = NULL;
	test->right = NULL; 
	test->parent = NULL;
	
	
	//Screen size
	system("COLOR F0");
	system("mode con: cols=120 lines=38");
	
	//Loop
	menu(test);
	


	
	return 0;
}
