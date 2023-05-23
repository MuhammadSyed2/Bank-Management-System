#include<stdio.h>
#include<string.h>
#define MAX 100

struct North_South_University_Information_Master_Food
{
    char name[100];
    char price[100];
};


typedef struct  North_South_University_Information_Master_Food food;

void search();

int main()
{
    while(1)
    {
    int opt;
    printf("\npress 1 to search:");
    scanf("%d",&opt);
        switch (opt)
        {
            case 1:search();
            break;
            default:
            printf("wrong key");
            printf("\nPRESS ANY KEY TO TRY AGAIN\n");
            break;
        }
    }

}


void search()
{
    int found =1 , i=0 ,index;
    char n[100];
    FILE *r=fopen("Business AID.txt","r");
    system("COLOR 1C");
    printf("Enter a food name or price to search:");
    //getchar();
    gets(n);


    food f[MAX];

      do
   {
        fflush(stdin);
        fgets(f[i].name,100, r);
        fgets(f[i].price,100, r);
        int x,y;
        x=strlen(f[i].name);
        y=strlen(f[i].price);
        f[i].name[x-1]='\0';
        f[i].price[y-1]='\0';


        if(strcmp(n,f[i].name)==0)
        {
            index=i;
            found=0;
        }
        else if(strcmp(n,f[i].price)==0)
        {
           //printInfo(f[i]);
   fflush(stdin);
   printf("Name: ");
   puts(f[i].name);
   fflush(stdin);
   printf("Price:");
   puts(f[i].price);
           found=2;
        }

        i++;
    }while(!feof(r));
    if(found==1)
    {
        printf("\nNot found\n");
    }
    else if(found==0)
    {
       //printInfo(f[index]);
       fflush(stdin);
   printf("Name: ");
   puts(f[i].name);
   fflush(stdin);
   printf("Price:");
   puts(f[i].price);
    }
    fclose(r);

}
