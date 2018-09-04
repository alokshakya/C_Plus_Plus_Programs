#include<stdio.h>
#include<string.h>
#include<time.h>
void my_swap(char *,char *, int, int);
int main()
{
    clock_t start,end;
     double cpu_time_used;

    int len1,len2;
    char s1[100],s2[100];
    scanf("\n%[^\n]s%n",s1,len1);//%n specifiers is used to find the length of string while scanning it
    scanf("\n%[^\n]s%n",s2,len2);//%[^\n]s is used to take string input with spaces instead of gets() take string until get newline
    start=clock();
    my_swap(s1,s2,len1,len2);
    printf("s1=%s\ns2=%s",s1,s2);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%d",2>>24);
    printf("\nfun() took %f seconds to execute \n", cpu_time_used);
    return 0;
}
void my_swap(char a[],char b[], int al, int bl)
{
    int i=0;
    while(al>0||bl>0)
    {
        if(al==0)
        {
        a[i]=b[i];
        b[i]='\0';
        i++;
        bl--;
        if(bl==0)
            a[i]='\0';
        continue;
        }
        if(bl==0)
        {
        b[i]=a[i];
        a[i]='\0';
        i++;
        al--;
        if(al==0)
            b[i]='\0';
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
