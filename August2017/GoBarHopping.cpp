#include <bits/stdc++.h>
#define LEFT 0
#define RIGHT 1
const int N = 1000*1000+2;
int n, arr[N], cnt[N][2][2];
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    assert(n >= 1 && n <= 1000*1000);
    for(int i=1;i<=n-1;i++){
    	cin>>arr[i];
    	assert(arr[i] == 0 || arr[i] == 1);
    }

    for(int i=2;i<=n;i++){
    	cnt[i][LEFT][arr[i-1]] = 1 + cnt[i-1][LEFT][arr[i-1]];
    }

    for(int i=n-1;i>=1;i--){
    	cnt[i][RIGHT][arr[i]] = 1 + cnt[i+1][RIGHT][arr[i]];
    }

    int q;
    cin>>q;
    assert(q >= 1 && q <= 1000*1000);

    int state = 0;
    while(q--){

    	char ch;
    	cin>>ch;
    	assert(ch == 'U' || ch == 'Q');

    	if(ch == 'U'){

    		state ^= 1;
    	}
    	else{

    		int src;
    		cin>>src;
    		assert(src >= 1 && src <= n);

    		int ans = 1 + cnt[src][LEFT][state^LEFT] + cnt[src][RIGHT][state^RIGHT];
    		cout<<ans<<endl;
    	}
    }

    return 0;
}
