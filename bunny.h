//============================================================================
// Name        : Radioactive Bunny project
// Author      : Emma Redfoot
// Version     :
// Copyright   : Your copyright notice
// Description : Final Project
//============================================================================
#include <iostream>
#include <string>
using namespace std;

class Bunny {
public:
    //Each Bunny must have:
    string gender;
    string name;
    string color;
    bool mutant;
    bool living;
    int age;
    //The next is a pointer to the next bunny in the linked list
    Bunny *next;
    //Create an array of arrays
    //This array will hold all of the characteristics of a bunny instance
    //int bunny[string, string, string, int, bool=false];
    //This array will hold all of the bunny arrays
    //int bunnies[];

public:
    //Default Constructor
    Bunny();

    // Bunny()
    // {
    //     color = "none";
    //     gender = "none";
    //     name = "none";
    //     age=0;
    //     mutant = false;
    //     next = NULL;
    // }
    //Destructor
    //~Bunny();

    string getGender(double x);

    string getColor(double x);

    string getName(double x);

    bool getMutant(double x);

    void incrementAge(Bunny*);

    //Everything above here is the actual data going into the node.



    void printBunny();

};

// struct node {
//     int data;
//     node *next;
// };

class BunnyList {
public:
    Bunny *head, *tail;

public:
    //constructor
    BunnyList(){head=NULL; tail=NULL;}
    //Destructor
    ~BunnyList();

    void AddBun(Bunny* Bun);
};
