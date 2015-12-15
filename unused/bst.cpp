#include <iostream>
#include <stdlib.h>
#include <cassert>
using namespace std;

//This is a standard Binary Search Tree,
//with rotate_left and rotate_right (no remove).
//Your job is to implement make_max_root which should use rotations
//to reshape the BST with the largest node as the root
//It should still be a BST and no node should be lost

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value){
        data = value;
        left = 0;
        right = 0;
        parent = 0;
    }
    
    ~Node(){
        if (left != 0){
            delete left;
        }
        if (right != 0){
            delete right;
        }
    }
    
    void insert(int value){
        if (value < data){
            if (left == 0){
                //create a new node as the left child
                Node* newNode = new Node(value);
                left = newNode;
                left->parent = this;
            } else {
                //pass it forward
                left->insert(value);
            }
        } else if (value > data) {
            if (right == 0){
                //create a new node as the right child
                Node* newNode = new Node(value);
                right = newNode;
                right->parent = this;
            } else {
                //pass it forward
                right->insert(value);
            }
        }
    }
    
    Node* min(){
        if (left == 0){
            return this;
        }
        return left->min();
    }
    
    Node* max(){
        if (right == 0){
            return this;
        }
        return right->max();
    }
    
    Node* next(){
        if (right != 0){
            return right->min();
        }
        Node* current = this;
        Node* above = parent;
        while(above != 0 && current == above->right){
            current = above;
            above = above->parent;
        }
        return above;
    }
    
    Node* prev(){
        if (left != 0){
            return left->max();
        }
        Node* current = this;
        Node* above = parent;
        while(above != 0 && current == above->left){
            current = above;
            above = above->parent;
        }
        return above;
    }

    void print(){
        if (left != 0){
            left->print();
        }
        cout << data << endl;
        if (right != 0){
            right->print();
        }
    }
    
    Node* rotate_right(){
        if (this->left == 0){
            return this;
        }
        
        Node* grand_parent = this->parent;
        Node* replacement = this->left;
        if (grand_parent != 0){
            if (this == grand_parent->left){
                grand_parent->left = replacement;
            } else {
                grand_parent->right = replacement;
            }
        }
        this->parent = replacement;
        this->left = replacement->right;
        replacement->right = this;
        replacement->parent = grand_parent;
        return replacement;
    }
    
    Node* rotate_left(){
        if (this->right == 0){
            return this;
        }
        
        Node* grand_parent = this->parent;
        Node* replacement = this->right;
        if (grand_parent != 0){
            if (this == grand_parent->right){
                grand_parent->right = replacement;
            } else {
                grand_parent->left = replacement;
            }
        }
        this->parent = replacement;
        this->right = replacement->left;
        replacement->left = this;
        replacement->parent = grand_parent;
        return replacement;
    }
    
    int count_nodes(){
        int answer = 1;
        if (left != 0){
            answer += left->count_nodes();
        }
        if (right != 0){
            answer += right->count_nodes();
        }
        return answer;
    }
    

    //Code this function, return the new root at the end
    Node* make_max_root(){
    //Start editing here
    
        return this; //return the new root please
    //Stop editing here
    }

};

int main() {
    srand(1983);
    
    Node* root = new Node(rand() % 1000);
    for(int i = 0; i < 20; i++){
        root->insert(rand() % 1000);
    }
    
    root = root->make_max_root();
    assert(root->data == 980);
    assert(root->count_nodes() == 20);
    assert(root->right == 0);

    cout << "All tests pass" << endl;
}