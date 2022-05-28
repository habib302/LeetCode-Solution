class Solution {
public:
    vector<string> res;
    
    bool isValid(string s1){
        //cout<<s1<<endl;
        if(s1.size()==0 || s1.size()>3) return false;
        if(s1.size()>1  && s1[0]=='0') return false;
        if(stoi(s1)>255) return false;
        
        return true;
    }
    
    void helper(int start, int dots,string temp, string s){
        
        //base case
        if(dots==3){
            
            //check last valid part
            if( isValid(s.substr(start)) ){
                res.push_back(temp+s.substr(start));
            }
            
            return ;
        }
        
        for(int i=start; i<s.size();i++){
            
            if( isValid(s.substr(start , i-start+1)) ){
                
                temp.push_back(s[i]);
                temp.push_back('.');
                
                //cout<<temp<<endl;
                
                helper(i+1, dots+1, temp,s);
                
                temp.pop_back();
            }
        }
        return ;
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        //base case
        if(s.size()<4 || s.size()>12) return res;
        
        helper(0,0, "",s);
        
        return res;
    }
};