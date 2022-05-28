//using set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> set;
        
        for(int i=0;i<n;i++){
            if(set.count(nums[i])){
                return true;
            }
            else{
                set.insert(nums[i]);
            }
        }
        
        return false;
    }
};
----------------------------------------------
//using sort
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        //base case
        if(n==1) return false;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        
        return false;
    }
};


-------------------------------------
//using map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        
        for(auto i: map){
            if(i.second > 1){
                return true;
            }
        }
        
        return false;
    }
};