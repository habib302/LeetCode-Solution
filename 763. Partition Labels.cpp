class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> freq(26,0), res;
        
        //map character using their index
        for(int i=0;i<n;i++){
            char ch=s[i]-'a';
            freq[ch]=i;
        }
      
      int prev=-1,max_index=0;
      
      //update max & check max==i.. then push to res
      for(int i=0;i<n;i++){
          char ch=s[i]-'a';
          
          max_index= max(max_index,freq[ch]);
          
          if(i==max_index){
            res.push_back(max_index-prev);
            prev=max_index;
          }
      }
      
      return res;
    }
};