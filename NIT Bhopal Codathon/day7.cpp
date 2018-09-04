#include <bits/stdc++.h>
#include <unistd.h>
#include <fcntl.h>
#define ll  long long
#define f first
#define s second
#define pii pair< ll,ll >
#define pb push_back
#define sc(x) scanf("%d",&x)
#define lw lower_bound
#define llmax 1e9
#define mod 1000000007
#define block 350
#define MAX 100010
using namespace std;
// set <pii> s ;
priority_queue < pair < ll ,pii > ,vector< pair < ll ,pii > > ,std::greater< pair < ll ,pii > > > q ;
map <ll,bool> mii  ;
map <ll,ll> ::iterator iit,iit1 ;
map <string ,ll> msi ;
map <string ,ll> ::iterator sit ;
map <char ,ll > mci2 ;
map <char ,ll > ::iterator cit ;
map <ll ,char > mci1 ;
map <ll ,ll> mark ,mii1;
map <ll ,bool> ::iterator bit ;
vector < int > v ,ans ;
vector <ll > ::iterator vit ;
int a[MAX] ,ok [100*MAX];
bool dp [200*MAX] ;

int main  () {

	// ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,x ,mx=0;
    sc(n) ;
    for ( int i=0;i<n;i++) sc(a[i]) ;
    // sort (a.begin(),a.end()) ;
    // vit =unique (a.begin(),a.end()) ;
    // a.resize(distance(a.begin(),vit)) ;
    // n =a.size() ;
    int cnt = 0 ,ind =0;
    int pi =-1,pj=-1,pk=-1 ;
    for ( int i=0 ;i <n && cnt <2e8 ;i++) {
        for ( int j=i+1;j<n && cnt <2e8 ;j++) {
            while ( j<n && pj==a[j] && cnt<2e8) j++ ;
            if ( j== n ) break ;
            int val =a[i] +a[j] ;
            for ( int k = j+1 ;k< n && cnt <2e8 ;k++) {
                cnt++ ;
                if (dp [val+a[k]] ) continue ;
                dp [val+a[k]] =true ;
                ok[ind++] =(val+a[k]) ;
            }
        }
    }

    // int ind =0 ;
    // for ( int i=1;i<=mx;i++) {
    //     if (ok[i]) ok [ind++] ={i,ok[i]} ;
    // }
    // int i=0; cnt = 0;

    // // cout <<"#" ;
    // while (i <ind  ) {

    //     if (ok[i].s >= 2) {

    //         ll val = 2*(ok[i].s) ;
    //         int j =0 ;

    //         while (j<ind) {

    //             cnt++ ;
    //             if (dp [val+ok[j].f]) continue ;
    //             dp [val+ok[j].f] =true ;
    //             v.pb (val+ok[j].f) ;
    //             if (cnt > 1e6) break ;
    //             j++ ;
    //         }

    //     }
    //     cnt++ ;
    //     i++ ;
    // }

    // i =0 ;
    // while ( i< ind ) {

    //     if (ok[i].s >= 3 ) {

    //         if (dp [3*ok[i].f]) continue ;
    //         dp [3*ok[i].f] =true ;
    //         v.pb (3*ok[i].f) ;
    //     }

    //     i++ ;
    // }
    cnt =0;
    pi =-1,pj=-1,pk=-1 ;
    for  ( int i=n-1;i>=0 && cnt <2e8 ;i--) {
        for ( int j=i-1;j>=0 && cnt <2e8;j--) {
            while (j>=0 && pj==a[j] && cnt <2e8) j-- ;
            if (j==-1) break ;
            int val=a[i]+a[j] ;
            for ( int k=j-1;k>=0 && cnt <2e8 ;k--) {
                cnt++ ;
                if (dp [val+a[k]] ) continue ;
                dp [val+a[k]] =true ;
                ok[ind++] =(val+a[k]) ;
            }
        }
    }
    printf ("%d\n",ind) ;
    for ( int i=0;i<ind;i++) printf("%d ", ok[i] );
}
