#include <stdio.h>
int main() {
	int T=0,index_s=0,index_e=0;
	int start=59,end = 2359,t1,t2;
	char answer[20];
	scanf("%d",&T);
	char start_T[T][5],end_T[T][5];
	for(int i=0;i<T;++i){
	  scanf("%s%s%s",start_T[i],answer,end_T[i]);
		t1 = (start_T[i][0]-'0')*1000 + (start_T[i][1]-'0')*100 + (start_T[i][3]-'0')*10 + (start_T[i][4]-'0');
		t2 = (end_T[i][0]-'0')*1000 + (end_T[i][1]-'0')*100 + (end_T[i][3]-'0')*10 + (end_T[i][4]-'0');
		if(start<t1){
			index_s = i;
			start = t1;
		}
		if(end>t2){
			index_e = i;
			end = t2;
		}
	}
	if(start>end) printf("-1");
	else printf("%s ~ %s\n",start_T[2],end_T[1]);
	return 0;
}

