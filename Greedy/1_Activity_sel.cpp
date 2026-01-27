#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int maxActi(vector<int> start,vector<int> end){
    int count = 1; // A0 select
    int currEndTime=end[0];
    cout<<"Selecting A0"<<endl;
    for(int i = 1;i<start.size();i++){
        if(start[i] >= currEndTime){ //non-overlapping
            cout<<"Selecting A"<<i<<endl;
            count++;
            currEndTime=end[i];
        }
    }
    return count;
}

bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
}
void sortpair(vector<int> &start,vector<int> &end){
    int n=end.size();
    vector<pair<int,int>> p(n);
    for(int i =0 ;i<n;i++){
        p[i] = make_pair(start[i],end[i]);
    }
    sort(p.begin(),p.end(),compare);
    for(int i =0 ;i<n;i++){
        start[i] = p[i].first;
        end[i] = p[i].second;
    }
}


int main(){
    vector<int> start ={0,1,3};
    vector<int> end = {9,2,4};
    sortpair(start,end);
    
    cout<<maxActi(start,end);
    return 0;
}