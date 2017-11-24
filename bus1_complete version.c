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
int i,n=0,m,l=0,x=0,amount,k=0,j,seat_booked,unavailable[30],available[30],temp;
char date[15],time[15]="10:30";
int main()
{
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
    root_1[0].seat=0;
    read_bus_1();
    printf("how many seat you want:");
    scanf("%d",&amount);
    if(x>1000)
        {
           x=0;
        }

    for(i=x;i<x+amount;i++)
    {
        printf("(Format dd-mm-yyyy)  Date:");
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
        printf("Seat plan:\n");
        printf("[1]\t\t[11][21]\n");
        printf("[2]\t\t[12][22]\n");
        printf("[3]\t\t[13][23]\n");
        printf("[4]\t\t[14][24]\n");
        printf("[5]\t\t[15][25]\n");
        printf("[6]\t\t[16][26]\n");
        printf("[7]\t\t[17][27]\n");
        printf("[8]\t\t[18][28]\n");
        printf("[9]\t\t[19][29]\n");
        printf("[10]\t\t[20][30]\n");
        printf("\n\n Seat available:");
        k=0;
        j=1;
                for(j=1;j<=30;j++)
                {
                i=0;
                while(i<x+amount)
                {
                if(strcmp(date,root_1[i].date)==0 && strcmp(time,root_1[i].time)==0 && root_1[i].seat==j)
                {
                      unavailable[k]=j;
                      n++;
                      k++;
                }
                i++;
                }
                }
               /* for(k=0;k<=n;k++)
                {
                    if(unavailable[k]>unavailable[k+1])
                    {
                        temp=unavailable[k];
                        unavailable[k]=unavailable[k+1];
                        unavailable[k+1]=temp;
                    }
                }*/

                for(j=1;j<=30;j++)
                {
                    available[j]=j;
                }
                    for(k=0;k<=n;k++)
                    {
                        for(j=1;j<=30;j++)
                        {
                        if(j==unavailable[k])
                        {
                            for(j=1;j<=30-l;j++)
                            {
                              available[j]=available[j+1];
                            }
                            l++;
                        }
                        }
                    }
              for(j=1;j<=30-l;j++)
              {
                  printf("%d\t",available[j]);
              }
        seat();
        read_bus_1();
        root_1[i].seat=seat_booked;
        write_bus_1();
    }
    x=i+1;
    write_bus_1();
}

void view_bus_1()
{
    read_bus_1();
    x=1000-x;
    for(i=0;i<1000-x;i++)
    {
        printf("\nDate:%s",root_1[i].date);
        printf("\nName:%s",root_1[i].first_name);
        printf("\nName:%s",root_1[i].last_name);
        printf("\ntime:%s",root_1[i].time);
        printf("\nseat:%d",root_1[i].seat);
    }
}

void seat()
{
    root_1[0].seat=0;
    read_bus_1();
    printf("\nSeat Number:");
    scanf("%d",&seat_booked);
    i=0;
        for(j=1;j<=30;j++)
            {
              while(i<x+amount)
              {
              if(strcmp(date,root_1[i].date)==0 && strcmp(time,root_1[i].time)==0 && root_1[i].seat==seat_booked)
                {
                    printf("The seat is not available...Please try again...\n");
                    seat();
                }
              else if(strcmp(date,root_1[i].date)==0 && strcmp(time,root_1[i].time)==0 && seat_booked!=root_1[i].seat && seat_booked==j)
                {
                    seat_booked=j;
                    write_bus_1();
                }
                i++;
              }
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
    fread(&seat_booked,sizeof(seat_booked),1,counter1);
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
    fwrite(&seat_booked,sizeof(seat_booked),1,counter1);
    fclose(counter1);
}
