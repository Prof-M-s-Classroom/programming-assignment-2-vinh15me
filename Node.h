#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    // TODO: Implement constructor here
    Node(T value):data(value), left(nullptr), right(nullptr) {}

};

#endif // NODE_H