class Solution {
public:
    string addBinary(string a, string b) {
        int index1=a.size()-1, index2=b.size()-1;
        
        int sum=0,carry=0;
        string res="";
        
        while(index1>=0 || index2>=0 || carry>0){
            
            sum=0;
            
            if(index1 >= 0){
                sum = sum + a[index1]-'0';
                index1--;
            }
            
            if(index2 >= 0){
                sum = sum + b[index2]-'0';
                index2--;
            }
            
            sum = sum + carry;
            
            //age carry...tarpor sum bair korbo
            //age sum ber korle sum er value change hoy jabe
            carry = sum /2;
            sum = sum % 2;
            
            res = to_string(sum) + res;
        }

        return res;
    }
};