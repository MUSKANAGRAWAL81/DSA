#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct nodetype
{
int coef;
int power;
struct nodetype *next;
}node;
void readPolynomial(node **);
void addPolynomial(node *,node *,node **);
void addNode(node **,int coef,int power);
void printPolynomial(node *);
void main()
{
node *poly1 ,*poly2, *poly3;
int choice ,element ,after,before;
poly1=poly2=poly3=NULL;
clrscr();
printf("\n enter the first polynomial");
readPolynomial(&poly1);
printPolynomial(poly1);
printf("\n enter the second polynomial");
readPolynomial(&poly2);
printPolynomial(poly2);
printf("\n");
addPolynomial(poly1,poly2,&poly3);
printPolynomial(poly3);
getch();

}



void readPolynomial(node **p)
{
int coef ,power;
printf("\n enter the terms in the ascending order of power.\n");
while(1)
{
printf("\n enter the degree of X:");
scanf("%d",&power);
printf("\n enter the cofficient:");
scanf("%d",&coef);
addNode(p,coef,power);
printf("/n Any more terms(Y/N)?:");
if(toupper(getch())=='Y')
break;
}
}
void addNode( node **ptr ,int coef,int power)
{
node *temp;
temp= (node *)malloc(sizeof(node));
temp->coef=coef;
temp->power=power;
if(*ptr == NULL)
{
temp->next = NULL;
*ptr = temp;
}
else
{
temp->next = *ptr;
*ptr =temp;
}
}

void printPolynomial(node *ptr)
{
if(ptr!=NULL)
printf("%dx^%d",ptr->coef,ptr->power);
for(ptr = ptr->next;ptr!=NULL;ptr = ptr->next)
{
if(ptr->coef>0)
printf("+");
if(ptr->power==0)
printf("%d",ptr->coef);
else if (ptr->power==1)
printf("%dx",ptr->coef);
else
printf("%dx^%d",ptr->coef,ptr->power);
}
}

void addPolynomial(node *ptr1,node *ptr2,node **ptr3)
{
int power;
float coef;
while((ptr1!=NULL)&&(ptr2!=NULL))
{
if(ptr1->power>ptr2->power)
{
coef=ptr1->power;
power=ptr1->power;
ptr1=ptr1->next;
}
else if (ptr1->power<ptr2->power)
{
coef=ptr2->coef;
power=ptr2->power;
ptr2=ptr2->next;
}
else
{
coef=ptr1->coef+ptr2->coef;
power=ptr1->power;
ptr1=ptr1->next;
ptr2=ptr2->next;
}
if(coef!=0)
addNode(ptr3,coef,power);
}
if(ptr1==NULL)
{
for(; ptr2!=NULL;ptr2=ptr2->next)
addNode(ptr3,ptr2->coef,ptr2->power);
}
else if (ptr2==NULL)
{
for(; ptr1!=NULL;ptr1=ptr1->next)
addNode(ptr3,ptr1->coef,ptr1->power);
}
}
