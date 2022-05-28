class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[n];
        vector<int> inDegree(n,0);
        
        for(auto p: prerequisites){
            int a=p[0], b=p[1];
            
            adj[a].push_back(b);
            inDegree[b]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<inDegree.size();i++){
            //cout<<i<<" ";
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        // for(auto i:adj[1]){
        //     cout<<i<<" ";
        // }
        
        int count=0;
        
        // while(q.size()>0){
        //     cout<<q.front()<<" ";
        //     q.pop();
        // }
        
        vector<int> res;
        
        while(q.size()>0){
            
            int qSize=q.size();
            
            for(int i=0;i<qSize;i++){
                
                int node = q.front();
                q.pop();
                
                res.push_back(node);
                
                //cout<<node<<" ";
                for(auto x:adj[node]){
                    inDegree[x]--;
                    
                    if(inDegree[x]==0){
                        q.push(x);
                    }
                }
                
            }
        }
        reverse(res.begin(), res.end());
        
        return (res.size()==n) ? res : vector<int>();
    }
};