/*
Welcome to FPE(Format Preserving Encryption)
Note:Clear the String
    :Take the input file and output the file
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char encr[100];
void Encrpyt();
void Decrpyt();

int len_count(int x){
    int i=0;
    while(x>0)
    {
        x=x/10;
        i++;
    }
    return i;
}
int main()
{
    int l=1,x;
    while(l == 1)
    {
        printf("\n\t\tWelcome to FPE(Format Preserving Encryption)\n");
        printf("1.Want to Encrypt.\n");
        printf("2.Want to Decrypt.\n");
        printf("3.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d",&x);
        switch(x)
        {
        case 1:
            Encrpyt();
            break;
        case 2:
            Decrpyt();
            break;
        case 3:
            l=0;
            break;
        default:
            printf("Enter the Valid Number.\n");
        }
    }
}
void Encrpyt()
{
    int i,d,n,x=0,t=0,r,j=0,l,n1;
    int v;
    char pass[12];
    char s[100],gg;
    printf("Choose Your file:");
    scanf("%s",s);
    l=strlen(s);
    while(x!=5)
    {
        n = rand();
        x = len_count(n);
    }
    n1=n;
    r=n%10;
    while(j!=r)
    {
        gg=s[l-1];
        for(i=l-1;i>=0;i--)
        {
            if(i==(l-1))
                s[i]=s[0];
            else
                s[i+1]=s[i];
        }
        s[0]=gg;
        j++;
    }
    n=n/10;
    d=n%10;
    printf("Your Encrypted String is:\n");
    for(i=0;s[i]!='\0';i++)
    {
        if((s[i]+d)<=127)
        {
            s[i]=s[i]+d;
        }
        else if((s[i]+d)>127)
        {
            s[i]=128-s[i];
        }
        t++;
        if(t==2)
        {
            for (v = 0; v < 5; v++) {
                pass[v] = rand() % 9;
                char capLetter = 'A' + (rand() % 26);
                pass[v + 2] = capLetter;
                char letter = 'a' + (rand() % 26);
                pass[v + 3] = letter;
                printf("%d%c%c", pass[v], pass[v + 2], pass[v + 3]);
            }
            t=0;
        }
        printf("%c",s[i]);
        encr[i]=s[i];
    }
    printf("\nYour Encrypted Key is:%d\n",n1);
}


void Decrpyt()
{
    int n,i,d,j=0,r;
    char s[100],gg,ss;
    printf("Enter Your String:");
    scanf("%s",s);
    printf("Enter Your Encrypted Key is:");
    scanf("%d",&n);
    if(len_count(n)!=5)
    {
        printf("Please enter the valid Key");
        return;
    }
    r=n%10;
    int l = strlen(encr);
    while(j!=r)
    {
        gg=encr[1];
        ss=encr[0];
        for(i=0;i<=(l-1);i++)
        {
            if(i==(l-1))
                encr[0]=encr[i];
            else
                encr[i]=encr[i+1];
        }
        encr[0]=gg;
        encr[l-1]=ss;
        j++;
    }
    n=n/10;
    d=n%10;
    printf("Your Decrypted String is:");
    for(i=0;i<l;i++)
    {
        if((encr[i]-d)>=0)
        {
            encr[i]=encr[i]-d;
        }
        else if((encr[i]-d)<0)
        {
            encr[i]=128+encr[i];
        }
        printf("%c",encr[i]);
    }
    printf("\n");
}
