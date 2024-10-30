#include <string>
#include <iostream>

using namespace std;


class Zebra{
private:
    string name;
    static int count;
public:
    static int getCount(){
        return count;
    }

    string getName(){
        return name;
    }

    Zebra(){
        name = "";
        count++;
    }

    Zebra(string newName){
        name = newName;
        count++;
        cout << "Hello, I'm just born! My name is: " << name << endl;
    }

    ~Zebra(){
        count--;
        cout << "Ugh! I'm dying, new count: " << count << endl;
    }
    static void f(){
        cout << "Current count: " << Zebra::getCount() << endl;
        Zebra Joker("Joker");
        Zebra Alice ("Alice");
        cout << "New Zebras Joker and Alice made, current count: " << Zebra::getCount() << endl;
    }
};

class ZebraKid : public Zebra{
    using Zebra::Zebra;
};

int Zebra::count = 0;

static void f(){
    cout << "Current count: " << Zebra::getCount() << endl;
    Zebra Joker("Joker");
    Zebra Alice ("Alice");
    cout << "New Zebras Joker and Alice made, current count: " << Zebra::getCount() << endl;
}


int main() {
    cout << "########" << endl;
    cout << "Main Problem" << endl;
    cout << "########" << endl;
    // You should be able to run main() with your classes
    // No need to edit this part unless for debugging
    // print the initial count number
    cout << Zebra::getCount() << '\n'; // zero!
    // Creat object a with name Morgana
    Zebra a("Morgana");
    // Print the current count number of Zerba object
    cout << Zebra::getCount() << '\n';
    // Use the function f() above
    ZebraKid::f();
    cout << "####" << endl;
    // Use the function f() above again
    f();
    cout << "####" << endl;
    // print out the current number of zebra
    cout << Zebra::getCount() << '\n';
    // Get the name of the zebra object a
    cout << a.Zebra::getName() << '\n';
    cout << "####" << endl;

    // create  ZebraKid object
    ZebraKid e("James");
    // Use the getName() form Zebra class
    cout << e.getName() << '\n';
    cout << Zebra::getCount() << '\n';


    cout << "====[ end ]====" << endl;
    cout << "               " << endl;

    cout << " #### This is after the program is completely done #####" << endl;
    cout << " ### The last remaining object should get destructed ###" << endl;

    return 0;

}