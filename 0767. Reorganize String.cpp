class Solution {
public:
    string reorganizeString(string s) {
        
        //base case
        if(s.size()==1) return s;
        
        vector<int> freq(26,0);
        int maxFrequency=INT_MIN,n=s.size();
        char letter;
        
        for(auto ch:s){
            freq[ch-'a']++;
            
            if(freq[ch-'a'] > maxFrequency){
                maxFrequency=freq[ch-'a'];
                letter=ch;
            }
        }
        
        // int t=ceil( n / 2.0);
        // cout<<t;
        
        //cout<<maxFrequency<<" "<<letter<<" "<<ceil(n/2.0);
        
        //check maxFrequency 
        if(maxFrequency > ceil(n/2.0) ) return "";
        
        //1st fill even index in string
        
        int index=0;
        
        while(freq[letter-'a'] >0){
            s[index]=letter;
            freq[letter-'a']--;
            index=index+2;
        }
        
        //cout<<s;
        
        for(int i=0;i<freq.size();i++){
            
            while(freq[i] >0){
                
                //if index>=n then start from 1st index
                if(index>=n){
                    index=1;
                }
                
                s[index]= i+'a';
                index=index+2;
                freq[i]--;
            }
            
        }
        
        return s;
    }
};