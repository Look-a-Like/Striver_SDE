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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool carry = false;
        ListNode *ans = new ListNode();
        ListNode *current = ans;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        while (t1 != NULL && t2 != NULL)
        {
            int sum = t1->val + t2->val;
            if (carry)
            {
                sum++;
                carry = false;
            }
            if (sum > 9)
            {
                carry = true;
            }
            current->next = new ListNode(sum % 10);
            current = current->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        while (t1 != NULL)
        {
            if (carry)
            {
                if (t1->val == 9)
                {
                    current->next = new ListNode(0);
                    current = current->next;
                }
                else
                {
                    carry = false;
                    current->next = new ListNode(t1->val + 1);
                    current = current->next;
                }
            }
            else
            {
                current->next = new ListNode(t1->val);
                current = current->next;
            }
            t1 = t1->next;
        }
        while (t2 != NULL)
        {
            if (carry)
            {
                if (t2->val == 9)
                {
                    current->next = new ListNode(0);
                    current = current->next;
                }
                else
                {
                    carry = false;
                    current->next = new ListNode(t2->val + 1);
                    current = current->next;
                }
            }
            else
            {
                current->next = new ListNode(t2->val);
                current = current->next;
            }
            t2 = t2->next;
        }
        if (carry)
        {
            current->next = new ListNode(1);
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
    ListNode *head = object.addTwoNumbers(head1, head2);
    print(head);
}