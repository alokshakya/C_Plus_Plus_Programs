#include<stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[])
{
    if(argc==1)
    {
        printf("No arguments");
        return 0;
    }
    else
    {
        int base,height;
        float area;
        base=atoi(argv[1]);
        height=atoi(argv[2]);
        //area=(1/2)*base*height;//this formula will give answer 0.00 because (1/2) will give 0 because both 1 and 2 are int
        area=(1.0/2.0)*base*height;
        printf("%.2f",area);
        return 0;
    }
}
