class Solution {
public:
    bool isIsomorphic(string s, string t) {
      //base case
      if(s==t) return true;
      
      //step1: initialize two array with zero
      int m1[256]={0},m2[256]={0},n=s.size();
      
      for(int i=0;i<n;i++){
        char ch1=s[i];
        char ch2=t[i];
        
        //step2: if m1[ch1] are not equal to m2[ch2] reurn false
        if(m1[ch1] != m2[ch2]) return false;
        
        //step3: update m1[ch1] & m2[ch2] with same value
        //get the char ascii value
        m1[int(ch1)]=i+1;
        m2[int(ch2)]=i+1;
      }
      
      return true;
    }
};
---------------------------------------------------------------------
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