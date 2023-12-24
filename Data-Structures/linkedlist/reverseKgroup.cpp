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

ListNode *reverse(ListNode *root, int k)
{
    ListNode *curr = root;
    ListNode *pre = NULL;

    while (k-- && curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    if (curr != NULL)
    {
        root->next = curr;
    }
    return pre;
}

ListNode *reverseKGroup(ListNode *&head, int k)
{
    if (head->next == NULL || head == NULL)
    {
        return head;
    }

    ListNode *curr = head;
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    int loop = count / k;

    ListNode *prev = NULL;

    for (int i = 0; i < loop; i++)
    {
        if (prev == NULL)
        {
            prev = head;
            head = reverse(head, k);
        }
        else
        {
            ListNode *temp = prev->next;
            prev->next = reverse(prev->next, k);
            prev = temp;
        }
    }
    return head;
}

void print(ListNode *head)
{
    ListNode *p = head;

    while (p != NULL)
    {
        cout << p->val << " -> " << flush;
        p = p->next;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(3);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    ListNode *ans = reverseKGroup(head, 2);
    print(head);

    return 0;
}