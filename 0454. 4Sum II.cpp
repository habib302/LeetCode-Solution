class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        //value -> frequency
        unordered_map<int,int> map;
        int temp=0,count=0,n=nums1.size();
        
        //create nums1 & nums2 frequency map
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp = nums1[i]+nums2[j];
                map[-temp]++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp = nums3[i]+nums4[j];
                
                if(map.find(temp)!= map.end()){
                    count = count + map[temp];
                }
            }
        }
        
        return count;
    }
};