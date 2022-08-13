class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        
        int left=0,right=n-1,maxArea=0;
        
        while(left < right){
            
			//first find the base & minHeight
            int base=right-left;
            int minHeight = min(height[left], height[right]);
            
            maxArea = max(maxArea, base*minHeight);
            
            //update left & right pointer
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        
        return maxArea;
    }
};