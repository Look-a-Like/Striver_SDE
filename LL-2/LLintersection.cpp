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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int n = 0, m = 0;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while (temp1 != NULL)
        {
            n++;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            m++;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        if (m > n)
        {
            int diff = m - n;
            for (int i = 0; i < diff; i++)
            {
                temp2 = temp2->next;
            }
        }
        else
        {
            int diff = n - m;
            for (int i = 0; i < diff; i++)
            {
                temp1 = temp1->next;
            }
        }
        while (temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
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
    int n, m, k;
    cin >> n >> m >> k;
    int x;
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    ListNode *head3 = NULL;
    ListNode *temp1 = head1;
    ListNode *temp2 = head2;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        insert(head3, x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insert(head1, x);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        insert(head2, x);
    }
    ListNode *temp1 = head1;
    if (temp1)
    {
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = head3; // Link head1 to the intersection list
    }

    ListNode *temp2 = head2;
    if (temp2)
    {
        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = head3; // Link head2 to the intersection list
    }
    Solution object;
    ListNode *ans = object.getIntersectionNode(head1, head2);
    if (ans == head3)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}