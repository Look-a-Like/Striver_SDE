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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        int n = 1;
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            n++;
        }
        k = k % n;
        if (k == 0)
            return head;
        ListNode *nt = head;
        for (int i = 0; i < n - k - 1; i++)
        {
            nt = nt->next;
        }
        ListNode *nh = nt->next;
        nt->next = nullptr;
        temp->next = head;
        return nh;
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
    };
    cin >> x;
    Solution object;
    ListNode *ans = object.rotateRight(head, x);
    print(ans);
}