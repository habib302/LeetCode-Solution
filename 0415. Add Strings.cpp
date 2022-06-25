class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i=num1.size()-1, j=num2.size()-1, sum=0,carry=0;
        string res ="";
        
        while(i>=0 || j>=0 || carry>0){
            sum = 0;
            
            if(i>=0){
                sum = sum + num1[i]-'0';
                i--;
            }
            
            if(j>=0){
                sum = sum + num2[j]-'0';
                j--;
            }
            
            sum = sum+carry;
            
            //age carry & pore sum
            carry = sum/10;
            sum = sum % 10;
    
            res = to_string(sum) + res;
        }
        return res;
    }
};