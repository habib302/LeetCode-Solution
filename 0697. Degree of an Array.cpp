class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        //frequency_map
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        
        int highestFrequency=0,n=nums.size(),res=INT_MAX,start,end;
        
        for(int i=0;i<n;i++){
            
            //frequency map
            if(map1.find(nums[i]) != map1.end()){
                map1[nums[i]]++;
                cout<<map1[nums[i]]<<" ";
            }
            else{
                map1[nums[i]]=1;
            }
            
            //map1[nums[i]]++;
            
            //firstIndex
            if(map2.find(nums[i]) != map2.end()){
                //continue
            }
            else{
                map2[nums[i]]=i;
            }
            
            //
            if(map1[nums[i]] > highestFrequency){
                //cout<<map1[nums[i]]<<'\n';
                highestFrequency = map1[nums[i]];
                
                //end-start+1
                res =  i-map2[nums[i]]+1 ;
            }
            else if(map1[nums[i]] == highestFrequency){
                res = min(res, i-map2[nums[i]]+1 );
            }
        }
        
        //for(auto i:map1) cout<<i.first<<" "<<i.second<<'\n';
        //for(auto i:map2) cout<<i.first<<" "<<i.second<<'\n';
        
        return res;
    }
};