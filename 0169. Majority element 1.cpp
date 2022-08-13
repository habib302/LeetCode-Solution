//using map

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int result=0;
        for(auto i:m){
            if(i.second>(nums.size())/2)
                result=i.first;
        }
        
        return result;
    }
};


------------------------------------------------
//using moore-voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority=0,count=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(count==0){
                majority=nums[i];
                count=1;
            }
            else if(majority==nums[i]){ 
                count++;
            }
            else{
                count--;
            }
        }
        
        return majority;
    }
};


------------------------------------------------
//using sort
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=nums.size()/2;
        return nums[m];
    }
};