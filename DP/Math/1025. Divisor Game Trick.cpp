class Solution {
public:
    //trick
    bool divisorGame(int n) {
        //if n is even Alice always win
        
        if(n%2==0) return true;
        else return false;
    }
};