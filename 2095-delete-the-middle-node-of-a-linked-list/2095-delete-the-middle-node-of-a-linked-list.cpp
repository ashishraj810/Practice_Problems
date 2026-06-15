
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
       if( head == NULL)
       return NULL;
       if(head->next == NULL)
       {
        // delete head;
        return NULL;
       }

       int size = 0;
       ListNode* temp = head;
       while(temp)
       {
        size++;
        temp = temp->next;
       } 
       int n = size/2;

         ListNode* current = head;
         ListNode *prev = NULL;
         for(int i = 0 ; i < n ; i++)
         {
            prev = current;
            current = current->next;
         }
         prev->next = current->next;
         delete current;
       

       return head;

    }

};