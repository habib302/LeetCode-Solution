class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> res(n+1,0);
        int in=0,out=0;
        
        for(int i=0;i<trust.size();i++){
            in = trust[i][1];
            out = trust[i][0];
            
            res[in]++;
            res[out]--;
        }
        
        //return the index/label
        //res er zero count korbo na
        //1 thake suru korbo
        for(int i=1;i<res.size();i++){
            if(res[i] == n-1){
                return i;
            }
        }
        
        return -1;
    }
};