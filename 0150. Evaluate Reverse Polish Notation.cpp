class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        int val1,val2;
        
        for(auto token:tokens){
            
            if(token=="+" || token=="-" || token=="*" || token=="/"){
                
                val2=st.top() ; st.pop();
                val1=st.top() ; st.pop();
                
                if(token=="+")      {st.push(val1+val2);}
                else if(token=="-") {st.push(val1-val2);}
                else if(token=="*") {st.push(val1*val2);}
                else                {st.push(val1/val2);}
            }
            
            else{
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};