//#include<stdio.h>
//#include<stdlib.h>

 void display_tree(Node* root, int level)
{
	
	if(root !=NULL)
		{	
			char color[5];
			
			printf("Node key: %d", root->key);
			printf("\nColor: %s",root->color);
			printf("\nLevel: %d", level);
			printf("\n\n");
			display_tree(root->left, level+1);
			display_tree(root->right, level+1);
			
		}
	
	
}
