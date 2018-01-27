#include <unordered_map>

struct Node {
    struct Node* left;
    struct Node* right;
};

static Node*
copy(Node* src,
     std::unordered_map<Node*, Node*> nodes)
{
    if (!src) {
        return nullptr;
    }
    auto it = nodes.find(src);
    if (it != nodes.end()) {
        return it->second;
    }
    Node *ret = new Node;
    nodes[src] = ret;
    ret->left = copy(src->left, nodes);
    ret->right = copy(src->right, nodes);
    return ret;
}

Node*
copy(Node* root)
{
    std::unordered_map<Node*, Node*> nodes;
    return copy(root, nodes);
}
