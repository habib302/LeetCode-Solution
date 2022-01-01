class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
     
      int n=arr.size(),rem=0,freq1;
      
      // remainder -> frequency
      unordered_map<int,int> map;
      
      //step 1: count remainder frequency
      for(auto val:arr){
        rem = (val%k+k)%k; //negative no remainder
        map[rem]++;
      }
      
      //traverse the array again
      for(auto val:arr){
        rem = (val%k+k)%k;
        
        //check 1: rem==0
        if(rem==0){
          if(map[rem]%2 == 1){
            return false;
          }
        }
        
        //check 2: rem*2==k
        else if(rem*2==k){
          if(map[rem]%2 == 1){
            return false;
          }
        }
        
        //check 3: x er frequency == (k-x) er frequency
        else{
          if(map[rem] != map[k-rem]){
            return false;
          }
        }
        
      }
      
      return true;
    }
};