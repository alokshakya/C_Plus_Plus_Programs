#include<bits/stdc++.h>
using namespace std;
void my_swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void selection_sort (int A[ ], int n) {
        // temporary variable to store the position of minimum element

        int minimum;
        // reduces the effective size of the array by one in  each iteration.

        for(int i = 0; i < n-1 ; i++)  {

           // assuming the first element to be the minimum of the unsorted array .
             minimum = i ;

          // gives the effective size of the unsorted  array .

            for(int j = i+1; j < n ; j++ ) {
                if(A[ j ] < A[ minimum ])  {                //finds the minimum element
                minimum = j ;
                }
             }
          // putting minimum element on its proper position.
          my_swap ( A[ minimum ], A[ i ]) ;
        }
   }
int main()
{
    int n,i;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    selection_sort(ar,n);
    for(i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
    return 0;
}
