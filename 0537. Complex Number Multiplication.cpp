class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
      
      int n1=num1.size(),n2=num2.size();
      
      string a,b,c,d;
      
      //separate a and b
      for(int i=0;i<n1;i++){
        if(num1[i]=='+'){
          b = num1.substr(i+1,n1-2);
          break;
        }
        else{
          a = a+num1[i];
        }
      }
      
      //separate c and d
      for(int i=0;i<n2;i++){
        if(num2[i]=='+'){
          d = num2.substr(i+1,n2-2);
          break;
        }
        else{
          c = c+num2[i];
        }
      }
      
      //res = (ac-bd) + (bc+ad)i
      string res=to_string(stoi(a)*stoi(c) - stoi(b)*stoi(d))+ "+" + 
                 to_string(stoi(b)*stoi(c) + stoi(a)*stoi(d)) + "i";
        return res;
    }
};