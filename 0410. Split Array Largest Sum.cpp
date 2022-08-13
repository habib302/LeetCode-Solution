class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int maxNum=INT_MIN, sum=0;
        
        for(int num:nums){
            maxNum = max(num, maxNum);
            sum = sum+num;
        }
        
        int start=maxNum, end=sum,res;
        
        while(start <= end){
            
            int mid=start + (end-start)/2;
            
            if(isPossible(nums,mid,m)){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return res;
    }
    
    bool isPossible(vector<int>& nums,int mid,int m){
        
        int currSum=0,count=1;
        
        for(int num:nums){
            
            currSum = currSum + num;
            
            if(currSum > mid){
                currSum = num;
                count++;
            }
            
            //check if count>m
            if(count>m)
                return 0;
        }
        
        return 1;
    }
};