#include <bits/stdc++.h>
using namespace std;
int kSmallest(vector<int> nums,int k);
int KSmallestMaxHeap(vector<int> nums,int k);

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        //cout<<kSmallest(nums,k)<<endl;
        cout<<KSmallestMaxHeap(nums,k)<<endl;
    }
    return 0;
}

//using sort
int kSmallest(vector<int> nums,int k){
    sort(nums.begin(),nums.end());
    return nums[k-1];
}

//using heap
int KSmallestMaxHeap(vector<int> nums,int k){
    priority_queue<int> maxHeap;
    for(int i=0;i<nums.size();i++){
        maxHeap.push(nums[i]);
        if(maxHeap.size()>k){
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}