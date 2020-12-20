#include <cassert>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

struct TreeNode
{
  int value;
  struct TreeNode* left;
  struct TreeNode* right;
};

void traceBSTValidation(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
  std::string rootStr = root != nullptr ? std::to_string(root->value) : "nullptr";
  std::string minNodeStr = minNode != nullptr ? std::to_string(minNode->value) : "nullptr";
  std::string maxNodeStr = maxNode != nullptr ? std::to_string(maxNode->value) : "nullptr";

  std::cout << "Root: " << rootStr << ", Min: " << minNodeStr << ", Max: " << maxNodeStr << std::endl;
}

bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
  if (root == nullptr)
  {
    return true;
  }

  if ((minNode != nullptr && root->value <= minNode->value) ||
      (maxNode != nullptr && root->value >= maxNode->value))
  {
    return false;
  }

  return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

// InfoSys
// Level 2
bool validateBST(TreeNode* root)
{
  return isValidBST(root, nullptr, nullptr);
}

// Level 2
// Example:  
//      1
//     / \
//    2   3     ==> 1245367
//   / \ / \
//  4  5 6  7 
void preorder(TreeNode* root)
{
  if (root != NULL)
  {
    std::cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

// Level 3 - Salesforce
// Example:
//      1
//     / \
//    2   3     ==> 1234567
//   / \ / \
//  4  5 6  7 
std::vector<int> levelOrder(TreeNode* root)
{
  std::vector<int> v;
  std::queue<TreeNode*> q;
  if (root) q.push(root);
  while (!q.empty())
  {
    TreeNode* node = q.front();
    q.pop();
    if (node == nullptr) continue;
    v.push_back(node->value);
    q.push(node->left);
    q.push(node->right);
  }
  return v;
}

int getTreeHeight(TreeNode* root)
{
  if (root == nullptr)
  {
    return 0;
  }

  int lHeight = getTreeHeight(root->left);
  int rHeight = getTreeHeight(root->right);

  return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

// Level 3 - Google (Leetcode Easy)
// The diameter of a Binary Tree is defined as the
// "Number of nodes on the longest path between two leaf nodes".
// Example:
//            20                                  
//         /     \                              
//        15     30 
//       /  \      \                     
//      14  18     35
//         /  \    /
//        17  19  32
//     diameter ==> 7 
// Note we can traverse from 32 to 19
int diameter(TreeNode* root)
{
  if (root == nullptr) return 0;

  int leftHeight = getTreeHeight(root->left);
  int rightHeight = getTreeHeight(root->right);

  int leftDiameter = diameter(root->left);
  int rightDiameter = diameter(root->right);

  // Return max of either:
  // 1) Height of left subtree + height of right subtree + 1
  // 2) Diameter of left subtree
  // 3) Diameter of right subtree
  return std::max(leftHeight + rightHeight + 1, std::max(leftDiameter, rightDiameter));
}

int main()
{
  TreeNode seven = {7, nullptr, nullptr};
  TreeNode six = {6, nullptr, nullptr};
  TreeNode five = {5, nullptr, nullptr};
  TreeNode four = {4, nullptr, nullptr};
  TreeNode three = {3, &six, &seven};
  TreeNode two = {2, &four, &five};
  TreeNode one = {1, &two, &three};

  std::vector<int> answer = {1,2,3,4,5,6,7};
  assert(levelOrder(&one) == answer);

  return 0;
}