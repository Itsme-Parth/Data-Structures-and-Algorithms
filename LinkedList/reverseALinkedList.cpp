#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *next;
    int data;
};
node *head = NULL;
void reverse()
{
}
//inserting node from the end
void insertNode(int val)
{
    node *temp;
    temp->data = val;
    temp->next = head;
    head = temp;
}
//Printing the Linked List
void printLinkedList()
{
    
}
//Deleting a node in the Linked List
void deleteNode()
{
}
int main()
{

    return 0;
}