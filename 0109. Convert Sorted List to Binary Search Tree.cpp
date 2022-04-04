//method 1: using create sorted array...same as 108
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        vector<int> nums;
        
        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        
        return helper(nums,0,nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums, int start, int end){
      //base case
      if(start > end) return NULL;
      
      int mid=start + (end-start)/2;
      
      TreeNode* root = new TreeNode(nums[mid]);
      
      root->left = helper(nums,start,mid-1);
      root->right = helper(nums,mid+1,end);
      
      return root;
    }
};



class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head,NULL);
    }
    
    TreeNode* helper(ListNode* head, ListNode* tail){
        //base case
        if(head==tail) return NULL;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        //find mid of linked list
        while(fast!=tail && fast->next!=tail){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        TreeNode* root=new TreeNode(slow->val);
        
        root->left = helper(head,slow);
        root->right = helper(slow->next,tail);
        
        return root;
    }
};