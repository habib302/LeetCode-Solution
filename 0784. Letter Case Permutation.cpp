class Solution {
public:
    vector<string> res;
    vector<string> letterCasePermutation(string s) {
        helper(0,"", s);
        return res;
    }
    
    void helper(int index,string temp,string s){

    //base case
    if(temp.size()==s.size()){
        res.push_back(temp);
        return;
    }


    for(int i=index;i<s.size();i++){

        if(s[i]>='0' && s[i]<='9'){
            helper(i+1, temp+s[i], s);
        }
        else{
            char ch1=tolower(s[i]);
            char ch2=toupper(s[i]);

            helper(i+1, temp+ch1, s);
            helper(i+1, temp+ch2, s);
        }
    }

    }
};