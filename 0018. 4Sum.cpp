class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> res;
        int n=nums.size(),left,right;
        long long int sum;
        
        //base case
        if(n<4) 
			return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<(n-3);i++){
            
            //handle i er duplicate
            if(i>0 && nums[i]==nums[i-1]) 
                continue;
            
            for(int j=i+1;j<(n-2);j++){
                
                //handle j er duplicate
                if(j>i+1 && nums[j]==nums[j-1]) 
                    continue; 
                
                left=j+1;
                right=n-1;
                
				//nums[i]=1000000000 & nums[j]=1000000000
				//so we need to use long long 
                long long int newTarget = target - (long long)(nums[i]+nums[j]);
                
                while(left<right){
                    
                    sum=nums[left]+nums[right];
                    
                    if(sum==newTarget){
                        
                        res.push_back( {nums[i],nums[j],nums[left],nums[right]} );
                        
                        //handle left_index duplicate
                        while(left<right && nums[left]==nums[left+1]){
                            left++;
                        }
                        left++;
                        
                        //handle right_index duplicate
                        while(left<right && nums[right]==nums[right-1]){
                            right--;
                        }
                        right--;
                        
                    }
                    else if(sum < newTarget){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return res;
    }
};