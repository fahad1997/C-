#include<stdlib.h>
#include<stdio.h>
#define size 5
void insertion();
void deletion();
void display();

int front=-1,rare=-1;
int queue[size];
int n;
int main()
{
    int ch;
    printf("\n1.start\n0.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    while(ch!=0)
    {
    printf("\n1.Insert\n2.Delete\n3.Display\n0.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
          printf("Insert a number:");
          scanf("%d",&n);
          insertion();
          break;
       case 2:
        deletion();
        break;
       case 3:
        display();
        break;
    }
    }
}

void insertion()
{
    if(front==0 && rare==size-1 || front==rare+1)
    {
        printf("The queue is full");
        return;
    }
    else if(rare==-1)
    {
        rare++;
        front++;
    }
    else if(front>0 && rare==size-1)
    {
        rare=0;
    }
    else
    {
        rare++;
    }
    queue[rare]=n;
}

void deletion()
{
    if(front==-1)
    {
        printf("The queue is empty");
    }
    else
    {
        printf("\n%d has been deleted",queue[front]);
        if(front==rare)
        {
            front=-1;
            rare=-1;
        }
        else
        {
            if(front==size-1)
            {
                front=0;
            }
            else
            {
                front++;
            }
        }
    }
}

void display()
{
    int i;
    if(front>rare)
    {
       for (i=0;i<=rare;i++)
        {
            printf("%d  ",queue[i]);
        }
        for (i=front;i<size;i++)
        {
            printf("%d  ",queue[i]);
        }
    }
    else
    {
        for(i=front;i<=rare;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}
