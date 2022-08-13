class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int start=1,end=INT_MIN,res;
        
        for(int num:nums){
            end = max(end, num);
        }
        
        res=end;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(isPossible(nums,mid,threshold)){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return res;
    }
    
    bool isPossible(vector<int>& nums, int mid,int threshold){
        
        int temp=0;
        
        for(int num:nums){
                
            temp = temp + ceil(num/(mid*1.0));
            
            if(temp > threshold)
                return false;
        }
        
        return true;
    }
};