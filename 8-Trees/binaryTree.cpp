#include<iostream>
#include<queue>
using namespace std;

class Node {
  public:

  int data;
  Node *left;
  Node *right;

  // Constructor
  Node(int data) {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

// Function to build a tree
Node* buildTree(Node *root) {

  cout << "Enter data: " << endl;
  int data;
  cin >> data;
  root = new Node(data);

  if (data == -1) {
    return NULL;
  }
  cout << "Enter data in left of: " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter data in right of: " << data << endl;
  root->right = buildTree(root->right);

  return root;
}

// Level order traversal
void levelOrderTraversal(Node *root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if (temp == NULL) {
      cout << endl;
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
    }
  }
}

// Inorder traveral -> LNR
void inorder(Node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
// Preorder traveral -> NLR
void preorder(Node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

// Postorder traveral -> LRN
void postorder(Node *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}

int main() {
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  Node *root = NULL;
  root = buildTree(root);
  cout << "Level order traversal of the tree: " << endl;
  levelOrderTraversal(root);
  cout << endl;
  cout << "Inorder traversal of the tree: " << endl;
  inorder(root);
  cout << endl;
  cout << "Preorder traversal of the tree: " << endl;
  preorder(root);
  cout << endl;
  cout << "Postorder traversal of the tree: " << endl;
  postorder(root);
  cout << endl;
  return 0;
}