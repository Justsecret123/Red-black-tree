//#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>

void menu_insertion()
{
	int key;
	printf("Enter a key: ");
	scanf("%d",&key);
}

void menu_removal()
{
	int key;
	printf("Enter the key of the node you want to remove: ");
	scanf("%d", &key);
}

void menu_display(Node* root)
{
	printf("Current tree: \n\n\n");
	display_tree(root,0);
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



void menu(Node* test)
{
	int choice, confirm; 
	
	printf("**************Red-black trees****************\n1-Insertion\n2-Removal\n3-Display the tree\n4-Search a key\n5-Exit\n\nWhich operation do you want to do ? ");
	scanf("%d", &choice);
	
	fflush(stdin);
	getch();
	system("cls");
	
	switch(choice)
	{
	
		case 1:
			menu_insertion();
			break;
		case 2: 
			menu_removal();
			break;
		case 3:
			menu_display(test);
			break;
		case 4:
			menu_search(test);
			break;
		case 5:
			printf("Do you really want to quit ? : 1(Yes) - Otherwise (No): ");
			scanf("%d", &confirm);
				if(confirm==1) 
					{exit(0);}
				else 
					{menu(test);}	
			break;
		default:
			menu(test);	
	}
}

