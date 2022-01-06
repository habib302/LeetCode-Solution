//method: using two hashmap
//this problem is same as word pattern
class Solution {
public:
    bool wordPattern(string pattern, string s) {
      
      int n1=pattern.size(),n2=s.size();
      vector<string> s1;
      string temp="";
      
      //step 1: remove all the white space & 
      //save the string in a vector 
      for(int i=0;i<n2;i++){
        char ch=s[i];
        if(ch==' '){
          s1.push_back(temp);
          temp="";
        }
        else {
          temp = temp+ch;
        }  
      }
      //push the last string
      s1.push_back(temp);
 
      n2=s1.size();
      
      //base case
      if(n1!=n2) return false;
      
      //declare two hashmap
      unordered_map<char,string> map1;
      unordered_map<string,bool> map2;
      
      for(int i=0;i<n1;i++){
        char ch=pattern[i];
        string s2=s1[i];
        
        //case1: 
        if(map1.find(ch) != map1.end()){
          if(map1[ch] != s2){
            return false;
          }
        }
        //case2:
        else{
          if(map2.find(s2) != map2.end()){
            return false;
          }
          else{
            map1.insert({ch,s2});
            map2.insert({s2,true});
          }
        }
      }

      return true;
    }
};