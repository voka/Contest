#include <iostream>
using namespace std;

int mart[10001][101] = {0,};
double dp[10001][101]= {0,};
int N=0,M=0;

void solve(){
  	cin>>M>>N; 
    for(int i=1; i<=N;++i){ 
        for(int j=1;j<=M;++j){
            scanf("%d",&mart[i][j]);
        }
    }
    for(int i=1; i<=N;++i){
        for(int j=1;j<=M;++j){
              dp[i][j] =  max(dp[i][j-1],dp[i-1][j]) + mart[i][j];
        }
    }
	printf("%.0lf\n",dp[N][M]);
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
