#include<bits/stdc++.h>
using namespace std;
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
   int co=0;
void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
   {
       co++;
       printf("%s \t", a);
   }

   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
int main()
{
    /*string str;
    cin>>str;
    int n = str.size();
    char ch[n];
    for(int i=0;i<n;i++)
        ch[i]=str[i];
    permute(ch, 0, n-1);*/

    char str[] = "ABCD";
    int n = strlen(str);
    permute(str, 0, n-1);
    cout<<"\nno of permutations "<<co<<endl;

    return 0;
}
