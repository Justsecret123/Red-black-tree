#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void menu_insertion()
{
	
}

void menu_removal()
{
	
}

void menu_display()
{
	
}

void menu_search()
{
	int choice;
	fflush(stdin);
	getch();
	system("cls");
	printf("Enter the Key: ");
	scanf("%d", &choice);
}



void menu()
{
	int choice, confirm; 
	
	printf("**************Red-black trees****************\n1-Insertion\n2-Removal\n3-Display the tree\n4-Search a key\n5-Exit\n\nWhich operation do you want to do ? ");
	scanf("%d", &choice);
	
	switch(choice)
	{
	
		case 1:
			menu_insertion();
			break;
		case 2: 
			menu_removal();
			break;
		case 3:
			menu_display();
			break;
		case 4:
			menu_search();
			break;
		case 5:
			printf("Do you really want to quit ? : 1(Yes) - Otherwise (No): ");
			scanf("%d", &confirm);
				if(confirm==0) 
					{exit(0);}
				else 
					{menu();}	
			break;
		default:
			menu();	
	}
}


