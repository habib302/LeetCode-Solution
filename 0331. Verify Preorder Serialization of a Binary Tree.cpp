class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> s;
        string s1;
        
        //split the preOrder when ','
        for(char ch:preorder){
            if(ch==','){
                s.push_back(s1);
                cout<<s1<<" ";
                s1="";
            }else{
                s1+=ch;
            }
        }
        //push the last one
        s.push_back(s1);
        
        int node=1;
        
        for(int i=0;i<s.size();i++){
            
            //decrease the node
            node--;
            
            //check node is negative
            if(node<0) return false;
            
            //update node
            if(s[i]!="#"){
                node +=2;
            }
        }
        
        return (node==0) ? true : false;
    }
};