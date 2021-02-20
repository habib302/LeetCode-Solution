#include <bits/stdc++.h>
using namespace std;
vector<int> KLargest(vector<int> nums);

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n;
        vector<int> nums(n);

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        vector<int> ans= KLargest(nums);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


vector<int> KLargest(vector<int> nums){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> result;
    
    for(int i=0;i<nums.size();i++){
        minHeap.push(nums[i]);
        // if(minHeap.size()>k){
        //     minHeap.pop();
        // }
    }
    while(minHeap.size()>0){
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}