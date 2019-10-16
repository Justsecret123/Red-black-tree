//#include<stdio.h>
//#include<stdlib.h>


//Buffer size initialization
HANDLE initialize_screen()
{
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer;
	buffer.X = 120;
	buffer.Y = 200;
	SetConsoleScreenBufferSize(hconsole,buffer);
	
	return hconsole;
}

void display_node(Node* node)
{
	if(node->color == "red") 
		{ 
		  printf(RED " %d", node->key);
		  printf(RESET "");
		}
	else 
		{printf("%d",node->key);}
}

//Go to the center of the screen
void goto_center(Node* node)
{
	
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos, end_position;
	pos.X = 60;
	pos.Y = 0;
	SetConsoleCursorPosition(hconsole, pos); //Set cursor at the center of the screen
	
	printf("%d", node->key); 
	
	pos.X = 57;
	pos.Y = 1;
	SetConsoleCursorPosition(hconsole, pos);
	printf("/"); //Display left branch
	
	pos.X = 63;
	pos.Y = 1;
	SetConsoleCursorPosition(hconsole, pos);
	printf("\\"); //Display right branch
	
	pos.X = 60;
	pos.Y = 0;
	SetConsoleCursorPosition(hconsole, pos);	
}


//Get the current position of the cursor
COORD cursor_position(HANDLE hconsole)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	
	if(GetConsoleScreenBufferInfo(hconsole,&cbsi))
		{return cbsi.dwCursorPosition;}
	else
		{
			COORD invalid = {0,0};
			return invalid;
		}
}

int GetDesiredPositionLeft(HANDLE hconsole, int level)
{
	return (level==1)? 50:cursor_position(hconsole).X-3;
}

int GetDesiredPositionRight(HANDLE hconsole, int level)
{
		switch(level)
	{
		case 1:
			return 70;
		default:
			return cursor_position(hconsole).X+5;
	}
}

void branches(HANDLE hconsole, COORD desired_position)
{
	COORD reset = desired_position;
	desired_position.X-=1;
	desired_position.Y+=1;
	SetConsoleCursorPosition(hconsole,desired_position);
	printf("/"); //Left Branch
	
	desired_position.X+=2;
	SetConsoleCursorPosition(hconsole,desired_position);
	printf("\\"); //Right Branch
	SetConsoleCursorPosition(hconsole,reset);
}

//Case 1 : Parent's left node
void goto_left(Node* node, HANDLE hconsole, int level)
{
	COORD desired_position;
	
	desired_position.X =  GetDesiredPositionLeft(hconsole,level);
	desired_position.Y = level * 2;
	SetConsoleCursorPosition(hconsole,desired_position);
	display_node(node);
	branches(hconsole,desired_position);
}
//Case 2 : Parent's right node
void goto_right(Node* node, HANDLE hconsole, int level)
{
	COORD desired_position;
	
	desired_position.X =  GetDesiredPositionRight(hconsole,level);
	desired_position.Y = level * 2;
	SetConsoleCursorPosition(hconsole,desired_position);
	display_node(node);
	branches(hconsole,desired_position);	
}


 void display_tree(Node* node, int level)
{
	//Base condition
	if(node !=NULL)
		{	
			HANDLE hconsole = initialize_screen();
			COORD current_position;
			
			if(level==0) //Case 0
				{goto_center(node);}
			else if(node==node->parent->left) //Case 1
				{goto_left(node,hconsole,level);}
			else //Case 2
				{goto_right(node,hconsole,level);}
				
			display_tree(node->left, level+1);
			display_tree(node->right, level+1);
		}
	
}

void display_tree_normal(Node* node, int level)
{
	if(node !=NULL)
		{	
			
			printf("\n %d",node->key);	
			display_tree_normal(node->left, level+1);
			display_tree_normal(node->right, level+1);
		}	
}
