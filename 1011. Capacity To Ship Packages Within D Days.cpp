class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int start=INT_MIN,end,res;
        
        for(int weight: weights){
            start = max(start, weight);
            end = end + weight;
        }
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(isPossible(weights,mid,days)){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return res;
        
    }
    
    bool isPossible(vector<int>& nums,int mid,int days){
        
        int d=1,currSum=0;
        
        for(int num:nums){
            
            currSum = currSum + num;
            
            if(mid < currSum){
                currSum = num;
                d++;
            }
            
            //check if d>days
            if(d>days)
                return false;
        }
        
        return true;
    }
};