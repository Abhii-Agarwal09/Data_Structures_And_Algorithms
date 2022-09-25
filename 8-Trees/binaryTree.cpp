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

// Insert into BST function
Node* insertIntoBST(Node* root, int d) {
  if (root == NULL) {
    root = new Node(d);
    return root;
  }
  if (root -> data > d) {
    root->left = insertIntoBST(root->left,d);
  } else {
    root->right = insertIntoBST(root->right,d);
  }
  return root;
}

// Function to take input for a binary tree
void takeInput(Node *&root) {
  int data;
  cin >> data;
  while(data != -1) {
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

// Function to search for a number in BST
bool searchBST(Node* root, int el) {
  // if (root == NULL) {
  //   return false;
  // }
  // if (root->data == el) {
  //   return true;
  // } 
  // if (root->data > el) {
  //   return searchBST(root->left, el); 
  // } else {
  //   return searchBST(root->right, el);
  // }

  // Iterative way
  Node* temp = root;

  while(temp != NULL) {
    if (temp->data == el) {
      return true;
    }
    if (temp->data > el) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }
  return false;
}

// Function to return max value from BST
Node* maxValue(Node *root) {
  Node *temp = root;
  while(temp->right != NULL) {
    temp = temp->right;
  }
  return temp;
}

// Function to return min value from BST
Node* minValue(Node *root) {
  Node *temp = root;
  while(temp->left != NULL) {
    temp = temp->left;
  }
  return temp;
}

// Function to delete a node from a BST
Node* deleteFromBST(Node *root, int val) {
  // base case
  if (root == NULL) {
    return root;
  }
  if (root-> data == val) {
    // 0 child
    if (root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    }

    // 1 child

    // Left child
    if (root->left != NULL && root->right == NULL) {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    // Right child
    if (root->left == NULL && root->right != NULL) {
      Node *temp = root->right;
      delete root;
      return temp;
    }

    // 2 child
    if (root->left != NULL && root->right != NULL) {
      // Option 1 -> get max value from left
      // int maxVal = maxValue(root->left)->data;
      // root->data = maxVal;
      // root->left = deleteFromBST(root->left, maxVal);
      // return root;

      // Option 2 -> get min value from right
      int minVal = minValue(root->right)->data;
      root->data = minVal;
      root->right = deleteFromBST(root->right, minVal);
      return root;
    }
  } else if (root->data > val) {
    root->left = deleteFromBST(root->left, val);
    return root;
  } else {
    root->right = deleteFromBST(root->right, val);
    return root;
  }
}

int main() {
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  // Node *root = NULL;
  // root = buildTree(root);
  // cout << "Level order traversal of the tree: " << endl;
  // levelOrderTraversal(root);
  // cout << endl;
  // cout << "Inorder traversal of the tree: " << endl;
  // inorder(root);
  // cout << endl;
  // cout << "Preorder traversal of the tree: " << endl;
  // preorder(root);
  // cout << endl;
  // cout << "Postorder traversal of the tree: " << endl;
  // postorder(root);
  // cout << endl;

  // Binary Search Tree
  // 10 8 21 7 27 5 4 3 -1
  // 50 20 70 10 30 90 110 -1
  Node* root = NULL;
  cout << "Enter data: " << endl;
  takeInput(root);
  levelOrderTraversal(root);
  cout << "Searching in BST" << endl;
  cout << searchBST(root, 7) << endl;
  cout << searchBST(root, 21) << endl;
  cout << searchBST(root, 2) << endl;
  
  root = deleteFromBST(root, 50);
  levelOrderTraversal(root); 
  return 0;
}