class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int V=rooms.size();
      vector<int> visited(V,0);
      
      bsf(0,visited,rooms);
      
      for(auto i:visited){
        if(i==0){
          return false;
        }
      }
      
      return true;
      
    }
  void bsf(int src,vector<int>& visited, vector<vector<int>>& rooms){
    queue<int> q;
    q.push(src);
    
    visited[src]=1;
    
    while(q.size()>0){
      int node=q.front();
      q.pop();
      
      for(auto i:rooms[node]){
        if(visited[i]==0){
          visited[i]=1;
          q.push(i);
        }
      }
    }
    
  }
};