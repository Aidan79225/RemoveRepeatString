/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: s352431
 *
 * Created on March 13, 2018, 11:10 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    fstream mFile(argv[1], ios_base::in);
    ofstream ans;
    ans.open("ans.txt");
    unordered_set<string> mSet;
    unordered_set<string> mFilter;
    string temp;  
    int count = 0;
    if(argc == 3){
        fstream filter(argv[2], ios_base::in);
        while (filter >> temp) {
            mFilter.insert(temp);
        }
    }
    
    while (mFile >> temp) {
        if(mFilter.find(temp) == mFilter.end()){
            mSet.insert(temp);
        }
        count++;
    }
    for(auto&it : mSet){
        ans << it<< endl;
    }
    ans.close();
    cout<<"count : "<<count<< ", ans : "<<mSet.size()<<endl;
    return 0;
}

