#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node* next;
};

struct node* start=NULL;
struct node* create_cll(struct node* );
struct node* display(struct node* );
struct node* insert_beg(struct node* );
struct node* insert_end(struct node* );
struct node* insert_after(struct node* );
struct node* delete_beg(struct node* );
struct node* delete_end(struct node* );

int main()
{
	int choice;
	do
	{
		printf("*****MENU*****\n");
		printf("1.Create Circular Linked List.\n");
		printf("2.Display List.\n");
		printf("3.Insert At Beginning.\n");
		printf("4.Insert At End.\n");
		printf("5.Insert After One Node.\n");
		printf("6.Delete from the Beginning.\n");
		printf("7.Delete from the End.\n");
		printf("8.Exit.");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				start=create_cll(start);
				printf("Circular Linked List is Created.\n");
				break;
			case 2:
				start=display(start);
				break;
			case 3:
				start=insert_beg(start);
				printf("Value inserted successfully.\n");
				break;
			case 4:
				start=insert_end(start);
				printf("Value inserted successfully at end.\n");
				break;
			case 5:
				start=insert_after(start);
				printf("Value inserted after one node successfully.\n");
				break;
			case 6:
				start=delete_beg(start);
				printf("Delete from the beginning is successfully  done.\n");
				break;
			case 7:
				start=delete_end(start);
				printf("Delete from the end is successfully done.\n");
				break;
			case 8:
				exit(0);
			default:
				printf("Invalid Choice!!!\n");


		}
	}while(choice!=8);
	return 0;
}
struct node* create_cll(struct node* start)
{
	struct node* newnode, *ptr;
	int num;
	printf("Enter value :");
	scanf("%d",&num);
	printf("Enter -1 to end\n");
	while(num!=-1)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=num;
		if(start==NULL)
		{
			newnode->next=newnode;
			start=newnode;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				ptr=ptr->next;
				
			}
			ptr->next=newnode;
			newnode->next=start;
		}
		printf("Enter value: ");
		scanf("%d",&num);
	}
	return start;
}

struct node*  display(struct node* start)
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("The linked list is empty.\n");
	}
	else
	{
		ptr=start;
		while(ptr->next!=start)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->next;
		}
		printf("\t%d",ptr->data);
		printf("\n");
		
	}
	return start;
}
struct node* insert_beg(struct node* start)
{
	struct node* newnode, *ptr;
	int num;
	printf("Enter a value: ");
	scanf("%d",&num);
	newnode=(struct node* )malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=start;
	start=newnode;
	return start;
}

struct node* insert_end(struct node* start)
{
	struct node* newnode, *ptr;
	int num;
	printf("Enter a value: ");
	scanf("%d",&num);
	newnode=(struct node* )malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->next=start;
	return start;
}

struct node* insert_after(struct node* start)
{
	struct node* newnode, *ptr;
	int num,value;
	printf("Enter the number to be inserted: ");
	scanf("%d",&num);
	printf("\nEnter the value after which you want to be inserted: ");
	scanf("%d",&value);
	ptr=start;
	do
	{
		if(ptr->data==value)
		{
			newnode=(struct node* )malloc(sizeof(struct node));
			newnode->data=num;
			newnode->next=ptr->next;
			ptr->next=newnode;
			return start;
		}
		ptr=ptr->next;
	}while(ptr!=start);
	
	printf("Value not found.\n");
	return start;
}

struct node* delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=start->next;
	free(start);
	start=ptr->next;
	return start;
}

struct node* delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr=start;

	while(ptr->next!=start)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
	return start;
}
