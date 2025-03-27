#include <iostream>
#include <string>
#include "GameDecisionTree.h"
using namespace std;
int main() {
    GameDecisionTree<Story> myGame;

    string filename = "C:\\Users\\vinh1\\Documents\\GitHub\\programming-assignment-2-vinh15me\\story.txt";  // Specify the input file
    char delimiter = '|';                // '|' is the delimiter, change if needed

    Node test = new Node<string>("help");
    Node left2 = new Node<string>("left");
    Node right2 = (new Node<string>("right"));
    test.left = &left2;
    test.right = &right2;



    // Load the story data from the file
    myGame.loadStoryFromFile(filename, delimiter);

    myGame.preOrder();
    // Start the game
    myGame.playGame();

    return 0;
}