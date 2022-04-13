#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinarySearchTree{
    private:
        Node* root;

        void insertNode(Node *&tree, int data){
            if(tree == NULL){
                tree = new Node;
                tree->data = data;
                tree->left = NULL;
                tree->right = NULL;
            }else if(data < tree->data){
                insertNode(tree->left,data);
            }else{
                insertNode(tree->right,data);
            }
        }

        void printInOrder(Node *tree){
            if(tree == NULL){
                return;
            }
            printInOrder(tree->left);
            cout << tree->data << ", ";
            printInOrder(tree->right);
        }

        int treeLength(Node *tree){
            if(tree==NULL){
                return 0;
            }
            return 1+treeLength(tree->left)+treeLength(tree->right);
        }

        bool findNode(Node *tree, int data){
            if(tree==NULL){
                return false;
            }

            if(tree->data == data){
                return true;
            }else if(data < tree->data){
                return findNode(tree->left,data);
            }else{
                return findNode(tree->right,data);
            }
        }

        Node* retrieveNode(Node *tree, int data){
            if(tree==NULL){
                return NULL;
            }

            if(tree->data == data){
                return tree;
            }else if(data < tree->data){
                return retrieveNode(tree->left,data);
            }else{
                return retrieveNode(tree->right,data);
            }
        }

        void deleteNode(Node *&tree, int data){
            if(tree == NULL){
                return;
            }
            if(tree->data == data){
                if(tree->left == NULL && tree->right == NULL){
                    delete tree;
                    tree = NULL;
                }else if(tree->left != NULL){
                    int maxLeftNode = findMaxNode(tree->left);
                    tree->data = maxLeftNode;
                    deleteNode(tree->left,maxLeftNode);
                }else{
                    int minRightNode = findMinNode(tree->right);
                    tree->data = minRightNode;
                    deleteNode(tree->right,minRightNode);
                }
            }else if(tree->data < data){
                deleteNode(tree->right,data);
            }else{
                deleteNode(tree->left,data);
            }
        }

        int findMinNode(Node *tree){
            if(tree == NULL){
                return -1;
            }else if(tree->left == NULL){
                return tree->data;
            }else{
                return findMinNode(tree->left);
            }
        }

        int findMaxNode(Node *tree){
            if(tree == NULL){
                return -1;
            }else if(tree->right == NULL){
                return tree->data;
            }else{
                return findMaxNode(tree->right);
            }
        }

        void makeEmpty(Node *&tree){
            if(tree == NULL){
                return;
            }
            makeEmpty(tree->left);
            makeEmpty(tree->right);
            delete tree;
            tree = NULL;
        }

        int getHeight(Node *tree){
            if(tree == NULL){
                return 0;
            }
            int lsh = 1+getHeight(tree->left);
            int rsh = 1+getHeight(tree->right);

            if(lsh > rsh){
                return lsh;
            }else{
                return rsh;
            }
        }

        int countNodes(Node *tree){
            if(tree==NULL){
                return 0;
            }
            return 1+countNodes(tree->left)+countNodes(tree->right);
        }

       /* bool checkDup(Node* root, unordered_set<int> &s)
        {
        // If tree is empty, there are no
        // duplicates.
        if (root == NULL)
        return false;
    
        // If current node's data is already present.
        if (s.find(root->data) != s.end())
        return true;
    
        // Insert current node
        s.insert(root->data);
        
        // Recursively check in left and right
        // subtrees.
        return checkDup(root->left, s) ||
            checkDup(root->right, s);
        }*/

    public:
        BinarySearchTree(){
            root = NULL;
        }
        void insertNode(int data){
            insertNode(root,data);
        }

        void printInOrder(){
            printInOrder(root);
        }

        int treeLength(){
            treeLength(root);
        }

        Node* retrieveNode(int data){
            return retrieveNode(root,data);
        }

        bool findNode(int data){
            return findNode(root,data);
        }

        void deleteNode(int data){
            deleteNode(root,data);
        }

        int findMinNode(){
            findMinNode(root);
        }
        int findMaxNode(){
            findMaxNode(root);
        }

        bool isBalanced();

        void makeEmpty(){
            makeEmpty(root);
        }

        int getHeight(){
            getHeight(root);
        }

        bool isEmpty(){
            if(root == NULL){
                return true;
            }else{
                return false;
            }
        }

        int countNodes(){
            return countNodes(root);
        }
       /* bool checkDup(struct Node* root)
        {
            unordered_set<int> s;
            return checkDup(root, s);
        }*/
};


int main(){
    BinarySearchTree bst;
    bst.insertNode(5);
    bst.insertNode(2);
    bst.insertNode(7);
    bst.insertNode(1);
    bst.insertNode(8);
    bst.insertNode(3);
    bst.insertNode(6);

    bst.printInOrder();
   // bst.checkDup();

}

