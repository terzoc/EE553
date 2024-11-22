#include <iostream>
#include <cstring>

using namespace std;

class String{
private:
    int length;
    char* str;

public:

// Default Constructor
    String(){
        length = 0;
        str = nullptr;
    }

// Non default constructor
    String(const char* s){
        length = strlen(s);
        str = new char[length + 1]; 
        for (int i = 0; i < length; ++i) {
             str[i] = s[i]; 
        }
        str[length] = '\0';
    }

// Destructor
    ~String(){
        delete[] str;
    }

// << overload
    friend ostream& operator<<(ostream& os, const String& s) {
        os << s.str; 
        return os;
    }

// Copy constructor 
    String(const String& s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

// Move constructor
    String(String&& s) {
        str = s.str;
        length = s.length;
        s.str = nullptr;
        s.length = 0;
    }

// = overload
    String& operator=(const String& s) {
        if (this != &s) {
            delete[] str;
            length = s.length;
            str = new char[length + 1];
            strcpy(str, s.str);
        }
        return *this;
    }

// + overload
    String operator+(const String& s) {
        String newString;
        newString.length = length + s.length;
        newString.str = new char[newString.length + 1];
        strcpy(newString.str, str);
        strcat(newString.str, s.str);
        return newString;
    }
    

};

int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;

    // Create String s = abc
    String s = "abc";
    // cout s
    cout << "s is: " << s << '\n';
    // Create String s = def
    String s2 = "def";
    // cout s2
    cout  << "s2 is: " << s2 << '\n';
    // create String s3 equal s2
    String s3 = s2; // copy constructor
    // cout s3
    cout << "s3 is: " << s3 << " copy constructor "<<'\n';
    //    Create String s4 that is assigned to s added to s2
    String s4 = s + s2;  // abcdef // copy constructor
    // cout s4
    cout << "s4 is: " << s4 << " copy constructor of s + s2"<< '\n';
    // Create s5 and move s4
    String s5 = move(s4); // move constructor
    // cout s5
    cout << "s5 is: " << s5 << '\n';
    cout << "cout s4 should give you error after move()" << endl;
    cout << s4 << '\n';
    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    return 0;
}