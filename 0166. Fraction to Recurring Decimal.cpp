class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        //initialization
        string res="";
        
        //to store <rem, length of string>
        unordered_map<long,int> map;
        
        //base case
        if(numerator==0) return "0";
        
        
        //check numerator or denominator is negative
        if(numerator < 0 && denominator <0){
            //if both are negative do nothing
        }
        else if(numerator < 0 || denominator <0){
            res += '-';
        }
        
        long num= labs(numerator), deno= labs(denominator);
        
        long quo=num / deno;
        long rem=num % deno;
        
        res += to_string(quo);
        
        if(rem==0) return res;
        

        //add . to res because fraction is started
        res += '.';
        
        while(rem != 0){
            
            //check if rem is present in map
            if(map.find(rem) != map.end()){
                int pos=map[rem];
                res.insert(pos,"(" );
                res += ")";
                break;
            }
            else{
                map[rem]=res.size();
                rem = rem * 10;
                
                quo = rem / deno;
                rem = rem % deno;
                res += to_string(quo);
            }
        }
        
        return res;
    }
};