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

//check to see if the bunny is a mutant and less than 50 years
else if(YoungMutant){
    //Add a year
    temp->age+=1;
    //rename temp so that we know the current Bunny evaluated and can then access the
    //next bunny in the linked list
    other = temp;
    temp = temp->next;
}
