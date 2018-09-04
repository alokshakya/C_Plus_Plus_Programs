#include<bits/stdc++.h>
using namespace std;

long long Gifts (vector<int> S, int K) {
   // Write your code here
   long long ans=0;
   sort(S.begin(),S.end());
		for(int i=0;i<K;i++)
			ans+=(long long)S[i];
		for(int i=K;i<S.size();i++)
			ans+=(long long)S[K-1];
	return ans;

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> S(N);
        for(int i_S=0; i_S<N; i_S++)
        {
        	cin >> S[i_S];
        }
        int K;
        cin >> K;

        long long out_;
        out_ = Gifts(S, K);
        cout << out_;
        cout << "\n";
    }
}
