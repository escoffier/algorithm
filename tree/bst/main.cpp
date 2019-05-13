/*************************************************************************
        > File Name: main.cpp
        > Author:robbie
        > Mail: qunfengqiu@gmail.com
        > Created Time: Thu 14 Aug 2014 03:04:40 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node {
  node *lchild;
  node *rchild;
  int data;
  bool rvisited; // post-order use this flag
};

bool SearchBST(node *head, int element, node **result) {
  if (NULL == head) {
    *result = head;
    return false;
  }

  node *child = head;
  while (NULL != child) {
    *result = child;
    if (child->data == element) {
      return true;
    } else if (element < child->data) {
      child = child->lchild;
    } else {
      child = child->rchild;
    }
  }

  return false;
}

bool InsertBST(node **tree, int value) {
  node *child = *tree;
  // node *head = *tree;
  if (NULL == *tree) {
    child = new node;
    child->lchild = NULL;
    child->rchild = NULL;
    child->data = value;
    *tree = child;
    return true;
  }

  if (child->data == value) {
    std::cout << value << "already exist!" << std::endl;
    return false;
  }

  // node * child = tree;
  node *tailnode = child;
  while (NULL != child) {
    tailnode = child;
    if (child->data == value) {
      return false;
    } else if (value < child->data) {
      child = child->lchild;
    } else {
      child = child->rchild;
    }
  }

  child = new node;
  child->lchild = NULL;
  child->rchild = NULL;
  child->data = value;

  if (value < tailnode->data) {
    tailnode->lchild = child;
  } else {
    tailnode->rchild = child;
  }
  return true;
}

void LevelTranverse(node *head) {
  queue<node *> q;
  q.push(head);

  while (!q.empty()) {
    head = q.front();
    std::cout << head->data << std::endl;

    q.pop();

    if (NULL != head->lchild) {
      q.push(head->lchild);
    }

    if (NULL != head->rchild) {
      q.push(head->rchild);
    }
  }
}
// void InorderTranverse(node *head)
//{
//	if(head == NULL)
//		return;
//	InorderTranverse(head->lchild);
//    std::cout<<head->data<<" ";
//	InorderTranverse(head->rchild);
//}

#if 1
void PostorderTranverse1(node *head) {
  stack<node *> s;
  while (NULL != head || !s.empty()) {
    while (NULL != head) {
      head->rvisited = false;
      s.push(head);
      head = head->lchild;
    }

    if (!s.empty()) {
      head = s.top();

      if (NULL == head->rchild) {
        std::cout << "leaf node: " << head->data << std::endl;
        s.pop();
        head = head->rchild;
        continue;
      }

      if (head->rvisited) {
        std::cout << head->data << std::endl;
        s.pop();
        head = NULL;
      } else {
        head->rvisited = true;
        head = head->rchild;
      }
    }
  }
  std::cout << std::endl;
}

// Pre-order (NLR)
// 1. Check if the current node is empty or null.
// 2. Display the data part of the root (or current node).
// 3. Traverse the left subtree by recursively calling the pre-order function.
// 4. Traverse the right subtree by recursively calling the pre-order function.
void PreorderTranverse1(node *head) {
  stack<node *> s;
  while (head != NULL || !s.empty()) {
    if (head != NULL) {
      std::cout << head->data << " ";
      s.push(head);
      head = head->lchild;
    } else {
      head = s.top();
      s.pop();
      head = head->rchild;
    }
  }
  std::cout << std::endl;
}

void PreorderTranverse2(node *head) {
  if (NULL == head) {
    std::cout << "tree is empty" << std::endl;
    return;
  }

  stack<node *> s;
  s.push(head);
  while (!s.empty()) {
    head = s.top();
    std::cout << head->data << " ";

    s.pop();
    if (head->rchild != NULL) {
      s.push(head->rchild);
    }

    if (NULL != head->lchild) {
      s.push(head->lchild);
    }
  }

  std::cout << std::endl;
}

// Check if the current node is empty or null.
// Traverse the left subtree by recursively calling the in-order function.
// Display the data part of the root (or current node).
// Traverse the right subtree by recursively calling the in-order function.
void InorderTranverse(node *head) {
  if (NULL == head) {
    std::cout << "empty tree" << std::endl;
    return;
  }
  stack<node *> s;
  node *root = head;
  while (root != NULL || !s.empty()) {
    while (root != NULL) {
      s.push(root);
      root = root->lchild;
    }

    if (!s.empty()) {
      std::cout << s.top()->data << std::endl;
      root = s.top();
      s.pop();
      // std::cout<<root->data<<std::endl;
      root = root->rchild;
      // std::cout<<"right: "<<root<<std::endl;
    }
  }
}
#endif

void printarray(int a[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << a[i] << "  ";
  }
  std::cout << std::endl;
}
int main(int argc, char **argv) {
  // int a[] = {14, 13, 10, 8, 7, 6, 4 , 3, 1};
  int a[] = {14, 10, 13, 1, 7, 6, 4, 3, 8};
  node *tree = NULL;
  for (int i = 0; i < sizeof(a) / sizeof(int); ++i) {
    InsertBST(&tree, a[i]);
    // InorderTranverse(tree);
    // std::cout<<std::endl;
  }
  InorderTranverse(tree);
  // PreorderTranverse1(tree);
  std::cout << "***************" << std::endl;
  LevelTranverse(tree);
  // PreorderTranverse2(tree);
  std::cout << "post-order" << std::endl;
  PostorderTranverse1(tree);
  return 0;
}
