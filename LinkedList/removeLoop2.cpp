/*This implementation includes function to remove the loop in a linkedlist without finding 
the number of nodes in the loop*/

bool detectAndRemoveLoop(struct Node *head)
{
    Node *slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
}
