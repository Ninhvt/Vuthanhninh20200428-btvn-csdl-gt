#include <iostream>
using namespace std;


template <typename N> class BinaryTree{


public:
    struct Node{
        N data;
        Node* left;
        Node* right;
        
        Node(N _data) : data(_data), left(NULL), right(NULL) {}
    };
    BinaryTree() {
        root = NULL; 
        size = 0 ; 
    }
    void insertParent(N t, Node* T){
        Node* Newnode = new Node(t);
        if (root == NULL) root = Newnode;
        else{
            Newnode->left = T;
            if (T->left == NULL)
                T->left = Newnode;
            else
                T->right = Newnode;
        }
        size++;
    }
    void insertLeftChild(N t, Node* T){
        Node* Newnode = new Node(t);
        T->left = Newnode;
        size++;
    }
    void insertRightChild(N t, Node* T){
        Node* Newnode = new Node(t);
        T->right = Newnode;
        size++;
    }
    Node* findNode(N t){
        Node *current = root;
        while (current != nullptr){
            if (current->data == t) return current;
            else if (current->data > t) current = current->left;
            else current = current->right;
        }
        return nullptr;
    }
    void deleteCurrentNode(Node *T){
        if (T->left == nullptr && T->right == nullptr){
            if (T->parent->left == T) T->parent->left = nullptr;
            else T->parent->right = nullptr;
        }
        else if (T->left != nullptr && T->right != nullptr){
            Node *successor = T->right;
            while (successor->left != nullptr) successor = successor->left;
            T->data = successor->data;
            deleteCurrentNode(successor);
        }
        else{
            Node *child = (T->left != nullptr) ? T->left : T->right;
            if (T->parent->left == T) T->parent->left = child;
            else T->parent->right = child;
            child->parent = T->parent;
        }
        delete T;
        size--;
    }
    void deleteLeftChild(Node *T){
        if (T != NULL) {
            Node *temp = T->leftChild;
            T->leftChild = NULL;
            deleteCurrentNode(temp);
        }
    }
    void deleteRightChild(Node *T){
        if (T != NULL) {
            Node* temp = T->rightChild;
            T->rightChild = NULL;
            deleteCurrentNode(temp);
        }
    }
    int GetSize(){
        return size;
    }
private:
    Node* root;
    int size;
};
int main(){
    BinaryTree<int> cnp;
    cout << cnp.GetSize() << endl;
    BinaryTree<int> :: Node  *treem1 ; 
    cnp.insertParent(1 , treem1);
    cout << cnp.GetSize() << endl;

    
}