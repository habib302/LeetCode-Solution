class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];
        
        //first create the adjacency matrix
        for(int i=0;i<edges.size();i++){
            
            int a=edges[i][0], b= edges[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<bool> visited(n,false);
        
        //call bfs function
        bfs(adj,visited,source);
        
        return visited[destination];
    }
    
    void bfs(vector<int> adj[], vector<bool>& visited, int source){
        
        queue<int> q;
        q.push(source);
        
        visited[source]=true;
        
        while(q.size()>0){
            
            int node=q.front();
            q.pop();
            
            for(auto i:adj[node]){
                
                if(visited[i]==false){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
};