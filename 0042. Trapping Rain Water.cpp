class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        //base case
        if(n<3)
            return 0;
        
        int left=0,right=n-1,leftMax=INT_MIN,rightMax=INT_MIN,res=0;
        
        while(left < right){
            
            //update the leftMax & rightMax
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            
            //first we need to know which one is min
            //leftMax or rightMax
            if(leftMax < rightMax){
                res = res + (leftMax- height[left]);
                left++;
            }
            else{
                res = res + (rightMax- height[right]);
                right--;
            }
        }
        
        return res;
    }
};