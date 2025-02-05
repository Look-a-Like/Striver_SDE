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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int x = 0;
        while (temp != NULL)
        {
            x++;
            temp = temp->next;
        }
        temp = head;
        if (x - n == 0)
        {
            ListNode *del = head;
            head = head->next;
            delete del;
            return head;
        }
        for (int i = 0; i < (x - n) - 1; i++)
        {
            temp = temp->next;
        }
        ListNode *del = temp->next;
        temp->next = del->next;
        delete del;
        return head;
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
    cin >> x;
    print(head);
    Solution object;
    head = object.removeNthFromEnd(head, x);
    print(head);
}