vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> res;
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                dfs(i,res,visited,adj);
            }
        }
        return res;
    }
    
    void dfs(int node, vector<int>& res,vector<int>& visited,vector<int> adj[]){
        res.push_back(node);
        visited[node]=1;
        
        for(auto i:adj[node]){
            if(visited[i]==0){
                dfs(i,res,visited,adj);
            }
        }
    }