class Solution {
public:
    string getPermutation(int n, int k) {
        
        int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
        
        string res="";
        string nums="123456789";
        
        //reduce k because zero based index
        k--; 
        
        while(n>0){
            
            int index =  k/fact[n-1];
            
            res = res+ nums[index];
            nums.erase(nums.begin()+index);
            
            //update k & n
            k= k % fact[n-1];
            n--;
        }
        
        return res;
    }
};