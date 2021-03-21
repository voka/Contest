#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef struct Point{
	char status;
	char like;
	int x;
	int y;
	int st;
	double li;
};

bool cmp(Point a,Point b){
	if(a.st != b.st){ // 0 == "W", 1 == "Y", 2 == "O"
		return a.st<b.st;
	}
	if(a.li != b.st){
		return a.li>b.li;
	}
	if(a.x!=b.x){
		return a.x<b.x;
	}
	return a.y<b.y;
}

void printPoint(Point a){
	
	//cout<<"st : "<<a.st<<'\n'
	if(a.st == 0) return;
	cout<<a.like;
	printf(" %.1lf ",a.li);
	cout<<a.x<<" "<<a.y<<'\n';
}


int main() {
	map<char,int> stat;
	map<char,double> likely;
	stat['W'] = 0;
	stat['Y'] = 1;
	stat['O'] = 2;
	int index=0;
	int N,M;
	char e;
	cin>>likely['A']>>likely['B']>>likely['C']>>likely['D']>>likely['E'];
	cin>>N>>M;
	Point store[N*M + 1];
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>e;
			Point a = {e,e,i,j,stat[e],0.0};
			store[index++] = a;
		}
	}
	index = 0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			cin>>e;
			store[index].li = likely[e];
			store[index++].like = e;
		}
	}
	sort(store,store+index,cmp);
	for(int i=0;i<N*M;++i){
		printPoint(store[i]);
	}
	return 0;
}
