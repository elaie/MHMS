#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
void Menu_PutData();
void Menu_GetData();
void M_Put_Price();
void Main_Menu_Order();
void M_Get_Data();
void DISP();
int count[40];

void gotoxyE(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
struct Node* readLinkedList(char filename[]);
struct Node2 {
    int eid;
    char name[100];
    float salary;
    struct Node* next;
};

struct Node* head2;


// Function to insert a new Node2 at the front of the list
void insert2(int eid,char name[],float salary) {
    struct Node2* temp = (struct Node2*)malloc(sizeof(struct Node2));
    temp->eid = eid;
    temp->salary = salary;
    strcpy(temp->name,name);
	//temp->stcpy(Food,food);
    temp->next = head2;
    head2 = temp;
}

void writeLinkedList2(struct Node2* head2){
    
    struct Node2* temp = head2;
    
    FILE* file;
    file = fopen ("Employee.txt", "w");
    
    
    // writing all the Node2s of the linked list to the file
    while(temp!=NULL)
    {
        fwrite(temp, sizeof(struct Node2), 1, file);
        temp = temp->next;
    }
    
    if(fwrite != 0)
    {
        printf("Item Successfully Added!\n");
    }
       else
    {
           printf("Error While Writing\n");
    }
    
    fclose(file);
    
}

// Function to print the list
void printEList(struct Node2* head2) {
	system("cls");
    struct Node2* temp = head2;
    while(temp != NULL) {
    	
		printf("UID: %d)\nName: %s:\n",temp->eid, temp->name);	
		printf("Salary: %f\n\n",temp->salary);
        temp = temp->next;
    }
}


struct Node2* readLinkedList2(char filename[]){
    
    struct Node2* temp = (struct Node2 *)malloc(sizeof(struct Node2));;
    struct Node2* head2; // points to the first Node2 of the linked list in the file
    struct Node2* last; // points to the last Node2 of the linked list in the file
    last = head2 = NULL;
    
    FILE* file;
    file = fopen (filename, "r");
    
    
    // reading Node2s from the file
    // Node2s are read in the same order as they were stored
    // we are using the data stored in the file to create a new linked list
    while(fread(temp, sizeof(struct Node2), 1, file))
    {
        
        if(head2==NULL)
        {
            head2 = last = (struct Node2 *)malloc(sizeof(struct Node2));
        }
        else
        {
            last->next = (struct Node2 *)malloc(sizeof(struct Node2));
            last = last->next;
        }
        last->eid = temp->eid;
        last->salary = temp->salary;
        strcpy(last->name, temp->name);
        last->next = NULL;
        
    }
    
    fclose(file);
    
    return head2;
    
}


void update_data1(char name[]) {
	int newval;
   
   if(head2==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   struct Node2* current = head2;
   while(current->next!=NULL) {
      if(strcmp(current->name,name)==0 ){
         printf("Initial Amount=%d change to =",current->salary);
         scanf("%d",&newval);
         current->salary=newval;
         return;
      }
      
      current = current->next;
   }
   
   printf(" does not exist in the list\n");
}

void deleteNode2(char name[]) {

    int newval;

   if(head2==NULL) {
      printf("Linked List not initialized");
      return;
   } 
    struct Node2* prev=NULL;
      struct Node2* current = head2;
   while(current->next!=NULL) {
      if(strcmp(current->name,name)==0 ){
            prev->next=current->next;
            printf("Deleted");
         return;
      }
      prev=current;
      current = current->next;
   }

   printf(" does not exist in the list\n");
}
void update_salary() {
	int eeid;
	system("cls");
    struct Node2* temp = head2;
    while(temp != NULL) {
		printf("UID: %d)\nName: %s:\n",temp->eid, temp->name);	
		printf("Salary: %f\n\n",temp->salary);	
        temp = temp->next;
    }
	printf("Enter eid to modify the Salary: ");
	scanf("%d",&eeid);
	float newval;
   	
   if(head2==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   struct Node2* current = head2;
   while(current->next!=NULL) {
      if(current->eid==eeid ){
         printf("Initial Amount=%f change to =",current->salary);
         scanf("%f",&newval);
         current->salary=newval;
         writeLinkedList2(current);
         return;
      }
      
      current = current->next;
   }
   
   printf(" does not exist in the list\n");
}

