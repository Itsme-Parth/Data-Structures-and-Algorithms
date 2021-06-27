/* 2 linked lists 
ptr1 = 1 -> 2  -> 3 -> 4 (m)
ptr2 = 5 -> 6 -> 7 -> 8 -> 9 (n)
output - 1 - 5 - 2 - 6 - 3 - 7 - 4 - 8 - 9
(m + n) 
1 - 2 - 3 - 4
5 - 6 - 7 - 8 - 9

1 -> 5 {
        next1 = 1.next  //1st linkedlist
        next2 = 5.next //2nd linkedlist
        }
        next1 || next2 != NULL
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head1;
Node *head2;
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void push(Node **head, int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if (*head == NULL) //head is NULL
    {
        *head = temp;
    }
    else
    {
        temp->next = *head;
        *head = temp;
    }
}

Node *mergeLL(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }
    if (head1 == NULL)
    {
        return head2;
    }
    else
        return head1;
    Node *currPtr1 = head1, *currPtr2 = head2;
    Node *next1 = currPtr1, *next2 = currPtr2;
    while (next1 != NULL || next2 != NULL)
    {
        /*
            1 2 3 4
            4 5 6
        */
        next1 = currPtr1->next;
        currPtr1->next = currPtr2;
        next2 = currPtr2->next;
        currPtr2->next = next1;
        currPtr1 = next1;
        currPtr2 = next2;
    }
    if (next1 != NULL)
    {
        currPtr1 = next1;
    }
    if (next2 != NULL)
    {
        currPtr2 = next2;
    }
    return head1;
}
int main()
{
    head1 = NULL;
    head2 = NULL;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        push(&head1, x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        push(&head2, x);
    }
    mergeLL(head1, head2);
    print(head1);
    return 0;
}
