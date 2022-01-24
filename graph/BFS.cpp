vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
           
        vector<int> res;
        vector<int> visited(V,0);
        
        queue<int> q;
        q.push(0);
        visited[0]=1;
        
        while(q.size()>0){
            int node=q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto i:adj[node]){
                if(visited[i]==0){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        return res;
    }