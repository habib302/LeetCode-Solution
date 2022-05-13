class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        //base case
        if(n==0) return tasks.size();
        
        unordered_map<char,int> map;
        priority_queue<int> maxHeap;
        
        //create the frequency map
        for(char task:tasks){
            map[task]++;
        }
        
        for(auto i:map){
            maxHeap.push(i.second);
        }
        
        int cycleLength=n+1, lastCycleLength,res=0;
        
        //traverse until maxHeap.size greater than zero
        while(maxHeap.size()>0){
            
            lastCycleLength=maxHeap.size();
            
            vector<int> temp;
            
            //pop from maxHeap until cycleLength
            for(int i=0; i < cycleLength;i++){
                if(maxHeap.size()>0){
                    temp.push_back(maxHeap.top()-1);
                    maxHeap.pop();
                }
            }
            
            //again push to maxHeap where taskSize greater than zero
            for(auto t:temp){
                if(t>0) maxHeap.push(t);
            }
            
            //corner case: lastCycleLength
            res = res + (maxHeap.size()==0 ? lastCycleLength : cycleLength);
        }
        
        return res;
    }
};