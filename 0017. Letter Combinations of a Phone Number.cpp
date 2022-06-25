class Solution {
public:
    //map declare & initialize kore nibo
    unordered_map<char,string> map { {'2',"abc"}, {'3',"def"}, {'4',"ghi"},
                                     {'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"},
                                     {'8',"tuv"}, {'9',"wxyz"} };

    
    vector<string> res;
    
    vector<string> letterCombinations(string digits) {
       
        if(digits.size()==0) return res;
        
        helper(0,"", digits);
        
        return res;
    }
    
    void helper(int index, string temp, string digits){
        
        //base case
        if(index==digits.size()){
            res.push_back(temp);
            return ;
        }
        
        string curr=map[digits[index]];
        
        for(int i=0;i<curr.size();i++){
            
            temp.push_back(curr[i]);  //make choice
            
            helper(index+1, temp, digits);  //explore 
            
            temp.pop_back(); //back
        }
    }
};