//////////////////////////////////////// Linked List Implementation ///////////////////////////////////
///////////////////// insert and delete with call by value and call by reference //////////////////////

#include <iostream>

using namespace std;

class node
{
public:
    int info;
    node *link;
};

void print(node *start)
{
    if (start == NULL)
        cout << "Empty List..!" << endl;
    else
    {
        //node *p = start;
        while (start != NULL)
        {
            cout << start->info << " ";
            start = start->link;
        }
        cout << endl;
    }
}
#if 0
// passing pointer by value
node *insert(node *start, int num, int pos)
{
    if (start == NULL && pos > 0)
    {
        cout << "position not exist" << endl;
        return start;
    }
    if (pos == 0)
    { // inserting at 0th index
        node *temp = new node;
        temp->info = num;
        temp->link = start;
        start = temp;
        return start;
    }

    node *p;
    p = start;
    int loc = 0;
    while (loc != pos - 1)
    {
        p = p->link;
        loc++;
        if (p == NULL)
        {
            cout << "position not exist" << endl;
            return start;
        }
    }
    node *temp = new node();
    temp->info = num;
    temp->link = p->link;
    p->link = temp;
    return start;
}

node *deleteNum(node *start, int pos)
{
    if (start == NULL)
    {
        cout << "position not exist" << endl;
        return start;
    }
    if (pos == 0)
    {
        node *temp = start;
        start = start->link;
        free(temp);
        return start;
    }

    node *p, *temp;
    p = start;
    int loc = 0;
    while (loc != pos - 1)
    {
        p = p->link;
        loc++;
        if (p->link == NULL)
        {
            cout << "position not exist" << endl;
            return start;
        }
    }
    temp = p->link;
    p->link = p->link->link;
    free(temp);
    return start;
}
#endif

//passing pointer by reference
bool insert(node *&start, int num, int pos)
{
    if (start == NULL && pos > 0)
    {
        cout << "position not exist" << endl;
        return false;
    }
    if (pos == 0)
    { // inserting at 0th index
        node *temp = new node;
        temp->info = num;
        temp->link = start;
        start = temp;
        return true;
    }

    node *p;
    p = start;
    int loc = 0;
    while (loc != pos - 1)
    {
        p = p->link;
        loc++;
        if (p == NULL)
        {
            cout << "position not exist" << endl;
            return false;
        }
    }
    node *temp = new node();
    temp->info = num;
    temp->link = p->link;
    p->link = temp;
    return true;
}

bool deleteNum(node *&start, int pos)
{
    if (start == NULL)
    {
        cout << "position not exist" << endl;
        return false;
    }
    if (pos == 0)
    {
        node *temp = start;
        start = start->link;
        free(temp);
        return true;
    }

    node *p, *temp;
    p = start;
    int loc = 0;
    while (loc != pos - 1)
    {
        p = p->link;
        loc++;
        if (p->link == NULL)
        {
            cout << "position not exist" << endl;
            return false;
        }
    }
    temp = p->link;
    p->link = p->link->link;
    free(temp);
    return true;
}

int fetch(node *start, int pos)
{
    if (start == NULL)
    {
        cout << "Empty List ..!" << endl;
        return -1;
    }
    int loc = 0;
    node *p = start;
    while (loc != pos)
    {
        p = p->link;
        loc++;
        if (p == NULL)
        {
            cout << "position Does Not Exist ..!" << endl;
            return -1;
        }
    }
    return p->info;
}

int main()
{
    node *start = NULL;

    while (1)
    {
        cout << "1: insert"
             << "\t2: delete"
             << "\t3: fetch"
             << "\t4: print"
             << "\t5: exit" << endl;
        int n;
        cin >> n;
        int num, pos;
        switch (n)
        {
        case 1:
            cout << "num: ";
            cin >> num;
            cout << "pos: ";
            cin >> pos;
            insert(start, num, pos);
            break;
        case 2:
            cout << "position: ";
            cin >> pos;
            deleteNum(start, pos);
            break;
        case 3:
            cout << "position :";
            cin >> pos;
            num = fetch(start, pos);
            cout << num << endl;
            break;
        case 4:
            print(start);
            break;
        case 5:
            exit(1);
        default:
            cout << "invalid option !" << endl;
            break;
        }
    }
}