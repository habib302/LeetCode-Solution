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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        //base case
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* curr=new ListNode(0);
        ListNode* prev=new ListNode(0);
        ListNode* head1=new ListNode(0);       
        
        prev=head;
        curr=head->next;
        head1=head;
        
        while(1){
            
            int temp=prev->val;
            prev->val=curr->val;
            curr->val=temp;
            
            //1st update previous
            if(curr->next==NULL){
                return head1;
            }
            else{
                prev=curr->next;
            }
            
            //2nd update current
            if(prev->next==NULL){
                return head1;
            }
            else{
                curr=prev->next;
            }
        }
    }
};