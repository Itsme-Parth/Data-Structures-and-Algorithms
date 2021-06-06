//Code to remove the loop from the linked list
//This implementation includes counting the number of nodes to find the starting point
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void removeLoop(struct Node *, struct Node *);
//detecting if a loop exists
bool detectAndRemoveLoop(struct Node *list)
{
    Node *slow = list, *fast = list;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            removeLoop(slow, list);
            return true;
        }
    }
    return false;
}
//removing the existing loop
void removeLoop(struct Node *loop_node, struct Node *head)
{
    //both pointers pointing to head
    Node *ptr1 = loop_node, *ptr2 = loop_node;
    int k = 0;
    //counting the numbers of node
    while (ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        k++;
    }
    //placing ptr1 at head and ptr2 at kth node after head
    ptr1 = head;
    for (int i = 0; i < k; i++)
    {
        ptr2 = ptr2->next;
    }
    //finding the starting point of the loop
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    //finding the last point of the loop
    while (ptr2->next != ptr1)
    {
        ptr1 = ptr1->next;
    }
    //ptr1 points at start and ptr2 points at the last
    ptr2->next = NULL;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

struct Node *newNode(int key)
{
    struct Node *temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int main()
{
    struct Node *head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    head->next->next->next->next->next = head->next->next;

    detectAndRemoveLoop(head);

    cout << "Linked List after removing loop \n";
    printList(head);
    return 0;
}
