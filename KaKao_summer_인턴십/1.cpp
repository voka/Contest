#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,string> dic;
int a[1000001]={0,};
string ReplaceAll(string &str, const string& from, const string& to){
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos)  
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
    return str;
}
int solution(string s) {
    dic["zero"] = "0";
    dic["one"] = "1";
    dic["two"] = "2";
    dic["three"] = "3";
    dic["four"] = "4";
    dic["five"] = "5";
    dic["six"] = "6";
    dic["seven"] = "7";
    dic["eight"] = "8";
    dic["nine"] = "9";
    for(auto i : dic){
        s = ReplaceAll(s,i.first,i.second);
    }
    int answer = stoi(s);
    return answer;
}