#include <bits/stdc++.h>
#include "bt.cpp"
using namespace std;

// void my_left_view(Node* node){
//     if(node==NULL)
//         return;

//     printf("%d ", node->data);

//     if(node->left!=NULL)
//         my_left_view(node->left);

//     if(((!node->left) && (node->right!=NULL)) || ((!node->left->left) && (!node->left->right) && (node->right)))
//         my_left_view(node->right);
// }


// recursive
void util(Node* node, int level, int *max_level){
    if(!node)
        return;

    if(level > *max_level){
        printf("%d ", node->data);
        *max_level = level;
    }

    util(node->left, level+1, max_level);
    util(node->right, level+1, max_level);
}

void r_left_view(Node* root){
    int max_level = 0;
    util(root, 1, &max_level);
}


// iterative
void q_left_view(Node* node){
    if(!node){
        printf("%s", bt_mt_msg);
        return;
    }

    queue<Node*> q;
    q.push(node);

    while(!q.empty()){
        int n = q.size();

        for(int i=1; i<=n; i++){
            Node* temp = q.front();
            q.pop();

            if(i==1)
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

    root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->right->left = create_node(4);
    root->right->right = create_node(5);
    root->right->left->left = create_node(6);
    root->right->left->right = create_node(7);
    root->right->left->right->right = create_node(8);

    printf("Left-View using Recursion: ");  r_left_view(root);  printf("\n");
    printf("Left-View using Queue    : ");  q_left_view(root);  printf("\n");

    return 0;
}