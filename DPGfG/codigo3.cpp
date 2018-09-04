#include <cstdio>
#include <cassert>
using namespace std;
#define MAXN 2000000+5
int N, Q, L, R, X;
int start[MAXN+1];
int end[MAXN+1];
int days[MAXN+1];
int ans[MAXN+1];
void solve(){
	int count = 0;
	for(int i=-MAXN;i<=MAXN;i++){
		count = count + start[i];
		days[i] = count;
		count = count - end[i];
	}
	for(int i=-MAXN;i<=MAXN;i++)
		ans[days[i]]++;
	for(int i=MAXN-1;i>=-MAXN;i--)
		ans[i] += ans[i+1];
	return;
}
void init(){
	for(int i=-MAXN;i<=MAXN;i++)
		start[i] = end[i] = ans[i] = 0;
}
int main(){
	init();
	scanf("%d", &N);
	scanf("%d", &Q);
	for(int i=0;i<N;i++){
		scanf("%d %d", &L, &R);
		start[L]++;
		end[R]++;
	}
	solve();
	while(Q--){
		scanf("%d", &X);
		assert(X>0 and X<=N);
		printf("%d\n", ans[X]);
	}
	return 0;
}
