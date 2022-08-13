class Solution {
public:
    string reverseStr(string s, int k) {
        
        int n=s.size();
        
        //base case
        if(k==1)
            return s;
        
        if(k>n){
            reverse(s,0,n-1);
            return s;
        }
        
        for(int i=0; i<n; i=i+(2*k)){
            
            int start=i;
            
            //handle end 
            int end= (i+k-1) > n ? n-1 : (i+k-1);
            
            //find newK
            int newK = (end-start) + 1;
            
            if(newK < k){
                //reverse all
                reverse(s,start,end);
            }
            else{
                //reverse first k character
                reverse(s,start,end);
            }
        }
        
        return s;
    }
    
    //reverse method
    void reverse(string &s,int left,int right){
        
        while(left<right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};