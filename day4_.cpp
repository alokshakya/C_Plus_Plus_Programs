/* C/C++ program for Memoized version for nth Fibonacci number */
#include<iostream>
#define ll long long
#define MAX 100000000
using namespace std;
int lookup[MAX];

/* Function to initialize NIL values in lookup table */


/* function for nth Fibonacci number */
ll fib(int n)
{
   if (lookup[n] == 0)
   {

      if (n <= 2)
         lookup[n] = n;
      else
      {
          ll a=fib(n-1);
          ll b=fib(n-2);
          lookup[n] = a+ b + (a*b);
      }

   }

   return lookup[n];
}

int main ()
{
  //int n = 22;
  int t,f0,f1,N;
  cin>>t;
  while(t--)
  {
      cin>>f0>>f1>>N;
      lookup[0]=f0;
      lookup[1]=f1;
     cout<<"Fibonacci number is  "<< fib(N);
  }


  return 0;
}
