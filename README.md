[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Vinh Tran`  
### **Student ID:** `131807088`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

This is my RPG game. It allows the user to type 1 to go down the left tree or 2 to go down the right tree.
The story is handcrafted and loaded from the story.txt
The game ends when a leaf node is reach.
The tree is full so you will reach a left node when both left and right child event numbers are -1.


Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `Is here to call the method to start the game and call the method that loads the game from "story.txt"`  
- **`GameDecisionTree.h`** → `It contains the entire tree and all the nodes to play the game. It has loadStoryFromFile which sets up the tree. It has playGame which starts the game, then uses recurrsion to go through the tree.`  
- **`Node.h`** → `Holds the class Node where the Story class will be held in data and the left and right children will be held in their respective varibles`  
- **`Story.h`** → `Holds the calss Story where the data from the story.txt will be held like the event, event number, left event number, and right evnent number`  
- **`story.txt`** → `Using the given delimiter "|" we can seperate the line into four different varibles, event number, event, left eevent number and right event number. `

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?
- `First, the whole line is grabbed from the text file.`
- `Then, using string stream, we cut the line into four different varibles, `
- `those being the event number, event, left event number and right event number.`
- `All of those are inputed into a story object which is then put into the node.`
- How are nodes linked based on left and right event numbers?  
- `Event numbers work in my code by checking leaf nodes (with no children) and checking the story object to see what event number is supposed to be there.`
- `If the event number matches the event I'm inserting, then I insert the node there.`
- `This does that until there is no more lines`
- `during the actual playing of the game, I just ask the user to input 1 for the left node and 2 for the right node, and not use the event numbers.`
- What happens if an event has `-1` as left or right children?  
- `in my story, I have conclusion events which are the only nodes to have -1 and have -1 on both sides.`
- `when I reach these conclusion events, I print out the last data then imeddieately return, `
- `not asking the user for the input because both children number events are -1.`

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- `I just use cin and ask the user to input 1 for the left node and 2 for the right node.`
- `I print what each option will do in the story.`
- What happens when the player reaches a leaf node? 
- `when the player reaches a leaf node, (the only leaf nodes have both children as -1) `
- `the game will print the last data with the conculsion data then break immediately.`
- Explain the special case where multiple events lead to the same outcome.  
- `at the start, I have an introduction with branching decisions that all lead to the same start.`
- `I use this later as well as certain actions lead to the same node.`

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- `first I use the getLine to get the whole line with the delimiters.`
- `next I use the getline again to seperate the words from each other with the delimiters there to seperate them.`
- How do you ensure nodes are properly linked?  
- `I check the event numbers of the left and right child and put the node there if the event numbers match`
- `I don't break when I place a node so I can place multiple of the same node.`
- Any challenges faced while handling file input?  
- `Yeah, the program won't read the file locally so I had to put the absolute file path for it to work.`

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)
`When I made the insert node function, I forgot to check if the base was null when I sent it through recurrsion.`
`This sucked as it didn't break there but broke later when the program tried to read data in the node and it was null`
`I had to debug and search for why the node was null though I assumed inserting was the problem`

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
` Hello! Welcome to my game. Here, you will input the number 1 or the number 2 to make your decision. You got that? (1 for "Yes", 2 for "No")`
`2`
`What... You just made the decision. You're just gonna do that but multiple times through the story. (1 for "ok...", 2 for "But I don't wanna read")`
`2`
`Well that's too bad, you're gonna have to read my epic story... please read it i worked hard on it (1 for "Fine... but with a visible look of frustration", 2 for "Ok")`
`1`

`Thanks... Now let's get on with the story. (1 for "ok...", 2 for "I hate you.")`
`2`
---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(N)`  
- **Searching for an event in the tree** → `O(N)`  
- **Game traversal efficiency** → `O(log(n))`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

`nope`

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
