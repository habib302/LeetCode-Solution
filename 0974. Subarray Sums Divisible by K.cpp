class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int n=nums.size(),count=0,prefixSum=0,rem=0;
        
        //step1: declare & initialize map with {0,1}
        unordered_map<int,int> map;
        map.insert({0,1});
        
        for(int i=0;i<n;i++){
            
            //step2: calculate prefixSum
            prefixSum += nums[i];
            
            //step3: find remainder
            rem = prefixSum%k;
            
            //remainder negative hole pos korar jonne
            if(rem<0) rem += k;
            
            //step4: check remainder into map
            if(map.find(rem) != map.end()){
                count += map[rem];
                map[rem]++;
            }
            else{
                map.insert({rem,1});
            }
        }
        
        return count;
    }
};