#include<stdio.h>
#include<string.h>

struct account
{
    char name[100];
    char b[4];
    char NID[20];
    char Nname[100];
    int num;
    char x[20];
};

typedef struct account acc;
void newaccount();
void checkdetail();
//void updateinfo();
//void remove();
//void transact();
void view();


int main()
{
    int n;
    printf("\t\t\t BANK MANAGEMENT SYSTEM\n");
    printf("\n1.Open New Account \n\n2.Check Details of an Existing Account \n\n3.Update Information in an Existing Account \n\n4.Remove Account \n\n5.Transaction \n\n6.View List of Customers \n\n7.Exit\n\n\n");
    printf("Enter your choice: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1: newaccount();
                break;
        case 2: checkdetail();
                break;
        //case 3: updateinfo();
        //        break;
        //case 4: remove();
        //        break;
        //case 5: transact();
        //        break;
        case 6: view();
                break;
        //case 7: return 0;
        default: printf("Invalid input!");
    }
}

void newaccount()
{
    FILE *fp,*fp1,*fp2;
    fp=fopen("Bank account.txt","a");
    fp1=fopen("Bank account (v).txt","a");
    fp2=fopen("Bank account (s).txt","a");
    acc a;
    fflush(stdin);
    printf("Enter name: ");
    gets(a.name);
    fflush(stdin);
    printf("Enter account number: ");
    gets(a.b);
    fflush(stdin);
    printf("Enter national id no.: ");
    gets(a.NID);
    fflush(stdin);
    printf("Enter name of the nominator: ");
    gets(a.Nname);
    fflush(stdin);
    printf("Enter account number of the nominator: ");
    scanf("%d",&a.num);
    fflush(stdin);
    printf("Enter amount of money to deposit: ");
    gets(a.x);
    fprintf(fp,"Name: %s \nAccount no.: %s \nNational id no.: %s \nNominator name: %s \nNominator account no.: %d \nMoney: %s \n\n",a.name,a.b,a.NID,a.Nname,a.num,a.x);
    fprintf(fp1,"Name: %s \nAccount no.: %s \nMoney: %s \n\n",a.name,a.b,a.x);
    fprintf(fp2,"%s\n%s\n\n",a.name,a.b);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}

void view()
{
    FILE *fp;
    char info[100];
    fp=fopen("Bank account (v).txt","r");
    char i=0;
    do
    {
        fgets(info,100,fp);
        puts(info);
        i++;
    }while(!feof(fp));

    fclose(fp);
}

void checkdetail()
{
    int found =1 , i=0 ,index;
    char n[100];
    FILE *fp=fopen("Bank account (s).txt","r");
    printf("\nEnter name or account number to search:");
    getchar();
    gets(n);
    acc f[100];
    do
    {
        fflush(stdin);
        fgets(f[i].name, 100, fp);
        fgets(f[i].b, 100, fp);
        fgets(f[i].x, 100, fp);
        int x,y,z;
        x=strlen(f[i].name);
        y=strlen(f[i].b);
        z=strlen(f[i].x);
        f[i].name[x-1]='\0';
        f[i].b[y-1]='\0';
        f[i].x[z-1]='\0';

        if(strcmp(n,f[i].name)==0)
        {
            fflush(stdin);
            printf("Name: ");
            puts(f[i].name);
            printf("Account number: ");
            puts(f[i].b);
            printf("Money: ");
            puts(f[i].x);
            found=0;
        }
        else if(strcmp(n,f[i].b)==0)
        {
            fflush(stdin);
            printf("Name: ");
            puts(f[i].name);
            printf("Account number: ");
            puts(f[i].b);
            printf("Money: ");
            puts(f[i].x);
            found=2;
        }
        i++;
    }while(!feof(fp));
    if(found==1)
    {
        printf("\nNot found\n");
    }
}

void transact()
{

}
