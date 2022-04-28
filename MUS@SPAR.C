
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
int arr[100][100],row,col,i,j;
printf("Enter the no. of rows and column:");
scanf("%d,%d",&row,&col);
printf("\n");
printf("Enter the element in the matrix:");
printf("\n");
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
scanf("%d",&arr[i][j]);
}
}
printf("\n");
printf("inputted matrix is:");
printf("\n");
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
if(arr[i][j]!=0)
printf("%d %d %d",i+1,j+1,arr[i][j]);
}
printf("\n");
}
getch();
}
