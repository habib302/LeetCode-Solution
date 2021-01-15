#include <iostream>
#include <queue>
#include <vector>
//#include <priority_queue>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums,int k){
    priority_queue<int> maxHeap;

    for(int i=0;i<nums.size();i++){
        maxHeap.push(nums[i]);
        if(maxHeap.size()>k){
            cout<<maxHeap.top()<<" ";
            maxHeap.pop();
        }
    }

    while(maxHeap.size()>0){
        cout<<maxHeap.top()<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> nums;
        while(n--){
            int num1=0;
            cin>>num1;
            nums.push_back(num1);
        }
        //solve();
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0;i<nums.size();i++){
            minHeap.push(nums[i]);
            if(minHeap.size()>k){
                cout<<minHeap.top()<<" ";
                minHeap.pop();
            }
        }
        //cout<<"hello";
        while(minHeap.size()>0){
            cout<<minHeap.top()<<" ";
            minHeap.pop();
        }
        cout<<endl;

    }
	return 0;
}
