#include <iostream>
#include <stack>

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
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL)
        {
            slow = slow->next;
        }
        while (slow != NULL)
        {
            if (st.top() != slow->val)
            {
                return false;
            }
            slow = slow->next;
            st.pop();
        }
        return true;
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
    bool ans = object.isPalindrome(head);
    cout << ans;
}