
//#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>


enum node_color { BLACK , RED };

typedef struct Node
{
	struct Node* parent; 
	struct Node* left; 
	struct Node* right; 
	enum node_color color;
	int key;	
}
Node;

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
