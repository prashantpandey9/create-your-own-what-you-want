#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc ;
#define tc ll t sc cin >> t sc while (t--)
#define fast ios::sync_with_stdio(false)
#define spyder cin.tie(NULL)

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    cout << "Inorder Tree Traversal: ";
    preorderTraversal(root);
    cout << endl;
    return 0;
}