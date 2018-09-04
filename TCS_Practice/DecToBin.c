#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    if(argc==1)
    {
        printf("No Arguments ");
        return 0;
    }
    else
    {
        int n;

        n=atoi(argv[1]);
        int binaryN[64];
        int i=0;int j;
        while(n>0)
        {
            //storing in binary array remainder of number
            binaryN[i]=n%2;
            n=n/2;
            i++;
        }
        //printing reverse array
        while(i)
        {
            printf("%d",binaryN[--i]);
        }

        return 0;
    }
}
