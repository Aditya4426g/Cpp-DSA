#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<pair<int,int>> jobs){
    sort(jobs.begin(),jobs.end(),[](pair<int,int> p1,pair<int,int> p2){
        return p1.second>p2.second;
    });

    int profit=jobs[0].second;
    int safeDeadline = 2;

    for(int i=1;i<jobs.size();i++){
        if(jobs[i].first >=safeDeadline){
            profit += jobs[i].second;
            safeDeadline++;
        }
    }
    return profit;
}


int main(){
    int n=5;
    vector<pair<int,int>> jobs(n,make_pair(0,0));
    jobs[0] = make_pair(2,100);
    jobs[1] = make_pair(1,19);
    jobs[2] = make_pair(1,27);
    jobs[3] = make_pair(1,25);
    jobs[4] = make_pair(3,15);
    cout<<maxProfit(jobs);
    return 0;
}