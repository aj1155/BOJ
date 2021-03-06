#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Comparator{
    const vector<int> &G;
    int T;
    Comparator(const vector<int>& group, int t): G(group), T(t){}
    bool operator()(int a, int b){
        if(G[a] != G[b]) return G[a] < G[b];
        return G[a+T] < G[b+T];
    }
};
 
int main(){
    char S[5001];
    scanf("%s", S);
    int N = strlen(S), t = 1;
    vector<int> SA(N);
    for(int i=0; i<N; i++)
        SA[i] = i;
    vector<int> group(N+1), newGroup(N+1);
    for(int i=0; i<N; i++)
        group[i] = S[i];
    group[N] = newGroup[N] = -1;
 
    while(t < N){
        Comparator makeSA(group, t);
        sort(SA.begin(), SA.end(), makeSA);
        t *= 2;
        if(t >= N) break;
 
        newGroup[SA[0]] = 0;
        for(int i=1; i<N; i++){
            if(makeSA(SA[i-1], SA[i])) newGroup[SA[i]] = newGroup[SA[i-1]] + 1;
            else newGroup[SA[i]] = newGroup[SA[i-1]];
        }
        swap(group, newGroup);
    }
 
    vector<int> LCP(N), R(N, 0);
    for(int i=0; i<N; i++)
        R[SA[i]] = i;
    int l = 0;
    for(int i=0; i<N; i++){
        int k = R[i];
		if(k == 0) continue;
        int j = SA[k-1];
        while(S[i+l] == S[j+l]) l++;
        LCP[k] = l;
        if(l > 0) l--;
    }
 
	int result = 0;
    for(int i=1; i<N; i++)
        result = max(result, LCP[i]);
    printf("%d\n", result);
}