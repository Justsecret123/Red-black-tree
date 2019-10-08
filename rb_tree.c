#include<stdio.h>
#include<stdlib.h>

enum node_color { BLACK , RED };

//Strucuture declaration
typedef struct Node
{
	struct Node* parent; 
	struct Node* left; 
	struct Node* right; 
	enum node_color color;
	int key;	
}
Node;

#include "print.h"
#include "node.h"
#include "search.h"

Node* getParent(Node* node)
{
	return node->parent;
}

Node* getGrandParent(Node* node)
{
	
}

Node* getUncle(Node* node)
{
	
}

Node* getSibling(Node* node)
{
	
}



int main()
{
	menu();
	return 0;
}
