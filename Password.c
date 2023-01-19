#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

	
void gotoxyP(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//Functions for this file
int P_Get_No();
void P_Put_No(int a);
int Admin_Verification();
void Admin_Register_Pass();	


struct User_Pass
{
	char user[20];
	char pass[20];
}userPass_obj;


//function for User_Pass Structure
void P_Enter()
{
	printf("Enter your username: ");
	scanf("%s",userPass_obj.user);
	printf("Enter your New Password: ");
	scanf("%s",userPass_obj.pass);
}

//function for User_Pass Structure
void U_RE()
{
	printf("Enter your username: ");
	scanf("%s",userPass_obj.user);
	printf("Enter your New Password: ");
	scanf("%s",userPass_obj.pass);
}

//Structure Function to check Password
int check()
{
	int i=0;
	char User[20];
	char Password[20];
	gotoxyP(30,9);
	for(i;i<40;i++)
	{
		printf("%c",205);
	}
		gotoxyP(30,10);
		printf("%c",186);
		printf(" Enter Your Username: ");
		scanf("%s",User);
		gotoxyP(70,10);
		printf("%c",186);
		
		gotoxyP(30,11);
		printf("%c",186);
		printf(" Enter Password: ");
		scanf("%s",Password);
		gotoxyP(70,11);
		printf("%c",186);
	gotoxyP(30,12);
	i=0;
	for(i;i<40;i++)
	{
		printf("%c",205);
	}
	gotoxyP(30,13);
     if(strcmp(userPass_obj.pass,Password)==0 && strcmp(userPass_obj.user,User)==0)
		return 0;
	 else
		return 1;
}

//function for User_Pass Structure to check password
inline int U_Check(char *User,char *Password)
{
	if(strcmp(userPass_obj.pass,Password)==0 && strcmp(userPass_obj.user,User)==0)
	return 0;
}


//Function to change username and password of admin
void Admin_Register_Pass()
{
/*	FILE *file;
	//User_Pass R;
	P_Enter();
	file=fopen("APassword.dat","wb");
	fwrite(userPass_obj,1,sizeof(userPass_obj),file);
	file.close();
*/	
	
	FILE *outfile;
    P_Enter();
    // open file for writing
    outfile = fopen ("APassword.dat", "wb");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }
    
    // write struct to file
    fwrite (&userPass_obj, sizeof(struct User_Pass), 1, outfile);
     
    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
 	
    // close file
    fclose (outfile);
 
}



//Function to Login for admin
int Admin_Verification()
{
	//int i;
	//fstream file;
/*	
	file.open("APassword.dat",ios::binary|ios::in);
	file.read((char *)&R,sizeof(R));
	if (R.check()==0)
		return 0;
	else
		return 1;
	}
	*/
	
	FILE *infile;

  
    // Open APassword.dat for reading
    infile = fopen ("APassword.dat", "rb");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }
     
    // read file contents till end of file
    while(fread(&userPass_obj, sizeof(struct User_Pass), 1, infile))
    {
    if (check()==0)
		return 0;
	else
		return 1;
	}
    // close file
    fclose (infile);
    return 1;
}


//Function to login for User
/*
void User_Register_Pass()
{
	int No=P_Get_No();
	int i;
	fstream file;
	User_Pass R[100];
	file.open("UPassword.dat",ios::binary|ios::app);
	R[No].U_RE();
	file.write((char *)&R[No],sizeof(R[No]));
	file.close();
	P_Put_No(No+1);
	
	FILE *outfile;
     
    // open file for writing
    outfile = fopen ("person.dat", "w+");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }
 
    struct person input1 = {1, "rohan", "sharma"};
    struct person input2 = {2, "mahendra", "dhoni"};
     
    // write struct to file
    fwrite (&input1, sizeof(struct person), 1, outfile);
    fwrite (&input2, sizeof(struct person), 1, outfile);
     
    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
 
    // close file
    fclose (outfile);
}



//Function to Login for user
void User_Verification()
{
	int i,a,count=0;
	char User[20];
	char Password[20];
	fstream file;
	int No=P_Get_No();
	User_Pass R[100];
	file.open("UPassword.dat",ios::binary|ios::in);
		printf("Enter UserName: ");
		scanf("%s",User);
		printf("Enter Passowrd: ");
		scanf("%s",Password);
	for(i=0;i<No;i++)
	{
		file.read((char *)&R[i],sizeof(R[i]));
     	if(R[i].U_Check(User,Password)==0)
			printf("Password Valid");
		else count++;
	}
	if(count==No)
	printf("Password Invalid");
}
*/

//Gets number of student from file and returns the number
int P_Get_No()
{
	/*
	int number;
	//fstream file;
	//file.open("PNumber.txt",ios::in);
	file>>a;
	file.close();
	return a;
	*/
	
	FILE* ptr;
 	int number;
    // Opening file in reading mode
    ptr = fopen("PNumber.txt", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    //printf("content of this file are \n");
 

    number = fgetc(ptr);
    printf("%d", number);
 
 
    // Closing the file
    fclose(ptr);
    return number;
}


//Puts Number of student in file
void P_Put_No(int num)
{
	/*
	fstream file;
	file.open("PNumber.txt",ios::out);
	file<<a;
	file.close();
	*/
	//int num;
	FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("PNumber.txt","w");

   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

   fprintf(fptr,"%d",num);
   fclose(fptr);	
}
