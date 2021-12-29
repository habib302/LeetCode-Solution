class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
        int min1=INT_MAX,min2=INT_MAX,val=0;
        
        for(int i=0;i<nums.size();i++){
            val=nums[i];
            
            //build max1,max2,max3
            if(val > max1){
                max3=max2;
                max2=max1;
                max1=val;
            }
            else if(val>max2){
                max3=max2;
                max2=val;
            }
            else if(val > max3){
                max3=val;
            }
            
            //build min1,min2
            if(val < min1){
                min2=min1;
                min1=val;
            }
            else if(val < min2){
                min2=val;
            }
        }
        int res=max(max1*max2*max3, min1*min2*max1);
        return res;
    }
};