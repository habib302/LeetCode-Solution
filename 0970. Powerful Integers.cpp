class Solution {
public:
    int getBiggestPower(int num,int bound){
        //base case
        if(num==1) return 1;
        
        int res=0;
        
        while(bound){
            bound = bound/num;
            res++;
        }
        
        return res;
    }
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        vector<int> res;
        set<int> set;
        
        int xExponent=getBiggestPower(x,bound);
        int yExponent=getBiggestPower(y,bound);
        
        //cout<<xExponent<<" "<<yExponent;
        
        for(int i=0;i<xExponent;i++){
            for(int j=0;j<yExponent;j++){
                
                int temp = pow(x,i) + pow(y,j);
                
                if(temp <= bound){
                    if(set.count(temp)){
                        continue;
                    }
                    else{
                        set.insert(temp);
                        res.push_back(temp);
                    }
                }
                
            }
        }
        
        return res;
    }
};