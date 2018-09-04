/*
If frequent operation is insertion and deletion and finding minimum and maximum
in a data structure use set instead of priority_queue it will be efficient that modified form of
priority_queue.
*/

#include<iostream>
#include<set>
#include<algorithm>
#include<functional>
#include<iomanip> // for setprecision(1)
template<class T>
double GetMedian(const std::multiset<T>& data)
{
    if (data.empty())
        return 0;

    const size_t n = data.size();
    double median = 0;

    auto iter = data.cbegin();
    std::advance(iter, n / 2);

    // Middle or average of two middle values
    if (n % 2 == 0)
    {
        const auto iter2 = iter--;
        median = double(*iter + *iter2) / 2;    // data[n/2 - 1] AND data[n/2]
    }
    else
    {
        median = *iter;
    }

    return median;
}
using namespace std;
int main()
{
    int n,i,a,b;
    cin>>n;
    multiset<int> Q;
    multiset<int>::iterator it;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        Q.insert(a);
        double f=GetMedian(Q);
        cout << fixed << setprecision(1);
        cout<<f<<endl;
        //cout<<setprecision(4)<<a<<endl;
      //  printf("%.1f\n",GetMedian(Q))



    }




return 0;
 }
