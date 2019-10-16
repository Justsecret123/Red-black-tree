//#include<stdio.h>
//#include<stdlib.h>




void display_node(Node* node)
{
	if(node->color == "red") 
		{ 
		  printf(RED " %d\n", node->key);
		  printf(RESET "");
		}
	else 
		{printf(" %d\n",node->key);}
}

void display_tree(Node* node, int level)
{
	if(node !=NULL)
		{level += COUNT; 

		display_tree(node->right, level); 

		//Node after space count
		printf("\n"); 
		for (int i = COUNT; i < level; i++) 
		printf(" "); 
		display_node(node); 

		display_tree(node->left, level); 
		
		}	
}

