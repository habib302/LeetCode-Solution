class MedianFinder {
public:
    
    priority_queue<int> maxHeap;  //for left
    priority_queue<int, vector<int>, greater<int>> minHeap;  //for right
        
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size()==0 || maxHeap.top()>num){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        
        //balance the both 
        if(maxHeap.size() > minHeap.size()+1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
        if(minHeap.size() > maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
     double findMedian() {
         
      // Check if the size is odd
      if((maxHeap.size() + minHeap.size())%2 == 0){
        return (minHeap.top()+maxHeap.top())/2.0;
      }
         
      else{
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
      }
    }
};
