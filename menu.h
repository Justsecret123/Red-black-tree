
Node* menu_insertion(Node* root)
{
	int key;
	printf("Enter a key: ");
	scanf("%d",&key);
	Node* node = (Node*)malloc(sizeof(Node));
	node->key = key;
	root = Insert(root,node);
	return root;
	
}

void menu_removal(Node* root)
{
	int key;
	printf("Enter the key of the node you want to remove: ");
	scanf("%d", &key);
	Node* node = search(root,key);
	if(node==NULL){
		printf("Node not found.");
		menu_removal(root);
	}
	else{
		menu_display(root);
	}
}

void menu_display(Node* root)
{	COORD buffer;
	HANDLE handle = getHandle();
	Point x;
	
	buffer.X = max_space(root);
	buffer.Y = buffer.X;
	SetConsoleScreenBufferSize(handle,buffer);
	x.LastX = max_space(root);
	
	DisplayTree(root,getHandle(),0,depth(root),x);
	

}

void menu_search(Node* test)
{
	int key;
	struct Node* result;
	
	printf("Enter the Key: ");
	scanf("%d", &key);
	result=search(test,key);
	
	if(result==NULL)
		{printf("Not found :(");}
	else
		{printf("Found :D ");}
}



void menu(Node* root)
{
	int choice, confirm; 
	LOOP:
	printf("**************Red-black trees****************\n1-Insertion\n2-Removal\n3-Display the tree\n4-Search a key\n5-Exit\n\nWhich operation do you want to do ? ");
	scanf("%d", &choice);
	getch();
	system("cls");
	
	switch(choice)
	{
	
		case 1:
			root = menu_insertion(root);
			menu(root);
			break;
		case 2: 
			menu_removal(root);
			break;
		case 3:
			menu_display(root);
			break;
		case 4:
			menu_search(root);
			break;
		case 5:
			printf("Do you really want to quit ? : 1(Yes) - Otherwise (No): ");
			scanf("%d", &confirm);
				if(confirm==1) 
					{exit(0);}
				else 
					{menu(root);}	
			break;
		default:
			menu(root);	
	}
	
	int exit;
	
	printf("\n\n\n-------------------------------Enter a key---------------------------------------------\n\n\n1: Main Menu \tOther: Exit \t");
	scanf("%d",&exit);
	if(exit==1){
		system("CLS");
		goto LOOP;
	}
}


