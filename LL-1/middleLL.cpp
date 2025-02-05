#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *temp = head;
        int n = 0;
        if (head == NULL)
        {
            return NULL;
        }
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < n / 2; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
};

void insert(ListNode *&head, int x)
{
    if (head == NULL)
    {
        head = new ListNode(x);
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new ListNode(x);
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int x;
    ListNode *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(head, x);
    }
    print(head);
    Solution object;
    head = object.middleNode(head);
    print(head);
}