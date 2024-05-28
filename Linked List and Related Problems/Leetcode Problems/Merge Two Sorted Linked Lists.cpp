#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *root1 = NULL;
node *root2 = NULL;
node *sorted_node = NULL;

void insert_last(int val, node *&tmproot)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;

    node *curr_node = tmproot;

    if(tmproot == NULL)
    {
        tmproot = temp;
    }

    else
    {
        while(curr_node -> next != NULL)
        {
            curr_node = curr_node -> next;
        }
        curr_node -> next = temp;
    }


}

void Printing(node *temproot)
{
    node *curr_node = temproot;

    while(curr_node != NULL)
    {
        cout << curr_node -> data << endl;
        curr_node = curr_node -> next;
    }
}

void Merge_list(node *tmp_root1, node *tmp_root2)
{
    node *curr_node1 = tmp_root1;
    node *curr_node2 = tmp_root2;

    while(1)
    {
        if(curr_node1 != NULL && (curr_node2 == NULL || curr_node1 -> data <= curr_node2 -> data))
        {
            insert_last(curr_node1 -> data, sorted_node);
            curr_node1 = curr_node1 -> next;
        }
        else if(curr_node2 != NULL && (curr_node1 == NULL || curr_node2 -> data < curr_node1 -> data))
        {
            insert_last(curr_node2 -> data, sorted_node);
            curr_node2 = curr_node2 -> next;
        }
        if(curr_node1 == NULL && curr_node2 == NULL)
        {
            return;
        }
    }
}

int main()
{
    insert_last(1, root1);
    insert_last(2, root1);
    insert_last(5, root1);
    insert_last(6, root1);
    insert_last(8, root1);
    insert_last(9, root1);
    insert_last(3, root2);
    insert_last(4, root2);
    insert_last(6, root2);
    insert_last(7, root2);

    cout << "Linked List 1:" << endl;
    Printing(root1);
    cout << "Linked List 2:" << endl;
    Printing(root2);
    cout << "Merged Linked List:" << endl;
    Merge_list(root1, root2);
    Printing(sorted_node);
}
