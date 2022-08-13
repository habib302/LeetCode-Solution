class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size(),target=0;
        
        //pair sum->frequency
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                int sum = nums1[i]+nums2[j];
                
                mp[sum]++;
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                int newTarget = target - (nums3[i]+nums4[j]);
                
                if(mp.count(newTarget)){
                    count = count + mp[newTarget];
                }
            }
        }
        
        return count;
    }
};