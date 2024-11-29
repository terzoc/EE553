#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<int> findBuildingsWithOceanView(const vector<int>& heights){
    vector<int> output;

// Check if vector size is with required range
    if (heights.size() < 1 || heights.size() > pow(10,5)){
        cout << "Heights vector invalid size" << endl;
        return output;
    }

// Check if all heights are within required range
    for(int i : heights){
        if(i < 1 || i > pow(10,9)){
            cout << "Invalid height/s in height vector" << endl;
            return output;
        }
    }

// Check for ocean views
    for(int i = 0; i < heights.size(); i++){
        bool hasView = true;
        // Compare current hight to all heights between it and ocean and check if its blocked
        for(int j = i+1; j < heights.size(); j++){
            if(heights.at(i) <= heights.at(j)){
                hasView = false;
            }
        }
        // if not blocked push index to output vector
        if(hasView){
            output.push_back(i);
        }
    }
    return output;
}

int main(){
    vector<int> heights = {4,2,3,1};
    vector<int> buildingsWithOceanView = findBuildingsWithOceanView(heights);

    // Print output vector
    for (int i : buildingsWithOceanView)
        cout << i << " ";
    cout << endl;
}