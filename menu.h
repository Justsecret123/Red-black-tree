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



void menu(Node* test)
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
	
	int exit;
	
	printf("\n\n\n-------------------------------Enter a key---------------------------------------------\n\n\n1: Main Menu \tOther: Exit \t");
	scanf("%d",&exit);
	if(exit==1){
		system("CLS");
		goto LOOP;
	}
}


