#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;
deque<int> deleted_row;
int status[1000001]={0,};
int N;
int find_not_deleted(int index,bool flag,int num){// U : false, D : true;
    if(flag){
        while(1){
            if(!status[index]) {
                if(num == 0)
                    return index;
                num--;
            }
            index++;
        }
    }
    else{
        while(1){
            if(!status[index]) {
                if(num == 0)
                    return index;
                num--;
            }
            index--;
        }
    }
    
    
}
string solution(int n, int k, vector<string> cmd) {
    N = n;
    int selected_row = k,X=-1,recent=-1,end_node=n-1;
    string s;
    //cout<<"cur == "<<selected_row<<"\n";
    for(auto i : cmd){
        switch(i[0]){
            case 'D':
                s = "";
                for(int j=2;j<i.size();++j){
                    s += i[j];
                }
                //cout<<"S == "<<s<<"\n";
                X = stoi(s);
                selected_row = find_not_deleted(selected_row,true,X);
                //cout<<"cur == "<<selected_row<<", X == "<<X<<"\n";
                break;
            case 'U':
                s = "";
                for(int j=2;j<i.size();++j){
                    s += i[j];
                }
                //cout<<"S == "<<s<<"\n";
                X = stoi(s);
                selected_row = find_not_deleted(selected_row,false,X);
                //cout<<"cur == "<<selected_row<<", X == "<<X<<"\n";
                break;
            case 'C':
                deleted_row.push_back(selected_row);
                status[selected_row] = 1;
                //cout<<"cur == "<<selected_row<<"\n";
                if(selected_row == end_node){
                    selected_row = find_not_deleted(selected_row,false,0);
                    end_node = selected_row;
                }
                else{
                    selected_row = find_not_deleted(selected_row,true,0);
                }
                //cout<<"change == "<<selected_row<<"\n";
                break;
            case 'Z':
                recent = deleted_row.back();
                deleted_row.pop_back();
                status[recent] = 0;
                end_node = max(end_node,recent);
                break;
        }
    }
    string answer = "";
    for(int i=0;i<n;++i){
        if(!status[i]){
            answer+="O";
        }
        else{
            answer+="X";
        }
    }
    
    return answer;
}