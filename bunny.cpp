//Write a program that creates a linked list of bunny objects
#include <ctime>
#include <iostream>
#include <math.h>
#include <string>
#include </Users/emmaredfoot/eclipse-workspace/Homework/Final_Project/bunny.h>
using namespace std;

//Bunny::Bunnylist(string gender, string name, string color, bool mutant, int age = 0) {}

double randlcg(int numCalls) {

    numCalls++;
    long int lcg_array[100000];
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

Bunny BunnyArray[5000];

string Bunny::getGender(double x){
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

string Bunny::getColor(double x){
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

string Bunny::getName(double x){

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

// int Bunny::getAge(int age){
//     return(age++);
// }
bool Bunny::getMutant(double x){
    bool mutant = false;

    if(x>.97){
        mutant = true;
    }
    return(mutant);
}

//Bunny constructor
Bunny::Bunny(double x){
    cout << numCalls << endl;
    gender = getGender(x);
    color = getColor(x);
    name = getName(x);
    bool mutant = getMutant(x);
    bool living = true;

}

//New Bunny birth after the original 10
void BunnyList::AddBun(Bunny* Bun){
    int males = 0;
    int females = 0;
    int population = 0;
    //
}

//Track Bunny age. Have to start at the beginning of the list of bunnies and add 1 to each. The ones that have died
//I need to remove from the list
void Bunny::incrementAge(Bunny* start){
    while (start != NULL)
    {
        //Use a pointer to access the age characteristic in the bunny type
        start->age = start->age+1;
        start = start->next;
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
    cout << "Living? " << living << endl;
}


int main(){

double x;
x=randlcg(numCalls);

Bunny instanceBun = new Bunny(x);
instanceBun.printBunny();
//instanceBun.incrementAge(Bunny* start);

//initialize the first 10 bunnies
// while(sizeof(OriginalBuns)<10){
//     cout << numCalls << endl;
//     double x;
//     numCalls++;
//
//     //find the gender
//     x=randlcg(numCalls);
//     cout << x << endl;
//     string gender = OriginalBuns.getGender(x);
//     //find and assign the color
//     string color = OriginalBuns.getColor(x);
//
//     //find and assign the name
//     string name = OriginalBuns.getName(x);
// }
//
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



return(0);

}
