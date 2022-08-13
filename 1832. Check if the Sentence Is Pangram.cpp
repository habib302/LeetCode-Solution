class Solution {
public:
    bool checkIfPangram(string s) {
        //every character frequency
        vector<int> freq(26,0);

        for(char ch:s){
            if(ch==' '){
                continue;
            }
            else{
                freq[ch-'a']++;
            }
        }

        for(int i=0;i<26;i++){
            if(freq[i]==0){
                return false;
            }
        }

        return true;
    }
};