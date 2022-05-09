class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        //base case
        if(n%2==1) return false;
        
        for(char ch:s){
            
            //open bracket 
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            //close bracket
            else{
                char temp;
                
                //first check the stack & pop
                if(st.size()>0){
                    temp=st.top();
                    st.pop();
                }
                else{
                    return false;
                }
                
                //compare
                if( (temp=='(' && ch==')' ) ||
                    (temp=='{' && ch=='}' ) ||
                    (temp=='[' && ch==']' ) ){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        
        //stack is empty
        if(st.size()==0) {
            return true;
        }
        else return false;
    }
};

/*
1. only 6-type of brackets
2. round, curly, square brackets (open-close)
3. n=s.size()
4. n=odd then it is always false
5. stack= last in first out
6. (()
*/