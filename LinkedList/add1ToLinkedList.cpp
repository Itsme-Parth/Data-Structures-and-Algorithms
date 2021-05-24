//to be completed
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};  

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        node = node->next;
    }
    cout << "\n";
}

class Solution
{
public
    Node *reverse(Node *head)
    {
        Node *curr = head, *prev = NULL, *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    Node *addOne(Node *head)
    {
        reverse(head);
        Node *curr = head;
        if (curr->data + 1 <= 9)
        {
            curr->data += 1;
            reverse(head);
            return head;
        }
        else
        {
            int carry;
            curr->data = 0;
            carry = 1;
            curr = curr->next;
            while (!carry && !curr)
            {
                if (carry->data)
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Node *head = new Node(s[0] - '0');
        Node *tail = head;
        for (int i = 1; i < s.size(); i++)
        {
            tail->next = new Node(s[i] - '0');
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}