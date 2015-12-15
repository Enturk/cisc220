#include <iostream>
#include <cassert>
using namespace std;

//Edit these two functions
void set_bit(unsigned char &x, int i, bool value){
    //set bit i to value (in place)
}

bool get_bit(unsigned char x, int i){
    //return the value of bit i
}
//stop editing here

int main() {
    unsigned char x = 0;
    set_bit(x, 3, 1);
    set_bit(x, 5, 1);
    set_bit(x, 7, 1);
    
    assert(x % 2 == 0);
    assert(!get_bit(x,1));
    assert(!get_bit(x,2));
    assert(get_bit(x,3));
    assert(!get_bit(x,4));
    assert(get_bit(x,5));
    assert(!get_bit(x,6));
    assert(get_bit(x,7));
    
    set_bit(x, 3, 0);
    set_bit(x, 5, 0);
    assert(!get_bit(x, 0));
    assert(!get_bit(x,1));
    assert(!get_bit(x,2));
    assert(!get_bit(x,3));
    assert(!get_bit(x,4));
    assert(!get_bit(x,5));
    assert(!get_bit(x,6));
    assert(get_bit(x,7));
    
    cout << "All tests pass" << endl;
}