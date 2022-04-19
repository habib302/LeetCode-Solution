class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size(),maxLength=INT_MIN;
        //base case
        if(n<2) return n;
        
        //element -> true/false
        unordered_map<int,bool> map;
        
        //insert all the element and set to true
        for(int i=0;i<n;i++){
            map[nums[i]]=true;
        }
        
        //find all the start point
        for(int i=0;i<n;i++){
            
            if(map.find(nums[i]-1) != map.end()){
                map[nums[i]]=false;
            }
        }
        
        //count the maxLength
        for(int i=0;i<n;i++){
            
            if(map[nums[i]]==true){
                
                int count=0,start=nums[i];
                
                //count from start position
                while(map.find(start) != map.end()){
                    start++;
                    count++;
                }
                
                maxLength = max(maxLength, count);
            }
        }
        
        return maxLength;
    }
};