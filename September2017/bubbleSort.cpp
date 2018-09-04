#include<bits/stdc++.h>
using namespace std;
void bubble_sort( int A[ ], int n ) {
    int temp;
    for(int k = 0; k< n-1; k++) {
        // (n-k-1) is for ignoring comparisons of elements which have already been compared in earlier iterations

        for(int i = 0; i < n-k-1; i++) {
            if(A[ i ] > A[ i+1] ) {
                // here swapping of positions is being done.
                temp = A[ i ];
                A[ i ] = A[ i+1 ];
                A[ i + 1] = temp;
            }
        }
    }
}
int main()
{
    int n,i;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    bubble_sort(ar,n);
    for(i=0;i<n;i++)
        cout<<ar[i]<<" ";
    cout<<endl;
    return 0;
}
