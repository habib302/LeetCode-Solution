class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        
        //value, index
        unordered_map<int,int> map;
        
        for(int i=0;i<nums2.size();i++){
            map[nums2[i]]=i;
        }
        
        vector<int> res(nums1.size(),0);
        
        for(int i=0;i<nums1.size();i++){
            
            int index=map[nums1[i]];
            
            res[i]=index;
        }
        
        return res;
    }
};