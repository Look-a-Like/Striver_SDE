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
    void reverseK(ListNode *&head, stack<int> &st, int k)
    {
        ListNode *temp = head;
        for (int i = 0; i < k; i++)
        {
            if (!temp)
                return;
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        stack<int> st;
        ListNode *temp = head;
        ListNode *temp1 = head;
        int i = 0;
        while (temp != NULL)
        {
            i++;
            st.push(temp->val);
            if (i % k == 0)
            {
                reverseK(temp1, st, k);
                if (temp->next)
                {
                    temp1 = temp->next;
                }
            }
            temp = temp->next;
        }
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
    Solution object;
    ListNode *ans = object.reverseKGroup(head, x);
    print(ans);
}