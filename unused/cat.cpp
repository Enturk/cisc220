#include <iostream>
#include <string>
#include <cassert>
using namespace std;

struct Cat {
    int lives;
    int age;
    string name;
    
    Cat(string new_name, int new_age){
        name = new_name;
        lives = 9;
        age = new_age;
    }
};

Cat fetch_and_kill_oldest(Cat** cat_array, int length){
//This function tries to find the oldest cat, take away one life,
// and return it for petting or whatever.
//Fix this function starting here
    Cat temp = cat_array[0];
    for(int i = 1; i < length; i++){
        if (cat_array[i].age > temp.age){
            temp = cat_array[i];
        }
    }
    temp.lives -= 1;
    return temp;
//stop here
}


int main() {
    Cat fluffy("Fluffy", 1);
    Cat grumpy("Grumpy", 5);
    Cat crazy("Crazy", 3);
    Cat domino("Domino", 4);
    
    Cat* clowder[4] = {&fluffy, &grumpy, &crazy, &domino};
    
    Cat output = fetch_and_kill_oldest(clowder, 4);
    
    assert(output.name == "Grumpy");
    assert(output.lives == 8);
    assert(grumpy.lives == 8);
    
    //I'll replace Domino by an older cat and kill it twice.
    Cat goldie("Goldie", 9);
    clowder[3] = &goldie;
    
    output = fetch_and_kill_oldest(clowder, 4);
    output = fetch_and_kill_oldest(clowder, 4);
    
    assert(output.name == "Goldie");
    assert(output.lives == 7);
    assert(goldie.lives == 7);
    
    cout << "All tests pass" << endl;
}