#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int x): val(x){}

    void insert(int x){
        Node* curr = this;
        while (true){
            if (x < curr->val){
                if (curr->left) curr = curr->left;
                else {curr->left = new Node(x); return;}
            } else {
                if (curr->right) curr = curr->right;
                else {curr->right = new Node(x); return;}
            }
        }
    }

    void inorder(){
        stack<Node*> st{};
        Node* curr = this;

        while (!st.empty() || curr){
            while (curr) {
                st.push(curr);
                curr = curr->left;
            };
            curr = st.top();
            st.pop();
            cout << curr->val << "->";
            curr = curr->right;
        }
        cout << endl;
    }
};

Node* deleteNode(Node* tree, int x){
    if (tree == nullptr) return nullptr;
    if (x < tree->val) {tree->left = deleteNode(tree->left, x); return tree;};
    if (x > tree->val) {tree->right = deleteNode(tree->right, x); return tree;};
    if (x ==tree->val){
        if (tree->left == nullptr){
            Node* temp = tree->right;
            delete tree;
            return temp;
        }
        if (tree->right == nullptr) {
            Node* temp = tree->left;
            delete tree;
            return temp;
        };

        Node* curr = tree->right;
        while (curr->left){
            curr = curr->left;
        }
        tree->val = curr->val;

        tree->right = deleteNode(tree->right, tree->val);
        return tree;
    }
    return tree;
}



int main(){
    Node* tree = new Node(8);
    tree->insert(4);
    tree->insert(10);
    tree->insert(5);
    tree->insert(3);
    tree->insert(9);
    tree->insert(20);

    cout << "Nodes inserted: 8-4-10-5-3-9-20" << endl;

    cout << "Inorder traversal: " << endl;
    tree->inorder();
    tree = deleteNode(tree, 10);

    cout << "Inorder after deleting 10:" << endl;
    tree->inorder();
}

