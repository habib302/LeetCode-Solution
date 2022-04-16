class Solution {
public:
    //blacklist no, non-blacklist no from end
    unordered_map<int,int> map;
    set<int> set;
    int n1,top;
    
    Solution(int n, vector<int>& blacklist) {
        
        n1=blacklist.size();
        top=n-n1;
        
        //store all blacklist in a set
        for(int i=0;i<n1;i++){
            set.insert(blacklist[i]);
        }
        
        //decrease n by 1
        n--;
        
        //create the map
        for(int i=0;i<n1;i++){
            
            //first check blacklist[i] less than top
            if(blacklist[i] < top){
                
                //check until n is not blacklist
                while(set.count(n)){
                    n--;
                }
                
                map[blacklist[i]]=n;
                n--;
            }
        }
    }
    
    int pick() {
        
        int randomIndex = rand()% top;
        
        if(map.count(randomIndex)){
            return map[randomIndex];
        }
        
        return randomIndex;
    }
};