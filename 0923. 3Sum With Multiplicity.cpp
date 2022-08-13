class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n=arr.size();
        
        //base case
        if(n<3)
            return 0;
        
        long long res=0,mod=1e9+7;
        sort(arr.begin(),arr.end());
        int left,right;
        
        for(int i=0;i<n-2;i++){
            left=i+1;
            right=n-1;
            
            while(left < right){
                int sum=arr[i]+arr[left]+arr[right];
                
                if(sum==target){
                    int c1=1,c2=1;
                    
                    while(left<right && arr[left]==arr[left+1]){
                        left++;
                        c1++;
                    }
                    
                    while(left<right && arr[right]==arr[right-1]){
                        right--;
                        c2++;
                    }
                    
                    if(left==right){
                        res = (res + c1*(c1-1)/2) % mod;
                    }
                    else{
                        res = (res + c1*c2) % mod;
                    }
                    
                    //update left & right
                    //age update korbo na
                    left++;
                    right--;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return res;
    }
};