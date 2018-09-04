#include<iostream>
using namespace std;
int ** transposeMatrix(int **ar,int row,int col)
{
    int **tar=new int*[row];
    int i,j;
    for(i=0;i<col;i++)
    {   tar[i]=new int[col];
        for(j=0;j<row;j++)
        {
            tar[i][j]=ar[j][i];
        }
    }
    return tar;
}
void printMatrix(int** ar,int row,int col)
{
    int i,j;
    for(i=0;i<row;i++)
       {
           for(j=0;j<col;j++)
           {
               cout<<ar[i][j]<<" ";
           }
           cout<<endl;
       }
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int** ar=0;
    ar = new int*[n];
    for(i=0;i<n;i++)
    {   ar[i]=new int[m];
        for(j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }
   int** tpM= transposeMatrix(ar,n,m);
   printMatrix(tpM,m,n);
   //delete dynamically allocated array otherwise it lead to memory leak
   //delete ar array which was dynamically generated
   for(i=0;i<n;i++)
    delete[] ar[i];
   delete[] ar;
   //delete tpM Array
   for(i=0;i<m;i++)
    delete[] tpM[i];
   delete[] tpM;


    return 0;
}
