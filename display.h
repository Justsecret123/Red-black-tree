//#include<stdio.h>
//#include<stdlib.h>


//Buffer size initialization
void initialize_screen()
{
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer;
	buffer.X = 100;
	buffer.Y = 100;
	SetConsoleScreenBufferSize(hconsole,buffer);
}


//Go to the center of the screen
void goto_center(Node* node)
{
	
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 50;
	pos.Y = 0;
	SetConsoleCursorPosition(hconsole, pos); //Set cursor at the center of the screen
	
	printf(RED "%d", node->key); 
	printf(RESET "");
	
	pos.X = 47;
	pos.Y = 1;
	SetConsoleCursorPosition(hconsole, pos);
	printf("/"); //Display left branch
	
	pos.X = 53;
	pos.Y = 1;
	SetConsoleCursorPosition(hconsole, pos);
	printf("\\"); //Display right branch
	
}

//Case 1 : Parent's left node
void goto_left(Node* node)
{
	
}

void goto_right(Node* node)
{
	
}

//Case 2 : Parent's right node
 void display_tree(Node* node, int level)
{

	initialize_screen();
	
	//Base condition
	if(node !=NULL)
		{	
			if(level==0) //Case 0
				{goto_center(node);}
			else if(node==node->parent->left) //Case 1
				{goto_left(node);}
			else //Case 2
				{goto_right(node);}
				
			display_tree(node->left, level+1);
			display_tree(node->right, level+1);
		}	
}
