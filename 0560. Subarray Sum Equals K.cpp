class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      
        int n=nums.size(),prefixSum=0,count=0;
        
        //step1: declare & initialize map with {0,1}
        unordered_map<int,int> map;
        map.insert({0,1});
        
        for(int i=0;i<n;i++){
            
            //step2: calculate prefixSum
            prefixSum = prefixSum +nums[i];
            
            //step3: check prefixSum-k into map
            if(map.find(prefixSum-k) != map.end()){
                
                //step4: update count with frequency
                count = count + map[prefixSum-k];
            }
            
            //step5: save prefixSum with frequency
            map[prefixSum]++;
        }
        
        return count;
    }
};