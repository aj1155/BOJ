#include <cstdio>
using namespace std;

int main(){
	int N, M, arr[100000], rs[100001];
	scanf("%d", &N);
	rs[0] = 0;
	for(int i=0; i<N; i++){
		scanf("%d", arr+i);
		rs[i+1] = rs[i] + arr[i];
	}
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int p, q;
		scanf("%d %d", &p, &q);
		printf("%d\n", rs[q]-rs[p-1]);
	}
}