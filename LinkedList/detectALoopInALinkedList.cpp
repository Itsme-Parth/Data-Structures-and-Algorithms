class Solution
{
public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        Node *slow = head, *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;       //slow pointer
            fast = fast->next->next; //fast pointer moves twice as fast as the slow pointer
            if (slow == fast)
                return true;
        }
        return false;
    }
};