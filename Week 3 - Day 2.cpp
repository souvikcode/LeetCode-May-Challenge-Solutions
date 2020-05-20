/*
If the number of nodes are odd:
   store the last node in a variable last_odd. Traverse from the beginning to the end of the lisked list, we    will connect the consecutive odd nodes together and the even nodes will be added the end of the list        starting from last_odd
   
If the number of nodes are even:
    store the last odd node in last_odd and the lst even in last_even. Traverse from beginning to end of the     linked list and connect consecutive odd position nodes together and link the even position nodes to the     end of the list, starting from last_odd.
    At the end connect last_even to the newly formed lisked list.

Time Complexity: O(nodes)
Space Complexity: O(1)

*/
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* last_odd;
        ListNode* last_even;
        int len = 0;
        ListNode* current = head;
        for(current = head; current != NULL;)
        {
            if(len % 2 != 0)
                last_even = current;
            else
                last_odd = current;
            len++;
             current = current->next;
        }
        if(len == 0)
             return head;
        //cout<<len<<endl;
        if(len%2 != 0)
        {
            ListNode* temp;
            current = head;
            for(int i=0; i<len; i++)
            {
                if(i%2!=0)
                {
                    
                    temp = current->next;
                    //cout<<current->val<<endl;
                    current->next = current->next->next;
                    last_odd->next = temp;
                    last_odd = temp;
                    last_odd->next = NULL;
                    current = current->next;
                    i++;
                }
            }
        }
        else
        {
            ListNode* temp;
            current = head;
            for(int i=0; i<len-1; i++)
            {
                if(i%2!=0)
                {
                    temp = current->next;
                    current->next = current->next->next;
                    last_odd->next = temp;
                    last_odd = temp;
                    last_odd->next = NULL;
                    current = current->next;
                    i++;
                }
            }
            last_odd->next = last_even;
        }
        return head;
    }
};
