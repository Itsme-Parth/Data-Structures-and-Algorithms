//Function to reverse a linkedlist using recursion
void reverse(node *p)
{
    if (p == NULL)
    {
        head = p;
        return;
    }
    reverse(p->next);
    node *q = p->next;
    q->next = p;
    p->next = NULL;
}