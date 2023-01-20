#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>
#include<windows.h>
#include"Password.c"
#include"Menu.c"
#include"Reserve.c"
#include"Extra_Functions.h"
#include"employee.c"
void main()
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	int a,S,S2,i,f,COUNT=0;

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
	gotoxy(30,16);printf("%c",186);printf("5) Employee Information ");gotoxy(55,16);printf("%c",186);
	gotoxy(30,17);printf("%c",186);printf("6) Display Reciept ");gotoxy(55,17);printf("%c",186);
	gotoxy(30,18);printf("%c",186);printf("7) Settings ");gotoxy(55,18);printf("%c",186);
	gotoxy(30,19);
	for(i=0;i<25;i++)
	{
		printf("%c",205);
	}
	scanf("%d",&a);
	system("cls");
	char tempfood[100],fa[100],name[100];
	int tempstock,tempprice,eid;
	float salary;
	head = readLinkedList("Menu.txt"); // empty list
	head2= readLinkedList2("Employee.txt");
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
			system("cls");	
			gotoxy(50,16);printf("%c",186);printf("Enter An Option:");gotoxy(100,16);printf("%c",186);
			gotoxy(50,17);printf("%c",186);printf("1) Display Employee Information");gotoxy(100,17);printf("%c",186);
			gotoxy(50,18);printf("%c",186);printf("2) Add New Employee");gotoxy(100,18);printf("%c",186);
			gotoxy(50,19);printf("%c",186);printf("3) Modify Employee Salary");gotoxy(100,19);printf("%c",186);
			gotoxy(50,20);printf("%c",186);printf("4) Delete Employee Information");gotoxy(100,20);printf("%c",186);
			scanf("%d",&S2);
			switch(S2)
			{
			case 1:
				printEList(readLinkedList("Employee.txt"));
				getch();
				break;
			case 2:
					printf("Enter Name: ");
    				scanf("%s",name);
    				printf("Enter EID: ");
    				scanf("%d",&eid);
    				printf("Enter Salary: ");
    				scanf("%f",&salary);
    				insert2(eid,name,salary);
    				writeLinkedList2(head2);
					
   					break;
			case 3:
				update_salary();
				break;
			case 4:
				Admin_Register_Pass();
				break;					
		}
			break;
		case 6:
			DISP();
			break;
		case 7:
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
				displayStocks(readLinkedList("Menu.txt"));
				getch();
				break;
			case 2:
				update_stocks();
				break;
			case 3:
				update_price();
				break;
			case 4:
				Admin_Register_Pass();
				break;
			case 5:
				printf("Enter Food: ");
    				scanf("%s",&tempfood);
    				printf("Enter Stock: ");
    				scanf("%d",&tempstock);
    				printf("Enter Price: ");
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
