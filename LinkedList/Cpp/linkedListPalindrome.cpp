#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int val) { this->val = val; }
    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

bool solve(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}
bool isPalindrome(ListNode *head)
{
    ListNode *temp = head;
    vector<int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }
    return solve(arr);
}

int main()
{
    int n;
    cin >> n;
    ListNode *head = new ListNode(-1), *temp = head, *trail = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> temp->val;
        temp->next = new ListNode(-1);
        trail = temp;
        temp = temp->next;
    }
    trail->next = NULL;
    bool check = isPalindrome(head);
    if (check)
        cout << "LinkedList is a palindrome" << endl;
    else
        cout << "LinkedList is not a palindrome" << endl;
    return 0;
}