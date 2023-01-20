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

void gotoxyT(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
struct Node* readLinkedList(char filename[]);
struct Node {
    int Stock;
    char Food[100];
    int price;
    struct Node* next;
};

struct Node* head;


struct billA{
	char fName[100];
	int fPrice;
	int qty;
}billA_obj[30];
// Function to insert a new node at the front of the list
void insert(int stock,char food[],int price) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->Stock = stock;
    temp->price = price;
    strcpy(temp->Food,food);
	//temp->stcpy(Food,food);
    temp->next = head;
    head = temp;
}

void writeLinkedList(struct Node* head){
    
    struct Node* temp = head;
    
    FILE* file;
    file = fopen ("Menu.txt", "w");
    
    
    // writing all the nodes of the linked list to the file
    while(temp!=NULL)
    {
        fwrite(temp, sizeof(struct Node), 1, file);
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
int checkStock(struct Node* head,int bill_no){
	int ch,k=0,amt;
   scanf("%d",&ch);
   if(ch==80)
   	return;
   if(head==NULL) {
      printf("Linked List not initialized");
      return 0;
   } 
   struct Node* current1 = head;
   
   while(current1!=NULL) {
     if(k==ch-1){
      	printf("Traversing %d    %d",k,ch); 
        printf("Stocked changed of %s\n",current1->Food);
        printf("Current Stock %d \n",current1->Stock);
        printf("How many Plates of %s for the order? ",current1->Food);
        scanf("%d",&amt);
        if(current1->Stock>=amt)
        {
        	current1->Stock=current1->Stock-amt;
        	strcpy(billA_obj[bill_no].fName,current1->Food);
        	billA_obj[bill_no].fPrice=current1->price;
        	billA_obj[bill_no].qty=amt;
        	bill_no++;
		}
         	
        else
        	printf("Not Enough Stock for the food!!");       
		printf("New Stock: %d  ",current1->Stock);
		writeLinkedList(head);
         return bill_no;
      }     
      k++;
      current1 = current1->next;
   }
   
   printf(" does not exist in the list\n");
}

// Function to print the list
int printList(struct Node* head,int bill_no) {
	system("cls");
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	int i=0,j=1,Color=1,x1=45,y1=4,x2=99,y2=4;
    struct Node* temp = head;
    gotoxyT(0,1);
	for(i=0;i<100;i++)
	{
		printf("%c",205);
	}
	gotoxyT(0,2);
	printf("%c",186);
	gotoxyT(45,2);
	printf("What do you want to order?");
	gotoxyT(x2,2);
	printf("%c",186);
	gotoxyT(0,3);
	for(i=0;i<100;i++)
		printf("%c",205);
    while(temp != NULL) {
    	SetConsoleTextAttribute(color, Color);    	
		gotoxyT(0,y1);
		printf("%c",186);
		gotoxyT(x2,y1);
		printf("%c",186);
    	gotoxyT(x1,y1);
		printf("%d) %s:    %d \n",j, temp->Food,temp->price);		
        temp = temp->next;
        y1++;
        i++;
        j++;
        if(i%10==0)
			Color++;
    }
    gotoxyT(0,y1);
    for(i=0;i<100;i++)
	{
		printf("%c",205);
	}
	bill_no=checkStock(readLinkedList("Menu.txt"),bill_no);	
	return bill_no;
}


struct Node* readLinkedList(char filename[]){
    
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));;
    struct Node* head; // points to the first node of the linked list in the file
    struct Node* last; // points to the last node of the linked list in the file
    last = head = NULL;
    
    FILE* file;
    file = fopen (filename, "r");
    
    
    // reading nodes from the file
    // nodes are read in the same order as they were stored
    // we are using the data stored in the file to create a new linked list
    while(fread(temp, sizeof(struct Node), 1, file))
    {
        
        if(head==NULL)
        {
            head = last = (struct Node *)malloc(sizeof(struct Node));
        }
        else
        {
            last->next = (struct Node *)malloc(sizeof(struct Node));
            last = last->next;
        }
        last->Stock = temp->Stock;
        last->price = temp->price;
        strcpy(last->Food, temp->Food);
        last->next = NULL;
        
    }
    
    fclose(file);
    
    return head;
    
}


void update_data(char food[]) {
	int newval;
   
   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   struct Node* current = head;
   while(current->next!=NULL) {
      if(strcmp(current->Food,food)==0 ){
         printf("Initial Amount=%d change to =",current->price);
         scanf("%d",&newval);
         current->price=newval;
         return;
      }
      
      current = current->next;
   }
   
   printf(" does not exist in the list\n");
}

void deleteNode(char food[]) {
    int newval;

   if(head==NULL) {
      printf("Linked List not initialized");
      return;
   } 
    struct Node* prev=NULL;
      struct Node* current = head;
   while(current->next!=NULL) {
      if(strcmp(current->Food,food)==0 ){
            prev->next=current->next;
            printf("Deleted");
         return;
      }
      prev=current;
      current = current->next;
   }

   printf(" does not exist in the list\n");
}

int viewMenu(){
	int i;
	FILE *file1;

    // Open the file in append mode
    file1 = fopen("bill.txt", "a");
    if (file1 == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the string to the file
   // fprintf(file1, "%s\n", string);

    // Close the file
    


	char ch;
	int bill_no=0;
	float total=0;
	do{
		bill_no=printList(readLinkedList("Menu.txt"),bill_no); 
		if(bill_no==60)
			return;
		printf("Do you want more orders? (Y/N): ");
		ch=getch();
	}while(ch!='n');
	
	

    

  // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);
//printf( "%s\n",dt);
	fprintf(file1, "%s\n",dt);

   printf("Your Total Bill is: \n");
   
   for(i;i<bill_no;i++)
   {
   		printf("Item: %s	Quantity: %d	Total: %f\n",billA_obj[i].fName,billA_obj[i].qty,(float)billA_obj[i].fPrice*(float)billA_obj[i].qty);
   		fprintf(file1,"Item: %s	Quantity: %d	Total: %f\n",billA_obj[i].fName,billA_obj[i].qty,(float)billA_obj[i].fPrice*(float)billA_obj[i].qty);
   		total+=(float)billA_obj[i].fPrice*(float)billA_obj[i].qty;
   		
   }  
   printf("Grand Total %f",total);
   fprintf(file1, "Grand Total: %f\n\n",total);

     
    
 	
    // close file
    fclose(file1);

}
/*int main() {
	char tempfood[100],f[100];
	int tempstock,tempprice;
    head = NULL; // empty list
    for(int i=0;i<6;i++)
    {
    	printf("%d food ",i);
    	scanf("%s",&tempfood);
    	printf("%d stock ",i);
    	scanf("%d",&tempstock);
    	printf("%d price ",i);
    	scanf("%d",&tempprice);
    	insert(tempstock,tempfood,tempprice);
	}
	//insert(2);
   // insert(4);
   // insert(6);
    //insert(8);
    //printList();
    writeLinkedList(head);
    printList(readLinkedList("Menu.txt"));
    printf("Enter food=");
    scanf("%s",&f);
    update_data(f);
    writeLinkedList(head);
    printList(readLinkedList("Menu.txt"));   
    return 0;
}
*/
//Class to declare variables for the contents


void DISP()
{
	
    FILE *filePointer;
    char ch;

    //2
    filePointer = fopen("bill.txt", "r");

    //3
    if (filePointer == NULL)
    {
        printf("File is not available \n");
    }
    else
    {
        //4
        while ((ch = fgetc(filePointer)) != EOF)
        {
            printf("%c", ch);
        }
    }

    //5
    fclose(filePointer);
    getch();
}
