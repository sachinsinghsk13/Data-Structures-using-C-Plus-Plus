#include <iostream>
#include <queue>
using namespace std;

class Node;
class BinarySearchTree;

typedef Node node;
typedef Node *node_ptr;
typedef BinarySearchTree bst;
node_ptr create_new_node(int, int);

enum TraversalOrder
{
    INORDER,
    PREORDER,
    POSTORDER,
    BREADTHFIRST
};

class Node
{
  public:
    int key;
    int value;
    node_ptr left;
    node_ptr right;
    Node(int, int);
};

class BinarySearchTree
{
  private:
    node_ptr root;
    node_ptr insert(node_ptr root, int key, int value);
    node_ptr get(node_ptr root, int key);
    node_ptr remove(node_ptr root, int key, int &value);
    node_ptr get_highest_key_node(node_ptr);
    void inorder_traversal(node_ptr root);
    void breadth_first_traversal(node_ptr root);
  public:
    BinarySearchTree();
    void insert(int key, int value);
    int get(int key);
    int remove(int key);
    void traverse(TraversalOrder order);
};

int main()
{
    bst tree;
    int array[] = {54, 45, 63, 36, 51, 18, 39, 52};
    for (int i = 0; i < 8; i++)
        tree.insert(array[i], i * array[i]);
    tree.traverse(TraversalOrder::INORDER);
    cout << endl;
    cout << tree.remove(45) << endl;
    cout << endl;
    tree.traverse(TraversalOrder::BREADTHFIRST);
    return 0;
}
node_ptr create_new_node(int key, int data)
{
    return new Node(key, data);
}

node::Node(int key, int value)
{
    this->key = key;
    this->value = value;
    this->right = nullptr;
    this->left = nullptr;
}

bst::BinarySearchTree()
{
    this->root = nullptr;
}

/*Private */

node_ptr bst::insert(node_ptr root, int key, int value)
{
    if (root == nullptr)
        return create_new_node(key, value);
    else if (key < root->key)
        root->left = insert(root->left, key, value);
    else
        root->right = insert(root->right, key, value);
    return root;
}

node_ptr bst::get(node_ptr root, int key)
{
    if (root == nullptr)
        return root;
    else if (key == root->key)
        return root;
    else if (key < root->key)
        return get(root->left, key);
    else
        return get(root->right, key);
}

node_ptr bst::get_highest_key_node(node_ptr root)
{
    if (root->right != nullptr)
        return get_highest_key_node(root->right);
    return root;
}

node_ptr bst::remove(node_ptr root, int key, int &value)
{
    if (root == nullptr)
        return root;
    else if (key == root->key)
    {
        // node having both child
        if (root->left != nullptr && root->right != nullptr)
        {
            node_ptr max_key_node = get_highest_key_node(root->left);
            root->key = max_key_node->key;
            root->value = max_key_node->value;
            root->left = remove(root->left, root->key, value);
            return root;
        }
        // node have only left child
        else if (root->left != nullptr && root->right == nullptr)
        {
            node_ptr temp = root->left;
            value = root->value;
            delete root;
            return temp;
        }
        // node have only right child
        else if (root->left == nullptr && root->right != nullptr)
        {
            node_ptr temp = root->right;
            value = root->value;
            delete root;
            return temp;
        }
        // node is a leaf
        else
        {
            value = root->value;
            delete root;
            return nullptr;
        }
    }
    else if (key < root->key)
        root->left = remove(root->left, key, value);
    else
        root->right = remove(root->right, key, value);
    return root;
}

void bst::inorder_traversal(node_ptr root)
{
    if (root != nullptr)
    {
        inorder_traversal(root->left);
        std::cout << "[" << root->key << ", " << root->value << "]";
        inorder_traversal(root->right);
    }
}

void bst::breadth_first_traversal(node_ptr root) {
    if (root != nullptr) {
        queue <node_ptr> q;
        q.push(root);
        while (!q.empty()) {
            node_ptr n = q.front();
            q.pop();
            cout << n->key << " ";
             
            if (n->left != nullptr)
                q.push(n->left);
            if (n->right != nullptr)
                q.push(n->right);
        }
    }
}
/*Public API*/

void bst::insert(int key, int value)
{
    root = insert(root, key, value);
}

int bst::get(int key)
{
    node_ptr n = get(root, key);
    if (n)
        return n->value;
    return -1;
}

int bst::remove(int key)
{
    int value = -1;
    root = remove(root, key, value);
    return value;
}

void bst::traverse(TraversalOrder order)
{
    switch (order)
    {   
        case TraversalOrder::INORDER : 
            inorder_traversal(root);
            break;
        case TraversalOrder::BREADTHFIRST:
            breadth_first_traversal(root);
            break;
        default:
            break;
    }
}