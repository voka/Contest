#include <iostream>
using namespace std;

int mart[10001][101] = {0,};
double dp[10001][101]= {0,};
int N,M;

void printArray(int n, int m, int flag){
    for(int i=0; i<=n+1;++i){
        for(int j=0;j<=m+1;++j){
            if(flag ==1 )
                cout<<dp[i][j]<<", ";
            else
                cout<<mart[i][j]<<", ";
        }
        cout<<"\n";   
    }
        cout<<"\n\n\n";
}



void solve(){
  	cin>>M>>N; 
    for(int i=1; i<=N;++i){ 
        for(int j=1;j<=M;++j){
            scanf("%d",&mart[i][j]);
        }
    }
		cout<<N<<", "<<M<<"\n";
    printArray(N,M,2);
    for(int i=1; i<=N;++i){
        for(int j=1;j<=M;++j){
              dp[i][j] =  max(dp[i][j-1],dp[i-1][j]) + mart[i][j];
        }
    }
    printArray(N,M,1);
	
		printf("%.0lf\n",dp[N][M]);
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
