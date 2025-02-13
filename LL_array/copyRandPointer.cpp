#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

int main()
{
    Node *head;
    int x = 0;
    while (x != -1)
    {
        cin >> x;
    }
}