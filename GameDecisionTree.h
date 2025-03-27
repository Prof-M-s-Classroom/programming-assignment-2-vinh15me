#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H
using namespace std;

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>

class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const string& filename, char delimiter) {
        ifstream file;

        file.open(filename);

        if (!file.is_open()) {
            cout << "Could not open file " << filename << endl;
            return;
        }
        cout << "Loading story " << filename << endl;


        string line, word, event;
        int eventNumber, leftChildNumber, rightChildNumber;



        while (getline(file, line)) {
            cout << line << endl;
            stringstream ss(line);
            for (int i = 0; i<4; i++) {
                getline(ss, word, delimiter);
                switch (i) {
                    case 0:
                        eventNumber = stoi(word);
                        break;
                    case 1:
                        event = word;
                        break;
                    case 2:
                        leftChildNumber = stoi(word);
                        break;
                    case 3:
                        rightChildNumber = stoi(word);
                        break;
                    default:
                        cout << "Something is wrong." << endl;
                        exit(1);
                }
            }
            Story* newStory = new Story(event, eventNumber, leftChildNumber, rightChildNumber);
            Node<Story>* newNode = new Node<Story>(*newStory);
            if (root == NULL) {
                root = newNode;
            }
            else {
                insertNode(root, eventNumber,  newNode);
            }

        }
    }
    void preOrder() {
        if (!root) return;
        std::cout << root->data.description << endl;
        string input;
        cin >> input;
        for each(char c in input) {
            toupper(c);
        }
        if (input == "LEFT") {
            preOrder(root->left);
        }
        else if (input == "RIGHT") {
            preOrder(root->right);
        }
        else {
            cout << "PLease type left or right." << endl;
            preOrder();
        }
        return;
    }

    void preOrder(Node<Story>* temp) {
        if (!root) return;
        std::cout << root->data.description << endl;
        string input;
        cin >> input;
        for each(char c in input) {
            toupper(c);
        }
        if (input == "LEFT") {
            preOrder(temp->left);
        }
        else if (input == "RIGHT") {
            preOrder(temp->right);
        }
        else {
            cout << "PLease type left or right." << endl;
            preOrder(temp);
        }
    }

    void insertNode(Node<Story>* base, int targetEventNumber, Node<Story>* newNode) {
        if (base->data.leftEventNumber == targetEventNumber) {
            base->left = newNode;
            return;
        }
        else if (base->data.rightEventNumber == targetEventNumber) {
            base->right = newNode;
            return;
        }
        else if( base->right == nullptr && base->left == nullptr) {
            return;
        }
        insertNode(base->left, targetEventNumber, newNode);
        insertNode(base->right, targetEventNumber, newNode);
    }




    // TODO: Function to start the game and traverse the tree based on user input
    void playGame(){}
};

#endif // GAMEDECISIONTREE_H