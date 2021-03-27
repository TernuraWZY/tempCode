class Solution {
public:
    // head记录新链表头结点，tail记录新链表尾结点，pre记录dfs过程中上一次访问的非空节点
    Node *head, *pre, *tail;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return root;
        getTail(root);
        dfs(root);
        head->left = tail;
        tail->right = head;
        return head;
    }
    void dfs(Node *cur)
    {
        if(cur == nullptr)
            return;
        dfs(cur->left);
        // 获取链表头结点(达到最底处获取)
        if(head == nullptr)
            head = cur;
        if(pre != nullptr)
        {
            pre->right = cur;
            cur->left = pre;
        }
        pre = cur;
        dfs(cur->right);
    }
    // 获取链表尾结点(达到最底处获取)
    void getTail(Node *cur)
    {
        if(cur == nullptr)
            return;
        getTail(cur->right);
        if(tail == nullptr)
            tail = cur;
    }
};