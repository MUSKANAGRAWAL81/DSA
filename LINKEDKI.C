#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
// define structure
typedef struct nodetype
{
int info;
struct nodetype*next;
}node;
// function prototype
void createEmptyList(node **head);
void TraverseInOrder(node *head);
void InsertAtBegining(node **head,int item);
void traverseInReverse(node *head);
void InsertAtEnd(node **head,int item);
void InsertAfterElement(node *head,int item,int after);
node *Search(node *head,int element);
void deleteFromBegining(node **head);
void deleteFromEnd(node **head);
void deleteAfterElement(node *head,int after);
void reverseList(node **head);
void deleteList(node **head);
node *SearchInSorted(node *head, int item);
void main()
{
node*head;
int Choice,element,after,res;
clrscr();
createEmptyList(&head);
while(1)
{
printf("Operations Available are\n");
printf("1. Insert at begining\n");
printf("2. Traverse in order\n");
printf("3.Traverse in reverse\n");
printf("4. insert at the end\n");
printf("5.insert after the postion\n");
printf("6.search any element\n");
printf("7.delete element from begining\n");
printf("8. delete element from end\n");
printf("9.delete after the postion\n");
printf("10.reverse the linked list\n");
printf("11. delete the whole linked list\n");
printf("12.search an element in asorted linked list\n");
printf("enter the choice:\n" );
scanf("%d",&Choice);
switch(Choice)
{
case 1: printf("\nEnter the element");
scanf("%d",&element);
InsertAtBegining(&head,element);
break;
case 2: if(head==NULL)
			   printf("\n List is empty");
		else

		TraverseInOrder(head);
		printf("\n Pass any key to continue");
		getch();
		break;
case 3: if(head==NULL)
			  printf("\n List is empty");
		else
		   traverseInReverse(head);
		   printf("\npass any key to continue");
		   getch();
		   break;
case 4: printf("enter the element to be insert:\n");
		scanf("%d",&element);
		InsertAtEnd(&head, element);
		break;
case 5: printf("enter the position\n");
		scanf("%d",&after);
		printf("enter the element");
		scanf("%d",&element);
		InsertAfterElement(head ,element,after);
		break;
case 6: printf("Enter the element\n");
		scanf("%d",&element);
		res=(int)Search(head, element);
		printf("%d\n",res);
		break;
case 7: deleteFromBegining( &head);
		   printf("Element deleted\n");
		   printf("press any key to continue\n");
		   getch();
		   break;
case 8: deleteFromEnd(&head);
		   printf("element deleted\n");
		   printf("press any key to continue\n");
		   getch();
		   break;
case 9: printf("enter the postion:\n");
		scanf("%d",&after);
		deleteAfterElement(head,after);
		printf("press any key to continue:\n");
		getch();
		break;
case 10:reverseList(&head);
		printf("linkelist reversed.\n");
		printf("press any key to continue:\n");
		getch();
		break;
case 11: deleteList(&head);
		 printf("Linked list deleted\n");
		 printf("press any key to continue\n");
		 getch();
		 break;
case 12: printf("enter the element to be searched:\n");
		 scanf("%d",&element);
		 res =(int)SearchInSorted(head,element);
		 printf("%d\n",res);
		 break;
default: exit(0);
		}
	  }

}
void createEmptyList(node **head )
{
*head=NULL;
}
void InsertAtBegining(node **head,int item)
{
node *ptr;
ptr= (node*)malloc(sizeof(node));
ptr->info=item;
if(*head==NULL)
ptr->next=NULL;
else
ptr->next= *head;
*head= ptr;

}
void TraverseInOrder(node *head)
{
while(head!=NULL)
{
printf("\n %d",head->info);
head= head->next;
}
}

void traverseInReverse(node *head)
{
if(head->next!=NULL)
traverseInReverse(head->next);
printf("%d",head->info);
}
void InsertAtEnd(node **head, int item)
{
node *ptr,*loc;
ptr =(node *)malloc(sizeof(node));
ptr->info=item;
ptr->next=NULL;
if(*head==NULL)
{
*head=ptr;
}
else{
loc = *head;
while(loc->next!=NULL)
{
loc=loc->next;
}
loc->next=ptr;
}
}
void InsertAfterElement(node *head, int item, int after)
{
node *ptr,*loc;
loc=Search(head,after);
if(loc==(node *)NULL)
return;
else
{
ptr=(node*)malloc(sizeof(node));
ptr->info=item;
ptr->next=loc->next;
loc->next=ptr;
}}

node *Search(node *head ,int element)
{
while((head!=NULL)&&(head->info!= element))
head=head->next;
return head;
}
void deleteFromBegining(node **head)
{
node *ptr;
if(*head==NULL)
return;
else
{
ptr= *head;
*head =(*head)->next;
free(ptr);
}
}
void deleteFromEnd(node **head)
{
node *ptr,*loc;
if(*head==NULL)
return;
else if((*head)->next== NULL)
{
ptr =*head;
*head=NULL;
free(ptr);
}
else
{
loc=*head;
ptr=(*head)->next;
while(ptr->next!=NULL)
{
loc=ptr;
ptr=ptr->next;
}
loc->next=NULL;
free(ptr);
}
}
void deleteAfterElement(node *head,int after)
{
node *ptr,*loc;
loc=Search(head,after);
if(loc==(node*)NULL)
return;

ptr=loc->next;
loc->next=ptr->next;
free(ptr);
}
void reverseList(node **head)
{
node *previousNode, *currentNode, *nextNode;
currentNode=*head;
nextNode=currentNode->next;
previousNode=NULL;
currentNode->next=NULL;
while(nextNode!=NULL)
{
previousNode=currentNode;
currentNode=nextNode;
nextNode=currentNode->next;
currentNode->next=previousNode;
}
*head=currentNode;
}
void deleteList(node **head)
{
node *ptr;
while(*head!=NULL)
{
ptr= *head;
*head =(*head)->next;
free(ptr);
}
}
node *SearchInSorted(node *head,int item)
{
while(head!=NULL)
{
if(item<head->info)
return NULL;
else if(head->info==item)
return head;
else
head=head->next;
}
return NULL;
}



