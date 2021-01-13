/*Standard libraries*/
#include<stdio.h>
#include<stdlib.h>

/*Libraries*/
#include<malloc.h>
#include<windows.h>
#include<assert.h>

/*Header files*/

/****Struct and macros*****/
#include "colors_definition.h"
#include "point.h"
#include "node.h"

/*Functions*/
#include "search.h"
#include "display.h"
#include "get.h"
#include "rotations.h"
#include "insertion.h"
#include "removal.h"

/*Menu*/
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

