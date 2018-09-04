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
        int dec_value = 0;

        // Initializing base value to 1, i.e 2^0
        int base = 1;

        int k;
        k=0;
        while(argv[1][k])
        {
            k++;
        }
        int i;
        for (i=k-1;i>=0;i--)
        {
            if (argv[1][i] == '0')
            {
                dec_value += 0*base;
            }
            else
            {
                dec_value += 1*base;
            }
            base = base * 2;
        }

        printf("%d",dec_value);
        return 0;
    }
}
