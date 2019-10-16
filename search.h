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
			if(key > node->key)
				{return search(node->right,key);}
			else
				{return(search(node->left,key));}
	}
}
