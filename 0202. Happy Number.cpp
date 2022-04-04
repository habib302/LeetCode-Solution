class Solution {
public:
    
    int square(int num){
        //base case
        if(num<10){
            return num*num;
        }
        
        int sum=0,rem=0;
        
        while(num >0 ){
            rem = num % 10;
            num = num /10;
            sum = sum +(rem * rem);
        }
        
        cout<<sum;
        return sum;
    }
    
    bool isHappy(int n) {
        
        int temp=n;
        
        //Sum of squares of digits always ends in 1 or 89.
        while(1){
            
            if(temp==89){
                return false;
            }
            
            if(temp==1){
                return true;
            }
            
            temp = square(temp);
        }
    }
};