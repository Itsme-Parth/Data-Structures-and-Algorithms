/* There are two ways to find the start of the loop

1. Find the nummber of nodes in the loop and then put one pointer at head and second at kth node
after head and the point where they meet is the starting point of the loop

2. We use the smae procedure the one we do to check if loop exists and then move slow to the head and move
fast and slow together. The point where they meet is the starting point of the loop */

//Function of the second approach
//Considering that the loop already exists
Node *detectStartpoint(Node *head)
{
    Node *slow = head, *fast = head;
    /*
        while (fast && fast -> next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
    */
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}