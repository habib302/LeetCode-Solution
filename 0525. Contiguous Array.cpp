class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        
        //base case
        if(n<2) return 0;
        
        //create map & put map[0]=-1
        unordered_map<int,int> map;
        map[0]=-1;
        
        int maxLength=0,sum=0;
        
        for(int i=0;i<n;i++){
            
            //find sum
            if(nums[i]==1) sum += 1;
            else sum -= 1;
            
            if(map.find(sum) != map.end()){
                maxLength=max(maxLength, i- map[sum]);
            }else{
                map[sum]=i;
            }
        }
        
        return maxLength;
    }
};