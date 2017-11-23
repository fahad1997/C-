#include<stdio.h>
#include<string.h>
#include<windows.h>
void read();
void write();

struct info
{
  char name[20];
  char mobile[15];
  int age;
};
struct info a[10];
int i,x=0,n,m,j=0;
char name;
int main()
{
  system("COLOR 3f");
  printf("Enter 1 for update info. 2 for delete info 3 for watch info. :");
  scanf("%d",&m);
switch(m)
{
   case 1:
    read();
    printf("How many info. you want to input:");
    scanf("%d",&n);
    for(i=x;i<n+x;i++)
    {
        printf("Name:");
        scanf("%s",a[i].name);
        printf("Mobile:");
        scanf("%s",a[i].mobile);
        printf("Age:");
        scanf("%d",&a[i].age);
        write();
    }
    x=i+1;
    write();
    break;

   case 2:
    read();
    for(i=0;i<x-1;i++)
    {
        printf("\nName:%s",a[i].name);
        printf("\nMobile:%s",a[i].mobile);
        printf("\nAge:%d",a[i].age);
    }
    printf("\nEnter the name you want to delete:");
    scanf("%s",name);
    for(i=0;i<x-1;i++)
    {
        if(strcmp(name,a[i].name)==0)
        {
            for(i=j;i<x-1;i++)
            {
            strcpy(a[i].name,a[i+1].name);
            strcpy(a[i].mobile,a[i+1].mobile);
            a[i].age=a[i+1].age;
            write();
            }
             x=x-1;
             write();
        }
        j++;
    }
    system("cls");
    read();
    for(i=0;i<x-1;i++)
    {
        printf("\nName:%s",a[i].name);
        printf("\nMobile:%s",a[i].mobile);
        printf("\nAge:%d",a[i].age);
    }
    break;
   case 3:
    read();
    for(i=0;i<x-1;i++)
    {
        printf("\nName:%s",a[i].name);
        printf("\nMobile:%s",a[i].mobile);
        printf("\nAge:%d",a[i].age);
    }
     break;
    default:
    printf("the number is incorrect please try again....");
    main();
}
return 0;
}


void read()
{
    FILE*counter;
    counter=fopen("counter.txt","r");
    fread(&a,sizeof(a),1,counter);
    fclose(counter);

    FILE*counter1;
    counter1=fopen("counter1.txt","r");
    fread(&x,sizeof(x),1,counter1);
    fclose(counter1);
}

void write()
{
    FILE*counter;
    counter=fopen("counter.txt","w");
    fwrite(&a,sizeof(a),1,counter);
    fclose(counter);

    FILE*counter1;
    counter1=fopen("counter1.txt","w");
    fwrite(&x,sizeof(x),1,counter1);
    fclose(counter1);
}
