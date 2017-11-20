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
int i,seat,s,m,x=0,amount,k=0,j,seat_available[30],seat_booked;
char date[15],time[15];
int main()
{
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
    if(x>1000)
        {
           x=0;
        }

    for(i=x;i<=x+s;i++)
    {
        printf("(Format dd-mm-yyyy)  Date:");
        scanf("%s",root_1[i].date);
        printf("First Name:");
        scanf("%s",root_1[i].first_name);
        printf("Last Name:");
        scanf("%s",root_1[i].last_name);
        printf("Mobile Number:");
        scanf("%s",root_1[i].mobile);
        printf("\n\n Seat available:");
        for(j=1;j<=30;j++)
        {
            for(i=0;i<1000-x;i++)
            {
                if(strcmp(date,root_1[i].date)==0 && strcmp(time,root_1[i].time)==0 && seat==j)
                {
                    printf(" \t");
                }
                else
                    {
                      printf("%d\t",seat_available[j]);
                    }
            }
        }
        seat();
        root_1[i].seat=seat_booked;
        x=i+1;
        write_bus_1();
    }
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
        printf("Seat Number:");
        scanf("%d",&seat_booked);
        for(j=1;j<=30;j++)
        {
            for(i=0;i<1000-x;i++)
            {
                if(strcmp(date,root_1[i].date)==0 && strcmp(time,root_1[i].time)==0 && seat_booked==j)
                {
                    printf("The seat is not available...Please try again...");
                    seat();
                }
                else
                {
                    break;
                }
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

    FILE*count1;
    count1=fopen("counter1.txt","r");
    fread(&k,sizeof(k),1,count1);
    fclose(count1);
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

    FILE*count1;
    count1=fopen("counter1.txt","w");
    fwrite(&k,sizeof(k),1,count1);
    fclose(count1);
}
