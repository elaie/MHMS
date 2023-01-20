#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#include"Password.c"
#include"Menu.c"
#include"Reserve.c"
#include"Extra_Functions.h"
void main()
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	int a,S,i,f,COUNT=0;

	for(i=0;i<3;i++)
	{
		//Admin_Register_Pass();
		f=Admin_Verification();
		if(f==0)
		{
			Sleep(900);
			printf("Access Granted\n");
			getch();
			system("cls");
			break;
		}
	if(f==1)
	
	{
		Sleep(900);
		printf("Incorrect Password Please Try again! /n");
		getch();
		system("cls");
		COUNT++;
	}
	if(COUNT==3)
	exit (0);
	}
	while(1){
		system("cls");
	gotoxy(30,10);
	for (i=0;i<25;i++)
	{
		printf("%c",205);	
	}
	gotoxy(30,11);printf("%c",186);printf("Enter An Option: ");gotoxy(55,11);printf("%c",186);
	gotoxy(30,12);printf("%c",186);printf("1) Menu ");gotoxy(55,12);printf("%c",186);
	gotoxy(30,13);printf("%c",186);printf("2) Snacks Table ");gotoxy(55,13);printf("%c",186);
	gotoxy(30,14);printf("%c",186);printf("3) Dinner Table ");gotoxy(55,14);printf("%c",186);
	gotoxy(30,15);printf("%c",186);printf("4) Parking ");gotoxy(55,15);printf("%c",186);
	gotoxy(30,16);printf("%c",186);printf("5) Display Recipt ");gotoxy(55,16);printf("%c",186);
	gotoxy(30,17);printf("%c",186);printf("6) Settings ");gotoxy(55,17);printf("%c",186);
	gotoxy(30,18);
	for(i=0;i<25;i++)
	{
		printf("%c",205);
	}
	scanf("%d",&a);
	system("cls");
	char tempfood[100],fa[100];
	int tempstock,tempprice;
	head = readLinkedList("Menu.txt"); // empty list
	switch(a)
	{
		case 1: 
			viewMenu();
		case 2:
			Snacks_T();
			break;
		case 3:
			Dinner_T();
			break;
		case 4:
			Parking();
			break;
		case 5:
			DISP();
			break;
		case 6:
			system("cls");
			
			gotoxy(50,16);printf("%c",186);printf("Enter An Option:");gotoxy(75,16);printf("%c",186);
			gotoxy(50,17);printf("%c",186);printf("1) Display Stocks");gotoxy(75,17);printf("%c",186);
			gotoxy(50,18);printf("%c",186);printf("2) Modify Stocks");gotoxy(75,18);printf("%c",186);
			gotoxy(50,19);printf("%c",186);printf("3) Modify Prices");gotoxy(75,19);printf("%c",186);
			gotoxy(50,20);printf("%c",186);printf("4) Change Password");gotoxy(75,20);printf("%c",186);
			gotoxy(50,21);printf("%c",186);printf("5) Add Item");gotoxy(75,21);printf("%c",186);
			
			scanf("%d",&S);
		switch(S)
		{
			case 1:
				displayStocks("Menu.txt");
				getch();
				break;
			case 2:
			//	Menu_PutData();
				break;
			case 3:
			//	M_Put_Price();
				break;
			case 4:
				Admin_Register_Pass();
				break;
			case 5:
					printf("%d food ",i);
    				scanf("%s",&tempfood);
    				printf("%d stock ",i);
    				scanf("%d",&tempstock);
    				printf("%d price ",i);
    				scanf("%d",&tempprice);
    				insert(tempstock,tempfood,tempprice);
    				writeLinkedList(head);
    				//printList(readLinkedList("Menu.txt"),0);
    				break;
		}
	}
	
	}
	//SetConsoleTextAttribute(color, 10);gotoxy(30,10);
	
			 
/*	int S,i,a;
	cout<<"Enter Option:\n1)Enter DATA:\n2)Display DATA ";
	cin>>S;
	switch(S)
	{
		case 1:
			Put_Data();
			break;
		case 2:
			Get_Data();
			break;
		case 3:
			Put_No(a);
			break;
		case 4:
			E_Delete();
			break;
	}	*/
/*	int B;
	cout<<"Enter Option:\n1)Enter DATA:\n2)Display DATA ";
	cin>>B;
	switch(B)
	{
		case 1:
			User_Register_Pass();
			break;
		case 2:
			User_Verification();
			break;
	}*/
	getch();
}
