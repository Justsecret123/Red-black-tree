/*
-------------------------------------------------------------------------------------------------------------------------------------------------
This file contains the needed functions and instructions in order to display a tree
-------------------------------------------------------------------------------------------------------------------------------------------------

*/


/*
|----------------------------------------------------------------------------------------------------|
The depth function returns the depth of the tree. You can find its relevance in the latter functions. 
|---------------------------------------------------------------------------------------------------|
*/

int depth(Node* root) 
{
	if(root==NULL || root->left==NULL && root->right==NULL) /* ------ Case 1 & 2 : The actual node NULL (case1) or a leaf --------- */
		{return 0;} 
	else 
		{return depth(root->left)>depth(root->right)? 1+depth(root->left) : 1+depth(root->right);} /*Return the maximum depth between its 
																										right and left node*/
}

int coef(int order)
{
	if(order==1){
		return 2;
	}
	else{
		return  (coef(order-1)*2)+1;	
	}	
}

int Un(int depth)
{
	
	if(depth==1){
		return 4;
	}
	else{
		return 2*coef(depth);
	}
}

/*
|----------------------------------------------|
Returns the maximum width of the screen buffer  
|---------------------------------------------|
*/
int max_space(Node* root) 
{
	int tree_depth = depth(root);
	if(tree_depth!=0){
		return Un(tree_depth);
	}
}

/*
|---------------------------------------|
Displays the node in his defined color.  
|--------------------------------------|
*/
void display_node(Node* node)
{
	if(node->color == "red") 
		{ 
		  printf(RED " %d", node->key);
		  printf(RESET "");
		}
	else 
		{printf(" %d",node->key);}
}

/*
|---------------------------------------------------------------------------|
Returns the new step. Each level, the step size decreases almost by a half. 
|--------------------------------------------------------------------------|
*/
int find_step(int initial)
{
	return (initial/2)+1;
}


/*
|--------------------------------------------------------------|
Moves the cursor position to the left side of the current one
|-------------------------------------------------------------|
*/
Point goto_left(Node* node, HANDLE hconsole, Point initial, int level, int depth)
{
	COORD desired_position;
	Point step;
	
	step.step = find_step(initial.step);   /* ---- Get the new step ----- */
	desired_position.X = initial.LastX - step.step; /* ---- New X = initial(X) - step ----- */
	step.LastX = desired_position.X;
	desired_position.Y = level + 1; /* ---- Go to the next line ----- */
	SetConsoleCursorPosition(hconsole,desired_position); /* ---- Sets the cursor position to the left side of the initial one ---- */
	
	display_node(node);
	return step; /* ---------- Returns a Struct Point containing the current x and the current step as well -------- */
}


/*
|--------------------------------------------------------------|
Moves the cursor position to the right side of the current one
|-------------------------------------------------------------|
*/
Point goto_right(Node* node, HANDLE hconsole, Point initial, int level, int depth)
{
	COORD desired_position;
	Point step;
	step.step = find_step(initial.step); /* ---- Get the new step ----- */
	
	desired_position.X = initial.LastX + step.step; /* ---- New X = initial(X) + step ----- */
	step.LastX = desired_position.X; 
	desired_position.Y = level + 1; /* ---- Go to the next line ----- */
	SetConsoleCursorPosition(hconsole,desired_position); /* ---- Sets the cursor position to the right side of the initial one ---- */
	
	display_node(node);
	return step; /* ---------- Returns a Struct Point containing the current x and the current step as well -------- */
}

/*
|-----------------------------------------|
Returns the handle of the console (screen)
|----------------------------------------|
*/
HANDLE getHandle()
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}


/*
|--------------------------------------------------------------------|
Main function : gathers all the functions above to display the tree
|-------------------------------------------------------------------|
*/

void DisplayTree(Node* node, HANDLE handle, int level, int depth, Point x)
{

	if(node !=NULL){
		if(node->parent!=NULL){ /* ----- Case 1 : The node is his parent's left son ----- */
		
			if(node==node->parent->left){
				Point newX = goto_left(node,handle,x,level,depth); /* ----- Move to the left side ----- */
				DisplayTree(node->left,handle, level+1,depth,newX);
				DisplayTree(node->right,handle,level+1,depth,newX);
			}
			else{ /* ------ Case 2 : The node is his parent's right son ------- */
				Point newX = goto_right(node,handle,x,level,depth); /* ---- Move to the right side ---- */
				DisplayTree(node->left,handle, level+1,depth,newX);
				DisplayTree(node->right,handle,level+1,depth,newX);
			}
		}
		
		/* ---------- Case 3 : Root.  ----------- */
		else{
			COORD coord;
			coord.X = x.LastX/2; /* ---- In this case, the LastX contains the last column of the screen buffer. ------- */
			coord.Y = 0; 
			x.LastX = coord.X; /* ---- The LastX contains now the column at the middle of the buffer -----*/
			x.step = coord.X; /* ---- The first step = Last Column / 2 -----*/ 
			
			SetConsoleCursorPosition(handle,coord); /* ---- Sets the cursor position to  [line=0;column=center] ----*/
			display_node(node);
			DisplayTree(node->left,handle, level+1,depth,x);
			DisplayTree(node->right,handle,level+1,depth,x);
		}
		
			
	}
}

