/* Node structure  used in the program
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

/*  Function which returns the  root of the flattened linked list. */
Node *mergeTwoLists(Node *head1, Node *head2)
{
    Node *tmp = new Node(0);
    Node *res = tmp;

    while (head1 and head2)
    {
        if (head1->data < head2->data)
        {
            tmp->bottom = head1;
            tmp = tmp->bottom;
            head1 = head1->bottom;
        }
        else
        {
            tmp->bottom = head2;
            tmp = tmp->bottom;
            head2 = head2->bottom;
        }
    }

    if (head1)
    {
        tmp->bottom = head1;
    }
    else
    {
        tmp->bottom = head2;
    }

    return res->bottom;
}

Node *flatten(Node *root)
{
    if (!root or !root->next)
        return root;
    root->next = flatten(root->next);
    root = mergeTwoLists(root, root->next);
    return root;
}