#include<stdio.h>
#include<string.h>
#include<windows.h>
void read_bus_1();
void write_bus_1();
void view_bus_1();
void data_bus_1();
void seat();

struct bus_1
{
    char date[15];
    char first_name[20];
    char last_name[200];
    char mobile[15];
    char leaving_from[15];
    char going_to[15];
    char time[10];
    char coach_type[10];
    char reservation_type[15];
    int price;
    int seat;
};
struct bus_1 root_1[1000];
int i,m,n,l=0,x=0,amount,k=0,j,seat_booked,unavailable[30],a;
char date[15],time[15]="10:30";

int main()
{
    root_1[0].seat=0;
    system("COLOR 3f");
    scanf("%d",&m);
    switch(m)
    {
    case 1:
        data_bus_1();
        break;
    case 2:
        view_bus_1();
        break;
    }
    return 0;
}


void data_bus_1()
{
    read_bus_1();
    printf("how many seat you want:");
    scanf("%d",&amount);
    if(x+amount>1000)
        {
           x=0;
        }
    a=0;
    for(i=x;i<x+amount;i++)
    {
        printf("\n(Format dd-mm-yyyy)  Date:");
        scanf("%s",date);
        strcpy(root_1[i].date,date);
        strcpy(root_1[i].time,time);
        root_1[i].price=1000;
        printf("First Name:");
        scanf("%s",root_1[i].first_name);
        printf("Last Name:");
        scanf("%s",root_1[i].last_name);
        printf("Mobile Number:");
        scanf("%s",root_1[i].mobile);
        seat();
        i=x+a;
        root_1[i].seat=seat_booked;
        write_bus_1();
        a++;
    }
    x=i;
    write_bus_1();
}

void seat()
{
        read_bus_1();
        printf("Seat plan:\n");
        printf("\n");
        printf("\t[DRIVER]\n");
        printf("\n");
        printf("[1]\t[11][21]\n");
        printf("[2]\t[12][22]\n");
        printf("[3]\t[13][23]\n");
        printf("[4]\t[14][24]\n");
        printf("[5]\t[15][25]\n");
        printf("[6]\t[16][26]\n");
        printf("[7]\t[17][27]\n");
        printf("[8]\t[18][28]\n");
        printf("[9]\t[19][29]\n");
        printf("[10]\t[20][30]\n");
        printf("\n\n Seat available:");
        k=0;
        for(j=1;j<=30;j++)
        {
            for(i=0;i<=x+a;i++)
            {
                if(strcmp(date,root_1[i].date)==0 && root_1[i].seat==j)
                {
                    unavailable[k]=j;
                    k++;
                }
            }
        }

       k=0;

       for(j=1;j<=30;j++)
       {
           if(unavailable[k]==j)
             {
                k++;
             }
             else
             {
                printf("%d\t",j);
             }
       }


        printf("\nSeat Number:");
        scanf("%d",&seat_booked);

        for(j=1;j<=30;j++)
          {
              i=0;
              while(i<=x+a)
              {
              if(strcmp(date,root_1[i].date)==0 && root_1[i].seat==seat_booked)
                {
                    printf("The seat is not available...Please try again...\n");
                    printf("\nSeat Number:");
                    scanf("%d",&seat_booked);
                    i=-1;
                    j=1;
                }
              else if(strcmp(date,root_1[i].date)==0 && seat_booked!=root_1[i].seat && seat_booked==j)
                {
                    seat_booked=j;
                }
                i++;
              }
          }
}

void view_bus_1()
{
    read_bus_1();

    for(i=0;i<x;i++)
    {
        printf("\nDate:%s",root_1[i].date);
        printf("\nName:%s",root_1[i].first_name);
        printf("\nName:%s",root_1[i].last_name);
        printf("\ntime:%s",root_1[i].time);
        printf("\nseat:%d",root_1[i].seat);
    }
}

void read_bus_1()
{
    FILE*bus_1;
    bus_1=fopen("bus1.txt","r");
    fread(&root_1,sizeof(root_1),1,bus_1);
    fclose(bus_1);

    FILE*counter;
    counter=fopen("counter.txt","r");
    fread(&x,sizeof(x),1,counter);
    fclose(counter);

    FILE*counter1;
    counter1=fopen("counter1.txt","r");
    fread(&a,sizeof(a),1,counter1);
    fclose(counter1);
}
void write_bus_1()
{
    FILE*bus_1;
    bus_1=fopen("bus1.txt","w");
    fwrite(&root_1,sizeof(root_1),1,bus_1);
    fclose(bus_1);

     FILE*counter;
    counter=fopen("counter.txt","w");
    fwrite(&x,sizeof(x),1,counter);
    fclose(counter);

    FILE*counter1;
    counter1=fopen("counter1.txt","w");
    fwrite(&a,sizeof(a),1,counter1);
    fclose(counter1);
}
