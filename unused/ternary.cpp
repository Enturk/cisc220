#include <iostream>
#include <stdlib.h>
#include <cassert>
using namespace std;

//This is a Ternary Search Tree, which you have never played with.
//It is designed like a binary search tree but each node can accept 
//a second key and has three children.  
//All values in the left sub-tree are smaller than key1
//All values in the right sub-tree are larger than key2
//All values in the center sub-tree are between key1 and key2

//Your task is to implement is_in and count_nodes
//which should check for a key in the tree
//and count the number of nodes in the tree respectively

struct Node {
    int key1;
    int key2;
    int num_keys;
    Node* left;
    Node* center;
    Node* right;
    Node* parent;

    Node(int value){
        key1 = value;
        num_keys = 1;
        left = 0;
        center = 0;
        right = 0;
        parent = 0;
    }

    void insert(int value){
        //with only one key we take the other spot
        if (num_keys == 1){
            if (value < key1){
                key2 = key1;
                key1 = value;
            } else {
                key2 = value;
            }
            num_keys = 2;
            return;
        }
        
        if (value == key1){
            return;
        }
        if (value == key2){
            return;
        }
        
        //with 2 keys we head to the appropriate child
        if (value < key1){
            if (left == 0){
                //create a new node as the left child
                Node* newNode = new Node(value);
                left = newNode;
                left->parent = this;
            } else {
                //pass it forward
                left->insert(value);
            }
        } else if (value > key2 ) {
            if (right == 0){
                //create a new node as the right child
                Node* newNode = new Node(value);
                right = newNode;
                right->parent = this;
            } else {
                //pass it forward
                right->insert(value);
            }
        } else {
            if (center == 0){
                Node* newNode = new Node(value);
                center = newNode;
                center->parent = this;
            } else {
                //pass it on
                center->insert(value);
            }
        }
        return;
    }

    void print(){
        cout << "I am a node" << endl;
        if (left != 0){
            left->print();
        }
        cout << key1 << endl;
        if (center != 0){
            center->print();
        }
        if (num_keys > 1){
            cout << key2 << endl;
        }
        if (right != 0){
            right->print();
        }
    }
    
    //Code these two functions:
    //Start here
    bool is_in(int value){
        //return true if the value is anywhere in this tree
    }
    
    int count_nodes(){
        //return the number of nodes in the 
        //ternary tree rooted at this node
    }
    //end here
};

int main() {
    srand(1984);
    Node* root = new Node(rand() % 1000);
    for(int i = 0; i < 20; i++){
        root->insert(rand() % 1000);
    }

    assert(root->count_nodes() == 12);
    assert(root->center->count_nodes() == 2);
    assert(root->right->count_nodes() == 9);
    assert(root->right->left->center->count_nodes() == 1);

    assert(root->is_in(519));
    assert(root->is_in(319));
    assert(root->is_in(66));
    assert(root->is_in(700));
    assert(!root->is_in(522));
    assert(!root->is_in(318));
    assert(!root->is_in(65));
    assert(!root->is_in(701));
    
    cout << "All tests pass" << endl;
}