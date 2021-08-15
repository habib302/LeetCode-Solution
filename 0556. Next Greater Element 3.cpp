class Solution {
public:
    int nextGreaterElement(int n) {
        
        //base case 
        if(n<12) return -1;
        
        string nums=to_string(n);
        int n1=nums.size();
        int index=n1-2;
        
        //find decreasing element
        while(index>=0){
            if(nums[index] < nums[index+1]){
                break;
            }
            index--;
        }
        
        //jodi kono decreasing na pay tahole index -1 hbe...4321
        if(index==-1) return -1;
        
        //assign to last index and find greater element
        int j=n1-1;
        for( ;index<j;j--){
            if(nums[index] < nums[j]){
                break;
            }
        }
        
        //swap the index
        swap(nums[index],nums[j]);
        
        //reverse after index
        reverse(nums.begin()+index+1, nums.end());
        
        //check INT_MAX
        return stoll(nums)>INT_MAX ? -1 : stoi(nums);
    }
};