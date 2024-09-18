#include <iostream>
#include <cmath>  // double sin(double), double cos(double)
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
//#include "functionWind.h"
//#include "functionPrime.h"

using namespace std;

// const for pi
const double pi = 3.14159265358979323846;

void isPrime(int num){
    int maxDiv = num/2 + 1;
    // cout << maxDiv;
    bool prime = true;
    for(int i = maxDiv; i > 1; i--){
        if(num % i == 0){
            // cout << "\n not prime";
            prime = false;
        }
    }

    if(num <= 3) prime = true;
    if(num <= 1) prime = false;
    
    if(prime){
        cout << num << " is prime";
    }else{
        cout << num << " is not prime";
    }
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main() {
    cout << "###########" << endl;
    cout << "Problem One" << endl;
    cout << "###########" << endl;
    // For problem one, you only need to write your code in "functionPrime.cpp"
    // define isPrime
    isPrime(19);
    cout << '\n';

    isPrime(81);// trial divide, 81%3 == 0 therefore not prime
    cout << '\n';

    isPrime(57) ; // 57 % 2, 57% 3, 57%4
    cout << '\n';

    cout << "====[ end ]====" << endl;

    cout << "###########" << endl;
    cout << "Problem Two" << endl;
    cout << "###########" << endl;
    // For problem Two, you will need to write your code here
    // first read file robotpath.dat and name it thefile by using ifstream
    // make sure you use the full path to .dat file, e.g., .././src/robotpath.dat

    //check if thefile exist or not
    ifstream thefile("robotpath.dat"); 

    if (thefile.is_open()){

        cout << "File is open and ready" << '\n';
        cout << " " << '\n';

    }else{
        cout << "File not found!" << '\n';
        cout << " " << '\n';
    }

    // define your variables each line r and theta from the polar coordinates
    // use defined constant pi value in your calculation
    // start reading file and do calculation

    // while reading print the following for each line:
    //  - print distance and angle
    //  - print angle in radian, 1 degree is equal (pi/180degree)
    //  - print x and y location
    //  - check your conversion and print angle in rad after finding x and y with cartesian coordinates conversion
    // don't forget to close your opened file.

    string line; 
    float distance;
    int degrees;
    cout << setprecision(8);

    while(getline(thefile, line)){
        if(line != ""){
            stringstream ss(line);
            ss >> distance >> degrees;  
            cout << "Distance: "<< distance;
            cout << ", Degrees: " << degrees;
            double radians = degrees * pi /180;
            cout << ", Radians: " << radians;
            double xp = distance * cos(radians);
            cout << ", X: " << xp;
            double yp = distance * sin(radians);
            cout << ", Y: " << yp;
            double calcRad = atan(yp/xp);
            cout << ", Calculate Radians: " << calcRad;
            cout << '\n';
        }
    }
    thefile.close();

    cout << "====[ end ]====" << endl;

    cout << "###########" << endl;
    cout << "Problem Three" << endl;
    cout << "###########" << endl;
    //Write your code here

    // use Boolean CanRun to decide to do calculation or not based on condition
    bool canRun = true;
    // define your input value and other variable
    double temp, windSpeed, windChill;
    bool tempGood,speedGood = false;
    cout << setprecision(5);

    // print out message to enter wind speed and take the input
    // Check if speed meet condition

    while(!tempGood){
        cout << "Please enter actual temperature: ";
        cin >> temp;
        if(temp > 50){
            cout << "Temperature must be 50 degrees F or below\n";
        }else{
            tempGood = true;
        }
    }       

    // print out message to enter temperature and take the input
    // check if temperature  meet condition

    while(!speedGood){
        cout << "Please enter wind speed: ";
        cin >> windSpeed;
        if(windSpeed < 4){
            cout << "Wind speed must be above 3 mph\n";
        }else{
            speedGood = true;
        }
    }

    // check if all condition is met and use canRun to start calculation of wind chill
    // print out the value
    if(speedGood && tempGood){
        canRun = true;
    }

    if (canRun){
        windChill = 35.74 + 0.6215*temp - 35.75*pow(windSpeed,0.16) + 0.4275*temp*pow(windSpeed,0.16);
        cout << "Wind chill: " << windChill << " Degrees F\n";
    }else{
        cout << "Cannot run calculation, inputs do not meet required conditions\n";
    }
    
    cout << "====[ end ]====" << endl;

    return 0;
}
