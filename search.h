//#include<stdio.h>
//#include<stdlib.h>

struct Node* search(struct Node* node, int key)
{
	if(node==NULL)
		{return NULL;}
	else 
	{
		if(node->key == key)
			{return node;}
		else
			{return (key > node->key) ? search(node->right,key) : search(node->left,key);}
	}
}
