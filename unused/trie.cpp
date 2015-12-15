#include <iostream>
#include <string>
#include <cassert>
#include <map>
using namespace std;

// The PHONE TRIE.  This trie is set up to store phone numbers and
// a contact name with each phone number
//You should write the getName function which consumes a phone number and length
//and returns the name of the contact with that number or "NA"

struct Trie {
    map<char, Trie*> children;
    string name_of_contact;
    bool isEOW;
    
    bool hasChild(char key){
        map<char, Trie*>::iterator result = children.find(key);
        return result != children.end();      
    }
    
//Write this function only!
//start here
    string getName(char* input, int length){
        //should return the name stored under the give phone number
        //return the string "NA" when the number isn't in the Trie.
    }
//end here
    
    void insert(char* input, int length, string contact_name){
        if (length == 0){
            isEOW = true;
            name_of_contact = contact_name;
            return;
        }
        
        if (!hasChild(input[0])){
            Trie* newTrie = new Trie();
            children[input[0]] = newTrie;
        }

        (children[input[0]])->insert(input+1, length-1, contact_name);
    }
    
    Trie(){
        isEOW = false;
    }
};

int main() {
    Trie root;
    root.insert("8885551234", 10, "The Bling Hotline");
    root.insert("3028312010", 10, "CISC Office");
    root.insert("9047797791", 10, "Pog Reups");
    root.insert("911", 3, "Emergency Number");
    root.insert("8885451324", 10, "Porcupine Racetrack");
    root.insert("3028411995", 10, "Mrs. Butterworth");
    root.insert("811", 3, "Call before you dig");
    
    assert(root.getName("811", 3) == "Call before you dig");
    assert(root.getName("411", 3) == "NA");
    assert(root.getName("911", 3) == "Emergency Number");
    assert(root.getName("8885551234", 10) == "The Bling Hotline");
    assert(root.getName("8885551235", 10) == "NA");
}