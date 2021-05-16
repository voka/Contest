#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
struct rooms{
    int room[5][5];
};
struct Point{
    int x;
    int y;
};

rooms A[5] = {0,}; // X : 0, O : 1 , P : 10;
vector<Point> P_loc[5];

bool check_P(int index){
    int size = P_loc[index].size();
    for(int i=0;i<size;++i){
        int x1 = P_loc[index][i].x,y1 = P_loc[index][i].y;
        for(int j=0;j<size;++j){
            if(i==j) continue;
            int M_distance = 0,x2 = P_loc[index][j].x,y2 = P_loc[index][j].y;
            M_distance = abs(x1-x2) + abs(y1-y2);
            if(M_distance <2 ){
                return false;
            }
            if(M_distance == 2){
                if(x1==x2){
                    if(A[index].room[x1][(y1+y2)/2] == 1)
                        return false;
                }
                else if(y1==y2){
                    if(A[index].room[(x1+x2)/2][y1] == 1)
                        return false;
                }
                else if(A[index].room[x1][y2] == 1 || A[index].room[x2][y1] == 1){
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    int counts[5] = {0,};
    for(int i=0; i<5;++i){
        for(int j=0; j<5;++j){
            for(int k=0; k<5;++k){
                if(places[i][j][k] == 'P'){
                    A[i].room[j][k] = 10;
                    P_loc[i].push_back({j,k});
                    counts[i]++;
                }
                else if(places[i][j][k] == 'O'){
                    A[i].room[j][k] = 1;
                }
            }
            
        }
    }
    vector<int> answer(5);
    for(int i=0;i<5;++i){
        if(counts[i]!=0){
            if(check_P(i)){
                answer[i] = 1;
            }
        }else{
            answer[i] = 1;
        }
    }
    
    return answer;
}