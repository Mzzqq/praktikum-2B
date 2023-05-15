#include <iostream>

using namespace std;

// Binary Tree Node
struct Node {
    int val; // value
    Node* left; // left child
    Node* right; // right child
    
    // constructor
    // menginisialisasi node dengan value v, left child dan right child null
    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

// membuat binary tree dari input user
Node* buildTree() {
    int val;
    cout << "Masukkan nilai root: ";
    cin >> val;

    // jika input -1, maka node tersebut null
    Node* root = new Node(val);
    Node* nodes[1000]; 
    nodes[0] = root;
    int front = 0, rear = 0;
    
    // menggunakan BFS untuk membangun binary tree
    while (front <= rear) {
        Node* curr = nodes[front];
        int left_val, right_val;
        cout << "Masukkan nilai left child dari " << curr->val << " (atau -1 jika NULL): ";
        cin >> left_val;
        
        // jika input -1, maka node tersebut null
        if (left_val != -1) {
            curr->left = new Node(left_val);
            nodes[++rear] = curr->left;
        }

        cout << "Masukkan nilai right child dari " << curr->val << " (atau -1 jika NULL): ";
        cin >> right_val;
        
        // jika input -1, maka node tersebut null
        if (right_val != -1) {
            curr->right = new Node(right_val);
            nodes[++rear] = curr->right;
        }
        front++; // menggeser ke node selanjutnya
    }
    return root;
}


// fungsi untuk mencari minimum depth dari binary tree
int minDepth(Node* root) {
    if (!root) return 0; // jika root null, maka depth 0

    Node* nodes[1000];
    int depths[1000];
    int front = 0, rear = 0;
    nodes[rear] = root;
    depths[rear] = 1; 
    
    // menggunakan BFS untuk mencari minimum depth
    while (front <= rear) {
        Node* curr = nodes[front];
        int depth = depths[front];
        front++; // menggeser ke node selanjutnya
        
        // jika node merupakan leaf, maka return depth
        if (!curr->left && !curr->right) {
            return depth;
        }

        // jika bukan leaf, maka tambahkan depth dan node child ke queue
        if (curr->left) {
            nodes[++rear] = curr->left;
            depths[rear] = depth + 1;
        }

        // jika bukan leaf, maka tambahkan depth dan node child ke queue
        if (curr->right) {
            nodes[++rear] = curr->right;
            depths[rear] = depth + 1;
        }
    }
    return 0;
}

int main() {
    Node* root = buildTree();

    int min_depth = minDepth(root);
    cout << "depth minimum dari binary tree: " << min_depth << endl;

    return 0;
}
