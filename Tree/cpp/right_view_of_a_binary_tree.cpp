#include <bits/stdc++.h>
#include "bt.cpp"
using namespace std;


// recursive
void util(Node* node, int level, int *max_level){
    if(!node)
        return;

    if(level > *max_level){
        printf("%d ", node->data);
        *max_level = level;
    }

    util(node->right, level+1, max_level);
    util(node->left, level+1, max_level);
}

void r_right_view(Node* root){
    int max_level = 0;
    util(root, 1, &max_level);
}


// iterative
void q_right_view(Node* node){
    if(!node){
        printf("%s", bt_mt_msg);
        return;
    }

    queue<Node*> q;
    q.push(node);

    while(!q.empty()){
        int n = q.size();

        while(n--){
            Node* temp = q.front();
            q.pop();

            if(!n)
                printf("%d ", temp->data);

            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}


int main(){
    Node* root = NULL;
    
    // root = insert_node(root, 1);
    // root = insert_node(root, 2);
    // root = insert_node(root, 3);
    // root = insert_node(root, 4);
    // root = insert_node(root, 5);
    // root = insert_node(root, 6);
    // root = insert_node(root, 7);

    /*
                1
              /   \
             2     3
                 /   \
                4     5
              /   \
             6     7
                    \
                     8
    */

    root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->right->left = create_node(4);
    root->right->right = create_node(5);
    root->right->left->left = create_node(6);
    root->right->left->right = create_node(7);
    root->right->left->right->right = create_node(8);

    printf("Right-View using Recursion: ");  r_right_view(root);  printf("\n");
    printf("Right-View using Queue    : ");  q_right_view(root);  printf("\n");

    return 0;
}