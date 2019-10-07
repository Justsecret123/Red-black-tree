#include<stdio.h>
#include<stdlib.h>
#include "print.h"
#include "node.h"
enum node_color { BLACK , RED };

struct Node
{
	struct Node* parent; 
	struct Node* left; 
	struct Node* right; 
	enum node_color color;
	int key;	
}
Node;

struct Node* getParent(struct Node* node)
{
	return node->parent;
}

struct Node* getGrandParent(struct Node* node)
{
	
}

struct Node* getUncle(struct Node* node)
{
	
}

struct Node* getSibling(struct Node* node)
{
	
}


int main()
{
	menu();
	return 0;
}
