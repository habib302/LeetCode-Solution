class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        
        int left=0,right=n-1;
        set<char> set;
        set.insert('a'); set.insert('e'); set.insert('i'); set.insert('o'); set.insert('u');
        set.insert('A'); set.insert('E'); set.insert('I'); set.insert('O'); set.insert('U');
        
        while(left < right){
            
            //find left vowel
            while(left < right){
                char ch=s[left];
                
                if(set.count(ch)){
                    break;
                }
                else left++;
            }
            
			//find right vowel
            while(left < right){
                char ch=s[right];
                
                if(set.count(ch)){
                    break;
                }
                else right--;
            }
            
            
            swap(s[left],s[right]);
            left++;
            right--;
            
        }
        return s;
    }
};