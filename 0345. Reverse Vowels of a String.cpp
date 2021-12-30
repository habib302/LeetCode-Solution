class Solution {
public:
    string reverseVowels(string s) {
      
      int n=s.size(),left=0,right=0;
      right=n-1;
      
      while(left <= right){
        
        //find the left vowel
        while(left<=right){
          if(s[left] =='a'  || s[left] =='e'  ||s[left] =='i'  ||s[left] =='o'  ||s[left] =='u' || 
             s[left] =='A'  || s[left] =='E'  ||s[left] =='I'  ||s[left] =='O'  ||s[left] =='U'){
            break;
          }
          else left++;
        }
        
        //find the left vowel
        while(left<=right){
          if(s[right] =='a'  || s[right] =='e'  ||s[right] =='i'  ||s[right] =='o'  ||s[right] =='u' ||
             s[right] =='A'  || s[right] =='E'  ||s[right] =='I'  ||s[right] =='O'  ||s[right] =='U'){
            break;
          }
          else right--;
        }
        
        //swap them
        if(left<=right){
          swap(s[left],s[right]);
          left++;
          right--;
        }
      }
      
      return s;
    }
};