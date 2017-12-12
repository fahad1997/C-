#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void main()
{
    struct node
    {
        int num;
        int *ptr;
    };
    typedef struct node NODE;
    NODE *head , *first,*temp=0;
    int count=0;
    int choice=1;
    first=0;
    while(choice)
    {
        head=(NODE*)malloc(sizeof(NODE));
        printf("Enter Element\n");
        scanf("%d",&head->num);
        if(first !=0)
        {
            temp->ptr=head;
            temp=head;
        }
        else
            {
                first=temp=head;
            }
    fflush(stdin);
    printf("to continue press 1 or to stop press 0\n");
    scanf("%d",&choice);
}
temp->ptr =0;
temp=first;
printf("Status of the list:\n");
while(temp !=0)
{
  printf("[%d]   [%d]",temp,temp->num);
count++;
temp=temp->ptr;

}
printf("[NULL]\n");
printf("No. of nodes in the list is %d\n",count);
}
