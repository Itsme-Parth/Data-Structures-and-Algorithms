#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *next;
    int data;
};
node *head = NULL;
//reverse a linked list (Iterative Method)
void reverseIterative()
{
    node *prev = NULL, *next = NULL, *curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
//inserting node from the beginning
void insertNode(int val)
{
    node *temp = new node();
    temp->data = val;
    temp->next = head;
    head = temp;
}
//Printing the Linked List
void printLinkedList()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}
//Deleting a node at the nth position in the Linked List
void deleteNode(int n)
{
    node *temp = head;
    if (n == 1)
    {
        head = temp->next;
        delete temp;
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}
int main()
{
    insertNode(5);//list --> 5
    insertNode(4);//list --> 4 5
    insertNode(3);
    insertNode(2);
    insertNode(1);
    insertNode(0);
    printLinkedList();
    deleteNode(1);
    printLinkedList();
    deleteNode(3);
    printLinkedList();
    reverseIterative();
    printLinkedList();
    return 0;
}