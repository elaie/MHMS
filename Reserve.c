#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
void gotoxyR(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Check_D(int a,int i);
void Check_P(int a,int i);
void Check_R(int a,int i);
static int x,y,Count;
void Check_R(int a,int i)
{
	char s1[6]="Empty",s2[9]="Reserved";
		gotoxyR(x,y);
		if(a==0)
			printf("Snacks Table %d : %s\n",i+1,s1);
		else
			printf("Snacks Table %d : %s\n",i+1,s2);
		y++;
}

void Check_D(int a,int i)
{
	char s1[6]="Empty",s2[9]="Reserved";
		gotoxyR(x,y);
		if(a==0)
			printf("Dinner Table %d : %s\n",i+1,s1);
		else
			printf("Dinner Table %d : %s\n",i+1,s2);
		y++;
}

void Check_P(int a,int i)
{
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	char s1[6]="Empty",s2[9]="Reserved";
		if(a==0)
			{
				SetConsoleTextAttribute(color, 4);
 			}
		else
			{
				SetConsoleTextAttribute(color, 2);
 			}
 		if(Count==0)
				{
					gotoxyR(x+4,y+4);
					printf("%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178);
 					gotoxyR(x+2,y+5);
 					printf("%c%c%c%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178,178,178,178);
		 			gotoxyR(x+3,y+6);
 					printf("%c",162);
 					gotoxyR(x+10,y+6);
 					printf("%c",162);
 					Count=1;
 				}
				else
				{
					
					gotoxyR(x+4,y+4);
 					printf("%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178);
 					gotoxyR(x+22,y+5);
 					printf("%c%c%c%c%c%c%c%c%c%c%c",178,178,178,178,178,178,178,178,178,178,178);
		 			gotoxyR(x+23,y+6);
 					printf("%c",162);
 					gotoxyR(x+30,y+6);
 					printf("%c",162);
 					Count=0;
 					y+=4;
				}
}

void Dinner_T()
{
	int ch,flag[9],i=0;
	for(i;i<9;i++)
	flag[i]=0;
	do
	{
		ch=_getch();
		system("cls");
		x=5;
		y=6;
			if(ch==49)
				{
					if(flag[0]==0)
					{
						flag[0]=1;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					else if(flag[0]==1)
					{
						flag[0]=0;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					
				}
			else if(ch==50)
				{
					if(flag[1]==0)
					{
						flag[1]=1;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					else if(flag[1]==1)
					{
						flag[1]=0;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
				}
			else if(ch==51)
				{
					if(flag[2]==0)
					{
						flag[2]=1;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					else if(flag[2]==1)
					{
						flag[2]=0;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
				}
			else if(ch==52)
				{
					if(flag[3]==0)
					{
						flag[3]=1;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					else if(flag[3]==1)
					{
						flag[3]=0;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
				}
			else if(ch==53)
				{
					if(flag[4]==0)
					{
						flag[4]=1;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					else if(flag[4]==1)
					{
						flag[4]=0;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
				}
			else if(ch==54)
				{
					if(flag[5]==0)
					{
						flag[5]=1;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					else if(flag[5]==1)
					{
						flag[5]=0;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
				}
			else if(ch==55)
				{
					if(flag[6]==0)
					{
						flag[6]=1;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					else if(flag[6]==1)
					{
						flag[6]=0;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
				}
			else if(ch==56)
				{
					if(flag[7]==0)
					{
						flag[7]=1;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					else if(flag[7]==1)
					{
						flag[7]=0;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
				}
			else if(ch==57)
				{
					if(flag[8]==0)
					{
						flag[8]=1;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}
					else if(flag[8]==1)
					{
						flag[8]=0;
						for(i=0;i<9;i++)
							Check_D(flag[i],i);
					}																					
				}		
	}while(ch!=13);
}
void Parking()
{
	int ch,flag[9],i=0;
	for(i;i<9;i++)
	flag[i]=0;
	do
	{
		ch=_getch();
		system("cls");
		x=5;
		y=6;
			if(ch==49)
				{
					if(flag[0]==0)
					{
						flag[0]=1;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					else if(flag[0]==1)
					{
						flag[0]=0;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					
				}
			else if(ch==50)
				{
					if(flag[1]==0)
					{
						flag[1]=1;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					else if(flag[1]==1)
					{
						flag[1]=0;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
				}
			else if(ch==51)
				{
					if(flag[2]==0)
					{
						flag[2]=1;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					else if(flag[2]==1)
					{
						flag[2]=0;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
				}
			else if(ch==52)
				{
					if(flag[3]==0)
					{
						flag[3]=1;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					else if(flag[3]==1)
					{
						flag[3]=0;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
				}
			else if(ch==53)
				{
					if(flag[4]==0)
					{
						flag[4]=1;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					else if(flag[4]==1)
					{
						flag[4]=0;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
				}
			else if(ch==54)
				{
					if(flag[5]==0)
					{
						flag[5]=1;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					else if(flag[5]==1)
					{
						flag[5]=0;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
				}
			else if(ch==55)
				{
					if(flag[6]==0)
					{
						flag[6]=1;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					else if(flag[6]==1)
					{
						flag[6]=0;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
				}
			else if(ch==56)
				{
					if(flag[7]==0)
					{
						flag[7]=1;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					else if(flag[7]==1)
					{
						flag[7]=0;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
				}
			else if(ch==57)
				{
					if(flag[8]==0)
					{
						flag[8]=1;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}
					else if(flag[8]==1)
					{
						flag[8]=0;
						for(i=0;i<9;i++)
							Check_P(flag[i],i);
					}																					
				}		
	}while(ch!=13);
}
void Snacks_T()
{
	int ch,flag[9],i=0;
	for(i;i<9;i++)
	flag[i]=0;
	do
	{
		ch=_getch();
		system("cls");
		x=5;
		y=6;
			if(ch==49)
				{
					if(flag[0]==0)
					{
						flag[0]=1;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					else if(flag[0]==1)
					{
						flag[0]=0;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					
				}
			else if(ch==50)
				{
					if(flag[1]==0)
					{
						flag[1]=1;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					else if(flag[1]==1)
					{
						flag[1]=0;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
				}
			else if(ch==51)
				{
					if(flag[2]==0)
					{
						flag[2]=1;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					else if(flag[2]==1)
					{
						flag[2]=0;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
				}
			else if(ch==52)
				{
					if(flag[3]==0)
					{
						flag[3]=1;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					else if(flag[3]==1)
					{
						flag[3]=0;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
				}
			else if(ch==53)
				{
					if(flag[4]==0)
					{
						flag[4]=1;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					else if(flag[4]==1)
					{
						flag[4]=0;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
				}
			else if(ch==54)
				{
					if(flag[5]==0)
					{
						flag[5]=1;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					else if(flag[5]==1)
					{
						flag[5]=0;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
				}
			else if(ch==55)
				{
					if(flag[6]==0)
					{
						flag[6]=1;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					else if(flag[6]==1)
					{
						flag[6]=0;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
				}
			else if(ch==56)
				{
					if(flag[7]==0)
					{
						flag[7]=1;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					else if(flag[7]==1)
					{
						flag[7]=0;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
				}
			else if(ch==57)
				{
					if(flag[8]==0)
					{
						flag[8]=1;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}
					else if(flag[8]==1)
					{
						flag[8]=0;
						for(i=0;i<9;i++)
							Check_R(flag[i],i);
					}																					
				}		
	}while(ch!=13);
}
