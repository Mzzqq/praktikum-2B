#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// BT Node
struct Node{
    int data;
    struct Node* left, *right;
};

// Function untuk mencari batas kedalam dalam binary tree
int minDepth(Node *root){
    if (root == NULL) // jika node kosong
        return 0;

    if (root->left == NULL && root->right == NULL) // jika node leaf
    return 1;

    int l = INT_MAX, r = INT_MAX;

    if (root->left) // rekursi pada left subtree
    l = minDepth(root->left);

    if (root->right) // rekursi pada right subtree 
    r = minDepth(root->right);

    return min(l , r) + 1; // return nilai minimum kedalaman subtree + 1
}

// Function untuk membuat binary tree baru
Node *newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

// Function untuk membuat binary tree berdasarkan input user
Node* buildTree(){
    int data;
    cout << "Masukkan nilai root nya: ";
    cin >> data;
    Node* root = newNode(data);

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* curNode = q.front();
        q.pop();

        cout << "Masukkan nilai left child dari " << curNode->data << " (-1 Jika tidak punya left child): ";
        int leftData;
        cin >> leftData;
        if(leftData != -1)
        {
            Node* leftChild = newNode(leftData);
            curNode->left = leftChild;
            q.push(leftChild);
        }

        cout << "Masukkan nilai right child dari " << curNode->data << " (-1 Jika tidak punya right child): ";
        int rightData;
        cin >> rightData;
        if(rightData != -1)
        {
            Node* rightChild = newNode(rightData);
            curNode->right = rightChild;
            q.push(rightChild);
        }
    }

    return root;
}

// Main Program
int main()
{
    Node* root = buildTree();
    cout <<"\nBatas kedalaman binary tree adalah: "<< minDepth(root);
    return 0;
}
