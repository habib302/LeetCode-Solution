class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start=1, end=1000000000;
        
        while(start < end){
            
            //here mid==speed
            int mid = start + (end-start)/2;
            
            int totalHour=0;
            
            for(int pile:piles){
                totalHour = totalHour + ceil(pile/(mid*1.0));
            }
            
            if(totalHour > h){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        
        return start;
    }
};