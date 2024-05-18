#include <bits/stdc++.h>
using namespace std;


void menu()
{
    cout << "0. Menu" << endl;
    cout << "1. Insert first" << endl;
    cout << "2. Insert last" << endl;
    cout << "3. Insert anywhere" << endl;
    cout << "4. Delete first" << endl;
    cout << "5. Delete last" << endl;
    cout << "6. Delete anywhere" << endl;
    cout << "7. Print list" << endl;
    cout << "8. Linear search" << endl;
    cout << "9. Last node" << endl;
    cout << "10. Previous of last node" << endl;
    cout << "11. List size" << endl;
    cout << "12. List rotation anti clock wise" << endl;
}


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
    while(curr_node != NULL)
    {
        prev_node = curr_node;
        curr_node = curr_node -> next;
        if(prev_node -> data == replacement)
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

void List_rotation(int times)
{
    node *curr_node = root;
    for(int i = 0; i < times; i++)
    {
        insert_last(curr_node -> data);
        delete_first();
        curr_node = curr_node -> next;
    }
}

int main()
{
    int val, choice, replacement, index;

    menu();

    while(1)
    {
        cout << "Input choice: ";
        cin >> choice;

        if(choice == 0)
        {
            menu();
        }
        else if(choice == 1)
        {
            cout << "Insert first: ";
            cin >> val;
            insert_first(val);
        }
        else if(choice == 2)
        {
            cout << "Insert last: ";
            cin >> val;
            insert_last(val);
        }
        else if(choice == 3)
        {
            cout << "Insert Value: ";
            cin >> val;
            cout << "Next to: ";
            cin >> replacement;
            insert_at(val, replacement);
        }
        else if(choice == 4)
        {
            cout << "Delete first" << endl;
            delete_first();
        }
        else if(choice == 5)
        {
            cout << "Delete last";
            delete_last();
        }
        else if(choice == 6)
        {
            cout << "Delete at: ";
            cin >> val;
            delete_at(val);
        }
        else if(choice == 7)
        {
            cout << "Printing list: "  << endl;
            Printing();
        }
        else if(choice == 8)
        {
            cout << "Enter a value: ";
            cin >> val;
            Linear_search(val);
        }
        else if(choice == 9)
        {
            cout << "Last node: ";
            Last_node();
        }
        else if(choice == 10)
        {
            cout << "Previous of last node: ";
            Previous_o_Last();
        }
        else if(choice == 11)
        {
            cout << "List size: ";
            val = List_Size();
            cout << val << endl;
        }
        else if(choice == 12)
        {
            cout << "Rotation count: ";
            cin >> val;
            List_rotation(val);
        }
        else if(choice == -1)
        {
            break;
        }

        cout << endl;

    }

    return 0;
}
