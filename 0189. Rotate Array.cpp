//brute force
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        //base case
        if(k>n){
            k = k % n;
        }
        
        stack<int> st;
        
        int i=n-1,t=k;
        
        //store to stack
        while(t--){
            st.push(nums[i]);
            i--;
        }
        
        //move all the element to right
        for(int left=n-k-1,right=n-1; left>=0; left--,right--){
            nums[right]=nums[left];
        }
        
        int n1=st.size();
        
        //final push to the array from stack
        for(int i=0;i<n1;i++){
            nums[i]=st.top();
            st.pop();
        }
    }
};
=========================================================
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        //base case
        if(k>=n){
            k = k%n;
        }
        
        //three step 
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};