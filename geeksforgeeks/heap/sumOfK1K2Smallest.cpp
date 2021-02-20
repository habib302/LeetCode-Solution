#include <bits/stdc++.h>
using namespace std;
int sumOfK1k2(vector<int> nums,int n,int k1,int k2);
int kSmallest(vector<int> nums,int n,int k);

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k1,k2;
        cin>>n>>k1>>k2;
        vector<int> nums(n);

        for(int i=0;i<n;i++){
            cin>>nums[i];
        }

        cout<<sumOfK1k2(nums,n,k1,k2)<<endl;
    }
    return 0;
}


int sumOfK1k2(vector<int> nums,int n,int k1,int k2){
    int k11=kSmallest(nums,n,k1);
    int k22=kSmallest(nums,n,k2);
    int sum=0;
    for(int i=0;i<n;i++){
        if(nums[i]>k11 && nums[i]<k22){
            sum += nums[i];
        }
    }
    return sum;
}

int kSmallest(vector<int> nums,int n,int k){
    
    priority_queue<int> maxHeap;

    for(int i=0;i<n;i++){
        maxHeap.push(nums[i]);
        if(maxHeap.size()>k){
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}