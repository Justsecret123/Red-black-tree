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




