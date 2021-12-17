/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//method 1: using stack
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        //base case
        if(head==NULL || head->next==NULL) return head;
        
        int len=1;
        ListNode* curr=head;
        stack<int> st;
        
        //step 1: first fill the stack
        while(curr != NULL){
            if(len>=left && len<=right){
                st.push(curr->val);
            }
            curr=curr->next;
            len++;
        }
        
        curr=head;
        len=1;
        
        //step 2: again traverse the list and change the value
        while(curr != NULL){
            if(len>=left && len<=right){
                curr->val=st.top();
                st.pop();
                
            }
            curr=curr->next;
            len++;
        }
        return head;
    }
};