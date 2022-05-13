class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> set;
        queue<string> q;
        int level=0;
        
        for(auto word:wordList){
            set.insert(word);
        }
        
        //present
        if(set.find(endWord) != set.end()){
            //continue
        }
        else{
            return false;
        }
        
        //start bfs
        q.push(beginWord);
        
        while(q.size()>0){
            
            level++;
            int n=q.size();
            
            while(n--){
                string curr=q.front();
                q.pop();
                
                
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    
                    //try all possible combination
                    for(char c='a' ; c<='z';c++){
                        
                        //change the i-th character
                        temp[i]=c;
                        
                        //skip the same word
                        if(temp==curr) continue;
                        
                        //endWord found
                        if(temp==endWord) return level+1;
                        
                        //check in the set
                        if(set.find(temp) != set.end()){
                            q.push(temp);
                            set.erase(temp);//if we won't erase we enter in a loop
                            
                        }
                    }
                }
            }
        }
        return 0;
    }
};