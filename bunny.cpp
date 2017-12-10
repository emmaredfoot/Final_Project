//Write a program that creates a linked list of bunny objects
#include <ctime>
#include <iostream>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include </Users/emmaredfoot/eclipse-workspace/Homework/Final_Project/bunny.h>
using namespace std;

//Global Variables
int numCalls =0;
int MaxBunAge = 10;
int MaxMutantAge = 50;
int F_mate = 0;
int F_pop = 0;
int M_mate = 0;
int M_pop = 0;
int Mutants = 0;
Bunny BunnyArray[5000];

double randlcg() {
    //cout << "rand" << endl;
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
    return(normalize);
}



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
    if (gender == "female"){
        F_pop++;
    }
    if (gender == "male"){
        M_pop++;
    }
    color = setColor(x);
    name = setName(x);
    age = 0;
    if(numCalls>10){
        bool mutant = setMutant(x);
    }
    else{
        mutant = false;
    }
    if(mutant){
        Mutants++;
    }
    age = 0;
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

bool BunnyList::ageCheck(Bunny* current){
    bool liveBun = current->getAge()<MaxBunAge && !(current->getMutant());
    bool YoungMutant = current->getMutant() && current->getAge()<MaxMutantAge;
    if (liveBun || YoungMutant){
        return(1);
    }
    else{
        return(0);
    }
}
//Track Bunny age. Have to start at the beginning of the list of bunnies and add 1 to each. The ones that have died
//I need to remove from the list
void BunnyList::incrementAge(){
    //cout << "here" << endl;
    if(size){
        //cout << "also" << endl;
        //For the head of the linked list,
        Bunny* temp = head;
        Bunny* other = NULL;

        //test cases for all of the if statements
        bool liveBun = temp->getAge()<MaxBunAge && !(temp->getMutant());
        bool OldLadyBun = temp->getGender()=="female" && temp->getAge()>8;
        bool OldManBun = temp->getGender() == "male" && temp->getAge()>8;
        bool YoungMutant = temp->getMutant() && temp->getAge()<MaxMutantAge;
        bool deadBun = temp->getAge()>=MaxBunAge && !(temp->getMutant());
        bool FemaleCheck = temp -> getGender()=="female";
        bool MaleCheck = temp -> getGender()=="male";

        //Loop through the entire BunnyList and add a year to the ages of the bunnies that qualify
        //kill off the bunnies that are too old
        while (temp != NULL) //At the end of the bunny list temp will be empty
        {
            //Check to see if the bunny is less than 10 years old and not a mutant or less than 50 and not a mutant
            if(liveBun || YoungMutant){
                cout << "determining failure " << temp->getAge() << endl;
                //Add a year
                temp->age+=1;
                if (OldLadyBun){
                    cout << "age " << temp->getAge() << endl;
                    F_mate--;
                    cout << "# females: " << F_mate << endl;
                }
                if (OldManBun){
                    cout << "age " << temp->getAge() << endl;
                    M_mate--;
                    cout << "# males: " << M_mate << endl;
                }
                //rename temp so that we know the current Bunny evaluated and can then access the
                //next bunny in the linked list
                other = temp;
                temp = temp->next;
            }
            //Check to see if the the bunny is 10 years old and not a mutant
            else if(deadBun){
                //Check if we are on the first node of the Bunny List
                if(head==temp)
                {
                    head = temp -> next;
                    cout << temp->getName() << " died!" << endl;
                    //remove the node as the Bunny has died
                    delete temp;
                    //rename the next node as the front of the list
                    temp = head;
                    if (FemaleCheck){
                        F_pop--;
                    }
                    if (MaleCheck){
                        M_pop--;
                    }
                    size--;

                }
                else{
                    other->next= temp->next;
                    cout << temp->getName() << " died!" << endl;

                    //remove the node as the Bunny has died
                    if (FemaleCheck){
                        F_pop--;
                    }
                    if (MaleCheck){
                        M_pop--;
                    }
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
                    if (FemaleCheck){
                        F_pop--;
                    }
                    if (MaleCheck){
                        M_pop--;
                    }
                    //Decreases the mutant population
                    Mutants--;
                    delete temp;
                    //rename the next node as the front of the list
                    temp = head;
                    size--;

                }
                else{
                    other->next=temp->next;
                    cout << temp->getName() << " the mutant bunny died!" << endl;
                    //remove the node as the Bunny has died
                    if (temp -> getGender()=="female"){
                        F_pop--;
                    }
                    if (temp -> getGender()=="male"){
                        M_pop--;
                    }
                    Mutants--;
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

    ofstream bunnyfile("bunny.txt", std::ios_base::app);
    bunnyfile << "New Bunny \n";
    bunnyfile << "gender=";
    bunnyfile << gender;
    bunnyfile << "\n";
    bunnyfile << "color=";
    bunnyfile << color;
    bunnyfile << "\n";
    bunnyfile << "name=";
    bunnyfile << name;
    bunnyfile << "\n";

}

//Make bunny list
void BunnyList::OriginalList() {
        numCalls++;
        double x = randlcg();
        this->AddBun(x);
        cout << "x " << x << endl;
        cout << "numCalls: " << numCalls << endl;
        this->incrementAge();
}

void BunnyList::BunnyMates(){
    int new_buns = 0;
    cout << "new Buns" << endl;
    this->incrementAge();
    cout << "Females " << F_mate << endl;
    double x = randlcg();
    if(head){
        Bunny* temp = head;
        while(temp !=NULL){
            if(F_mate && M_mate){
                new_buns = min(F_mate,M_mate);
                cout << "New Round of " << new_buns << " bunnies!" << endl;
            }
            while(new_buns>=1){
                new_buns--;
                AddBun(x);
            }
        }
    }
}

// void BunnyList::BunnyMates(){
//     cout << "here" << endl;
//     numCalls++;
//     double x = randlcg(numCalls);
//     int new_buns = 0;
//     if(head){
//         Bunny* temp = head;
//         while(temp !=NULL){
//
//         }
//     }

// }

// void MutantConversion(){
//
// }
//
// void BunnyPopulation(){
//
// }
//
// void MutantPopulation(){
//
// }

int main(){
    double x = randlcg();
    //Bunny instanceBun = Bunny(x);
    BunnyList * PeskyWabbits = new BunnyList;

    //Use the pointer to the BunnyList PeskyWabbits to add the first 10 bunnies to the list and start
    //tracking their age
    while(numCalls<10){
        numCalls++;
        PeskyWabbits->OriginalList();
    }
    bool terminate = false;
    while(!terminate){
        //Increment age
        PeskyWabbits -> incrementAge();

        //Add Bunnies
        PeskyWabbits->BunnyMates();

        // //Convert to Mutant bunnies
        // PeskyWabbits->MutantConversion();
        //
        // //See if the size is 0
        // PeskyWabbits->BunnyPopulation();

    }


    cout << "f=" << F_pop << endl;

    //For each male/female pair age 2-8 years: a new bunny is created in turn



return(0);

}
