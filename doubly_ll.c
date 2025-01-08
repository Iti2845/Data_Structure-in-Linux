#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	struct node *next;
	int data;
};

struct node *start=NULL;
struct node *create_dll(struct node* );
struct node *insert_beg(struct node* );
struct node *insert_end(struct node* );
struct node *insert_before(struct node* );
struct node *insert_after(struct node* );

int main()
{
	int choice;
	do
	{
		printf("*****MENU*****\n");
		printf("1.Create Doubly Linked List.\n");
		printf("2.Insert Element at Beginning.\n");
	       printf("3.Insert Element at End.\n");
	        printf("4.Insert Elements before node.\n");
		printf("5.Insert elements after node.\n");
       		printf("6.END.\n");
 		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				start=create_dll(start);
	       			printf("Linked List Create Successfully\n");
				break;
			case 2:
				start=insert_beg(start);
	 			printf("Element inserted succesfuly at the beginning.\n");
				break;
			case 3:
				start=insert_end(start);
				printf("Element insert successfully at the end.\n");
				break;
			case 4:
				start=insert_before(start);
				printf("Eelements insert successfully before one node.\n");
				break;
			case 5:
				start=insert_after(start);
				printf("Elements insert successfully after one node.\n");
				break;
			case 6:
				printf("Exiting!!!\n");
				exit(0);
				break;
			default:
				printf("Invalid Choice\n");			
		}
	}while(choice!=6);
}

struct node *create_dll(struct node *start)
{
	struct node *newnode, *ptr;
	int num;
	printf("Enter a value: ");
	scanf("%d",&num);
	printf("Write -1 to end\n");
	while(num!=-1)
	{
		if(start==NULL)
		{
			newnode->data=num;
			newnode->prev=NULL;
			newnode->next=NULL;
			start=newnode;
		}
		else
		{
			ptr=start;
			newnode=(struct node* )malloc(sizeof(struct node));
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=newnode;
			newnode->prev=ptr;
			newnode->next=NULL;
		}
		printf("Enter a value: ");
		scanf("%d",&num);
		
	}
	return start;
}

struct node *insert_beg(struct node *start)
{
	struct node *newnode;
	int num;
	printf("Enter a value: ");
	scanf("%d",&num);
	newnode=(struct node* )malloc(sizeof(struct node));
	newnode->data=num;
	newnode->next=start;
	newnode->prev=NULL;
	start=newnode;
	return start;
}

struct node *insert_end(struct node *start)
{
	struct node *newnode, *ptr;
	int num;
	printf("Enter a value: ");
	scanf("%d",&num);
	newnode=(struct node* )malloc(sizeof(struct node));
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	newnode->data=num;
	newnode->prev=ptr;
	newnode->next=NULL;
	printf("\n");
	return start;

}

struct node *insert_before(struct node *start)
{
	struct node *newnode, *ptr;
	int num,b_num;
	printf("Enter a value: ");
	scanf("%d",&num);
	printf("\nEnter the number before which inserted: ");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=val)
	{
		ptr=ptr->next;
	}
	newnode->next=ptr;
	newnode->prev=ptr->prev;
	ptr->prev->next=newnode;
	ptr->prev=newnode;
	return start;
}

struct node *insert_after(struct node *start)
{
	struct node *newnode, *ptr;
	int num,a_num;
	printf("Enter a value: ");
	scanf("%d",&num);
	printf("\nEnter the number after which to be inserted: ");
	scanf("%d",&a_num);
	newnode=(struct node* )malloc(sizeof(struct node));
	newnode->data=num;
	ptr=start;
	while(ptr->data!=a_num)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->prev=ptr;
	newnode->next=ptr->next;
	ptr->next->prev=newnode;
	return start;
}

