//using boyer-moore algorithm
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int val1=-1,val2=-1,c1=0,c2=0;
        int n=nums.size();
        
        //base case
        if(n==1) return nums;
        
        for(int i=0;i<n;i++){
            if(val1==nums[i]){  
                c1++;
            }
            else if(val2==nums[i]){
                c2++;
            }
            else{
                if(c1==0){
                    val1=nums[i];
                    c1=1;
                }
                else if(c2==0){
                    val2=nums[i];
                    c2=1;
                }
                else{
                    c1--;
                    c2--;
                }
            }
        }
        
        vector<int> res;
        c1=0,c2=0;
        
        //now i get val1,val2... and count for val1,val2
        for(int i=0;i<n;i++){
            if(val1==nums[i])      c1++;
            else if(val2==nums[i]) c2++;
        }
        
        if(c1>n/3) res.push_back(val1);
        if(c2>n/3) res.push_back(val2);
        
        return res;
    }
};

----------------------------------------------------------------------
//using map
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        
        for(auto i:map){
            if(i.second>(nums.size())/3)
                result.push_back(i.first);
        }
        
        return result;
    }
};