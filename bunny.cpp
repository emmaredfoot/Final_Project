//Write a program that creates a linked list of bunny objects
#include <ctime>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include </Users/emmaredfoot/eclipse-workspace/Homework/Final_Project/bunny.h>
using namespace std;

//Bunny::Bunnylist(string gender, string name, string color, bool mutant, int age = 0) {}

double randlcg(int numCalls) {
    cout << "rand" << endl;
    numCalls++;
    long int lcg_array[1000000];
    double normalize;
    lcg_array[0] = 100001;
    int c = 1;
    int g = 61;
    long int modulus = pow(2,24);
    lcg_array[numCalls] = (lcg_array[numCalls-1]*g + c)%modulus;
    //cout << lcg_array[numCalls] << endl;
    normalize = double(lcg_array[numCalls])/modulus;
    return normalize;
}

//Global Variables
int numCalls =0;
int MaxBunAge = 10;
int MaxMutantAge = 50;
int F_pop = 0;
int M_pop = 0;
int Mutants = 0;
Bunny BunnyArray[5000];

string Bunny::setGender(double x){
    if (x < .49) {
        return("male");
    }
    else if (x > .51) {
        return("female");
    }
    else {
        return("other");
    }
};

string Bunny::getGender(){
    return(this->gender);
}

string Bunny::setColor(double x){
    if (x < .25) {
        return("white");
    }
    else if (.25 <= x < .5) {
        return("brown");
    }
    else if (.5 <= x < .75) {
        return("black");
    }
    else {
        return("spotted");
    }
}

string Bunny::setName(double x){

    if (x < .05){
        return("Green Buntern");
    }
    else if(.05<=x<.1){
        return("Batbun");
    }
    else if(.1<=x<.15){
        return("Spider-bun");
    }
    else if(.15<=x<.2){
        return("Iron Bun");
    }
    else if(.2<=x<.25){
        return("Capbun America");
    }
    else if(.25<=x<.3){
        return("Green Bunnet");
    }
    else if(.3<=x<.35){
        return("The Incredibun Hulk");
    }
    else if(.35<=x<.4){
        return("SuperBun");
    }
    else if(.4 <= x <.45){
        return("Mr. Buntastic");
    }
    else if(.45<=x<.5){
        return("Zorro");
    }
    else if(.5<=x<.55){
        return("Wonder Bun");
    }
    else if(.55<=x<.60){
        return("Black Rabbit");
    }
    else if(.6<=x<.65){
        return("Dr. Jean Bun");
    }
    else if(.65<=x<.7){
        return("Harley Bun");
    }
    else if(.7<=x<.75){
        return("CatBun");
    }
    else if(.75<=x<.8){
        return("Valkyrabbit");
    }
    else if(.8<=x<.85){
        return("Buffy Bunners");
    }
    else if(.85<=x<.9){
        return("The Invisibun Bunny");
    }
    else if(.9<=x<.95){
        return("Elektrabbit");
    }
    else{
        return("The Bionic Bunny");
    }
}

string Bunny::getName(){
    return(this->name);
}

// int Bunny::getAge(int age){
//     return(age++);
// }
bool Bunny::setMutant(double x){
    bool mutant = false;

    if(x>.97){
        mutant = true;
    }
    return(mutant);
}

bool Bunny::getMutant(){
    return(this->mutant);
}

//Bunny constructor
Bunny::Bunny(double x) {
    gender = setGender(x);
    color = setColor(x);
    name = setName(x);
    age = 0;
    if(numCalls>10){
        bool mutant = setMutant(x);
    }
    else{
        mutant = false;
    }

    printBunny();
}

//BunnyList constructor
BunnyList::BunnyList(): head(NULL), size(0){}

//New Bunny birth after the original 10
void BunnyList::AddBun(double x){
    Bunny* newBun = new Bunny(x);

    if (!head){
        head = newBun;
    }
    else{
        Bunny* temp = head;
        while(temp->next !=NULL){
            temp -> next = newBun;
        }
    }
    newBun->printBunny();
    ++size;
}

int Bunny::getAge(){
    return(age);
}

//Track Bunny age. Have to start at the beginning of the list of bunnies and add 1 to each. The ones that have died
//I need to remove from the list
void BunnyList::incrementAge(){
    if(head){
        cout << head << endl;
        //For the head of the linked list,
        Bunny* temp = head;
        Bunny* other = NULL;

        //Loop through the entire BunnyList and add a year to the ages of the bunnies that qualify
        //kill off the bunnies that are too old
        while (temp != NULL) //At the end of the bunny list temp will be empty
        {
            //Check to see if the bunny is less than 10 years old and not a mutant
            if(temp->getAge()<MaxBunAge && !(temp->getMutant())){
                cout << "gotcha" << endl;
                //Add a year
                temp->age+=1;
                //rename temp so that we know the current Bunny evaluated and can then access the
                //next bunny in the linked list
                if (temp->getGender()=="female" && temp->getAge()>8){
                    F_pop--;
                    cout << "# females: " << F_pop << endl;
                }
                else if (temp -> getGender() == "male" && temp->getAge()>8){
                    M_pop--;
                    cout << "# males: " << F_pop << endl;
                }
                other = temp;
                temp = temp->next;
            }
            //check to see if the bunny is a mutant and less than 50 years
            else if(temp->getMutant() && temp->getAge()<MaxMutantAge){
                //Add a year
                temp->age+=1;
                //rename temp so that we know the current Bunny evaluated and can then access the
                //next bunny in the linked list
                other = temp;
                temp = temp->next;
            }
            //Check to see if the the bunny is 10 years old and not a mutant
            else if(temp->getAge()>=MaxBunAge && !(temp->getMutant())){
                //Check if we are on the first node of the Bunny List
                if(head==temp)
                {
                    head = temp -> next;
                    cout << temp->getName() << " died!" << endl;
                    //remove the node as the Bunny has died
                    delete temp;
                    //rename the next node as the front of the list
                    temp = head;
                    size--;

                }
                else{
                    other->next=temp->next;
                    cout << temp->getName() << " died!" << endl;
                    //remove the node as the Bunny has died
                    delete temp;
                    //rename the next node as the front of the list
                    temp = other -> next;
                    size--;
                }
            }
            //In the case of a dead mutant bunny
            else{
                //Check if we are on the first node of the Bunny List
                if(head==temp)
                {
                    head = temp -> next;
                    cout << temp->getName() << " the mutant bunny died!" << endl;
                    //remove the node as the Bunny has died
                    delete temp;
                    //rename the next node as the front of the list
                    temp = head;
                    size--;

                }
                else{
                    other->next=temp->next;
                    cout << temp->getName() << " the mutant bunny died!" << endl;
                    //remove the node as the Bunny has died
                    delete temp;
                    //rename the next node as the front of the list
                    temp = other -> next;
                    size--;
                }

            }


        }
    }

}
//Print Bunny
void Bunny::printBunny()
{
    cout << gender << endl;
    cout << color << endl;
    cout << name << endl;
    //cout << age << endl;
    cout << "Mutant = " << mutant << endl;

    //save Bunny output to file
}

//Make bunny list
void BunnyList::OriginalList(int numCalls) {
    while(numCalls < 10){
        numCalls++;
        double x = randlcg(numCalls);
        this->AddBun(x);
        cout << "x " << x << endl;
        cout << "numCalls: " << numCalls << endl;
    }
}

// void Bunny::FemalePopulation(){
//     if (this->getGender() == "female"){
//         F_pop++;
//     }
// }
//
// void Bunny::BunnyMates(){
//     if (this->getGender() == "male"){
//         M_pop++;
//     }
//
// }


int main(){
    int numCalls = 0;
    double x = randlcg(numCalls);
    cout << "x=" << x << endl;
    //Bunny instanceBun = Bunny(x);
    BunnyList * PeskyWabbits = new BunnyList;

    //Use the pointer to the BunnyList PeskyWabbits to add the first 10 bunnies to the list and start
    //tracking their age
    PeskyWabbits->OriginalList(numCalls);

    //For each male/female pair age 2-8 years: a new bunny is created in turn



return(0);

}

//Use a pointer to access the age characteristic in the bunny type
// start->age = start->age+1;
// start = start->next;

//initialize the first 10 bunnies
// while(numCalls<10){
//     cout << "here" << endl;
//     instanceBun.getMutant(0);
//     instanceBun.printBunny();
// }

// double x=randlcg(numCalls);
// numCalls++;
//
// //find the gender
// x=randlcg(numCalls);
// cout << x << endl;
// string gender = AllBuns.getGender(x);
// cout << gender << endl;
//
// //find and assign the color
// string color = AllBuns.getColor(x);
// cout << color << endl;
//
// //find and assign the name
// string name = AllBuns.getName(x);
// cout << name << endl;
// bool mutant = AllBuns.getMutant(x);
// if (mutant==true){
//     cout << "Mutant" << endl;
// }
//
// int age=0;
//
//
// Bunny* CurrentBunny = MakeBunny(gender, color, name, age, mutant);
// //cout << OriginalBuns << endl;

// //Make initial 10 bunny list
// void OriginalList::BunnyList(int numCalls) {
//     cout << "numCalls" << numCalls << endl;
//     if(numCalls == 0)
//     cout << "again" << endl;
//     {
//         for(int i=0; i<10; i++){
//             numCalls++;
//             double x = randlcg(numCalls);
//             this->AddBun(x);
//             cout << "x " << x << endl;
//             cout << "numCalls: " << numCalls << endl;
//         }
//     }
//
//

// while(size){
//     numCalls++;
//     double x = randlcg(numCalls);
//     this->AddBun(x);
//     cout << "x " << x << endl;
//     cout << "numCalls: " << numCalls << endl;
//     //incrementAge adds a year to the bunnies that are still alive and kills the bunnies that are past
//     //their mortality
//     this->incrementAge();
// }
