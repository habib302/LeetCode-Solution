class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(52,0);

        for(char ch:s){
            if(ch>='a' && ch<='z'){
                freq[ch-'a']++;
            }

            if(ch>='A' && ch<='Z'){
                int index=(ch-'A')+26;
		        freq[index]++;
            }

        }

        int evenCount=0;
        bool isOdd=false;

        for(int i=0;i<52;i++){

            int temp = freq[i]/2;
            evenCount += (temp*2);

            if(freq[i]%2==1){
                isOdd=true;
            }
        }
        
        return isOdd ? evenCount+1 : evenCount;
    }
};