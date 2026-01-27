#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minAbs(vector<int> A,vector<int> B){
    int ans = 0 ;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0;i<A.size();i++){
        ans+=abs(A[i] - B[i]);

    }
    return ans;
}

int main()
{
    vector<int> A = {4,1,8,7};
    vector<int> B = {2,3,6,5};
    cout<<minAbs(A,B);

    return 0;
}