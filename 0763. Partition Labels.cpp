class Solution {
public:
    vector<int> partitionLabels(string s) {
      
      vector<int> res;
      unordered_map<char,int> map;
      int n=s.size();
      
      //step 1: map all the character
      for(int i=0;i<n;i++){
        char ch=s[i];
        map[ch]=i;
      }
      
      int maxIndex=0,lastIndex=-1;
      
      //step 2: traverse the string 
      for(int i=0;i<n;i++){
        char ch=s[i];
        maxIndex = max(maxIndex, map[ch]);
        if(maxIndex==i){
          res.push_back(maxIndex-lastIndex);
          lastIndex = i;
        }
      }
      
      return res;
    }
};