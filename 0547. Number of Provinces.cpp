class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      int V=isConnected.size();
      vector<int> visited(V,0);
      int count=0;
      
  
      for(int i=0;i<V;i++){
        if(visited[i]==0){
          count++;
          bsf(i,visited,isConnected);
        }
      }
      return count;
    }
  
  void bsf(int src,vector<int>& visited, vector<vector<int>>& isConnected){
    queue<int> q;
    q.push(src);
    
    visited[src]=1;
    
    while(q.size()>0){
      int node=q.front();
      q.pop();
      
      for(int i=0;i<isConnected[node].size();i++){
        if(isConnected[node][i]==1 && visited[i]==0){
          visited[i]=1;
          q.push(i);
        }
      }
    }
    
  }
};