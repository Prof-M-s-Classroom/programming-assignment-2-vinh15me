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
    Node<T*>* root;

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


        string line, word, event;
        int eventNumber, leftChildNumber, rightChildNumber;



        while (getline(file, line)) {
            //cout << line << endl;
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
            Node<Story*>* newNode = new Node<Story*>(newStory);
            if (root == NULL) {
                root = newNode;
            }
            else {
                insertNode(root, eventNumber,  newNode);
            }

        }
    }


    void insertNode(Node<Story*>* base, int targetEventNumber, Node<Story*>* newNode) {
        if (base == nullptr) {
            return;
        }
        if (base->data->leftEventNumber == targetEventNumber) {
            base->left = newNode;
        }
        if (base->data->rightEventNumber == targetEventNumber) {
            base->right = newNode;
        }
        else if( base->right == nullptr && base->left == nullptr) {
            return;
        }
        insertNode(base->left, targetEventNumber, newNode);
        insertNode(base->right, targetEventNumber, newNode);
    }




    // TODO: Function to start the game and traverse the tree based on user input
    void playGame() {
        if (!root) return;
        cout << root->data->description << endl;
        int input;
        cin >> input;
        if (input == 1) {
            goThroughStory(root->left);
        }
        else if (input == 2) {
            goThroughStory(root->right);
        }
        else {
            cout << "Please type 1 for the first choice or 2 for the second choice." << endl;
            cin.clear();
            cin.ignore();
            playGame();
        }
    }

    void goThroughStory(Node<Story*>* temp) {
        if (!temp) return;
        cout << temp->data->description << endl;
        if (temp->data->leftEventNumber == -1 && temp->data->rightEventNumber == -1) {
            cout << "The End!" << endl;
            return;
        }
        int input;
        cin >> input;
        if (input == 1) {
            goThroughStory(temp->left);
        }
        else if (input == 2) {
            goThroughStory(temp->right);
        }
        else {
            cout << "Please type 1 for the first choice or 2 for the second choice." << endl;
            cin.clear();
            cin.ignore();
            goThroughStory(temp);
        }
    }

};

#endif // GAMEDECISIONTREE_H