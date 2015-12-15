#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;

//Do NOT edit the Student struct
struct Student {
    int iq;
    int age;
    int strength;
    string name;
    Student(int iq_in, int age_in, int strength_in, string name_in){
        iq = iq_in;
        age = age_in;
        strength = strength_in;
        name = name_in;
    }
};

//You can add functions or new classes if you'd like


int main() {
    //Don't edit the students
    Student student1(112, 15, 99, "Joey");
    Student student2(152, 13, 21, "Sheldon");
    Student student3(82, 19, 91, "Connie");
    Student student4(130, 18, 75, "Wilma");
    Student student5(140, 16, 60, "Thelma");
    Student student6(145, 14, 55, "Malcolm");
    Student classroom[6] = {student1, student2, student3, student4, student5, student6};

//Make three STL priority queues, one to sort by IQ, one to sort by Strength,
// and one to sort by Age
//These declarations are wrong but you should keep the variable names.
    priority_queue<Student> iq_q;
    priority_queue<Student> st_q;
    priority_queue<Student> age_q;

//Do NOT edit below this line
//load the students into the pqs.
    for(int i = 0; i < 6; ++i){
        iq_q.push(classroom[i]);
        st_q.push(classroom[i]);
        age_q.push(classroom[i]);
    }
    
//These tests make sure they come out in the correct order
    assert( (iq_q.top()).name == "Sheldon"); //highest IQ
    iq_q.pop();
    assert( (iq_q.top()).name == "Malcolm");
    iq_q.pop();
    assert( (iq_q.top()).name == "Thelma");
    iq_q.pop();
    assert( (iq_q.top()).name == "Wilma");
    iq_q.pop();
    assert( (iq_q.top()).name == "Joey");
    iq_q.pop();
    assert( (iq_q.top()).name == "Connie");

    assert( (age_q.top()).name == "Connie"); //highest age
    age_q.pop();
    assert( (age_q.top()).name == "Wilma");
    age_q.pop();
    assert( (age_q.top()).name == "Thelma");
    age_q.pop();
    assert( (age_q.top()).name == "Joey");
    age_q.pop();
    assert( (age_q.top()).name == "Malcolm");
    age_q.pop();
    assert( (age_q.top()).name == "Sheldon");
    
    assert( (st_q.top()).name == "Joey"); //highest strength
    st_q.pop();
    assert( (st_q.top()).name == "Connie");
    st_q.pop();
    assert( (st_q.top()).name == "Wilma");
    st_q.pop();
    assert( (st_q.top()).name == "Thelma");
    st_q.pop();
    assert( (st_q.top()).name == "Malcolm");
    st_q.pop();
    assert( (st_q.top()).name == "Sheldon");
    cout << "All tests pass" << endl;
//Thanks for a great semester!
}