//method: using two hashmap
class Solution {
public:
    bool isIsomorphic(string s, string t) {
      
      int n1=s.size(),n2=t.size();
      
      //base case
      if(n1!=n2) return false;
      
      unordered_map<char,char> map1;
      unordered_map<char,bool> map2;
      
      for(int i=0;i<n1;i++){
        char ch1=s[i];
        char ch2=t[i];
        
        //case1: s1= a a  s2= x y
        if(map1.find(ch1) != map1.end() ){
          if(map1[ch1] != ch2) return false;
        }
        
        //case1: s1= a b  s2= x x
        else{
          if(map2.find(ch2) != map2.end()){
            return false;
          }
          else{
            map1.insert({ch1,ch2});
            map2.insert({ch2,true});
          }
        }
      }
      
      return true;
    }
};