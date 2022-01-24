bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(checkForCycle(i,visited,adj)){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool checkForCycle(int s,vector<int>& visited,vector<int> adj[]){
        //node & parent
        queue<pair<int,int>> q;
        
        //initial parent is -1
        q.push({s,-1});
        visited[s]=1;
        
        while(q.size()>0){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto i:adj[node]){
                if(visited[i]==0){
                    q.push({i,node});
                    visited[i]=1;
                }
                else if(parent != i){
                    return true;
                }
            }
        }
        return false;
    }