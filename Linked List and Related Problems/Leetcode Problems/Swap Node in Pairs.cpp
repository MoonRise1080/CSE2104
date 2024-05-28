#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *root = NULL;

int List_Size()
{
    node *curr_node = root;
    int index = 0;
    while(curr_node != NULL)
    {
        index++;
        curr_node = curr_node -> next;
    }
    return index;
}

void insert_first(int val)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        temp -> next = root;
        root = temp;
    }

}

void insert_last(int val)
{
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;

    node *curr_node = root;

    if(root == NULL)
    {
        root = temp;
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

void insert_at(int val, int replacement)
{
    node *curr_node = root;
    node *prev_node;
    node *temp;
    temp = new node();
    temp -> data = val;
    temp -> next = NULL;

    if(root == NULL)
    {
        insert_first(val);
        return;
    }
    else if(root -> data == replacement)
    {
        insert_first(val);
        return;
    }
    while(curr_node != NULL)
    {
        prev_node = curr_node;
        curr_node = curr_node -> next;
        if(curr_node -> data == replacement)
        {
            prev_node -> next = temp;
            temp -> next = curr_node;
            break;
        }
    }
}

void delete_first()
{
    if(root != NULL)
        root = root -> next;
}

void delete_last()
{
    node *curr_node = root;
    if(curr_node == NULL)
    {
        return;
    }
    while(curr_node -> next -> next != NULL)
    {
        curr_node = curr_node -> next;
    }

    curr_node -> next = NULL;
}

void delete_at(int val)
{
    node *curr_node = root;
    node *prev_node = curr_node;
    node *prev_o_prev_node = NULL;

    if(root == NULL)
    {
        return;
    }
    else if(root -> data == val)
    {
        delete_first();
    }
    while(curr_node != NULL)
    {
        prev_o_prev_node = prev_node;
        prev_node = prev_node -> next;
        curr_node = prev_node -> next;

        if(prev_node -> data == val)
        {
            prev_o_prev_node -> next = curr_node;
        }
    }
}

void Printing()
{
    node *curr_node = root;

    while(curr_node != NULL)
    {
        cout << curr_node -> data << endl;
        curr_node = curr_node -> next;
    }
}

void Last_node()
{
    node *curr_node = root;

    while(curr_node -> next != NULL)
    {
        curr_node = curr_node -> next;
    }
    cout << curr_node -> data << endl;
}

void Previous_o_Last()
{
    node *curr_node = root;

    while(curr_node -> next -> next != NULL)
    {
        curr_node = curr_node -> next;
    }

    cout << curr_node -> data << endl;
}

void Linear_search(int val)
{
    node *curr_node = root;

    while(curr_node != NULL)
    {
        if(curr_node -> data == val)
        {
            cout << "Found" << endl;
            return;
        }
        curr_node = curr_node -> next;
    }

    cout << "Not found" << endl;
}

void Reverse_Printing(node *curr_node)
{
    if(curr_node != NULL)
    {
        Reverse_Printing(curr_node -> next);
        cout << curr_node -> data << endl;
    }
}

void Swap_node_in_pair()
{
    node *prev_node = root;
    node *curr_node;
    int temp;

    while(prev_node != NULL)
    {
        curr_node = prev_node -> next;
        temp = curr_node -> data;
        delete_at(temp);
        insert_at(temp, prev_node -> data);
        prev_node = prev_node -> next;
    }
}

int main()
{
    insert_last(1);
    insert_last(2);
    insert_last(3);
    insert_last(4);
    insert_last(5);
    insert_last(6);

    Swap_node_in_pair();
    Printing();
}
