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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class Solution
{
public:
    //Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        map<int, int> mp;
        Node *prev = head, *curr = prev->next;
        mp[prev->data] = 1;
        while (curr)
        {
            if (mp.find(curr->data) != mp.end())
            {
                Node *temp = curr;
                curr = curr->next;
                delete temp;
                prev->next = curr;
            }
            else
            {
                mp[curr->data] = 1;
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}