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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode *ans = new ListNode();
        ListNode *current = ans;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val < temp2->val)
            {
                current->next = new ListNode(temp1->val);
                current = current->next;
                temp1 = temp1->next;
            }
            else
            {
                current->next = new ListNode(temp2->val);
                current = current->next;
                temp2 = temp2->next;
            }
        }
        while (temp1 != NULL)
        {
            current->next = new ListNode(temp1->val);
            current = current->next;
            temp1 = temp1->next;
        }
        while (temp2 != NULL)
        {
            current->next = new ListNode(temp2->val);
            current = current->next;
            temp2 = temp2->next;
        }
        ans = ans->next;
        return ans;
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
    int n, m;
    cin >> n >> m;
    int x;
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
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
    print(head1);
    print(head2);
    Solution object;
    ListNode *head = object.mergeTwoLists(head1, head2);
    print(head);
}