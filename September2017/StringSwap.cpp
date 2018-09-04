#include<stdio.h>
#include<string.h>
void my_swap(char *,char *, int, int)
int main()
{
    char s1[100],s2[100];
    scanf("\n%[^\n]s",s1);
    scanf("\n%[^\n]s",s2);
    my_swap(s1,s2,strlen(s1),strlen(s2));
    printf("s1=%s\ns2=%s",s1,s2);
    return 0;
}
void my_swap(char a[],char b[], int al, int bl)
{
    int i=0;
    while(al>0||a2>0)
    {
        if(al==0)
        {
        a[i]=b[i];
        b[i]='\0';
        i++;
        bl--;
        continue;
        }
        if(bl==0)
        {
        b[i]=a[i];
        a[i]='\0';
        i++;
        al--
        continue;
        }
        a[i]=a[i]^b[i];
        b[i]=a[i]^b[i];
        a[i]=a[i]^b[i];
        i++;
        al--;
        bl--;
    }
}
