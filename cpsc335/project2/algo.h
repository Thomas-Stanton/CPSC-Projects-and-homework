#ifndef Algo_T_h
#define Algo_T_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


static void algo_one(std::string arr0[1], std::string arr1[4]) {
    /*
    Given an array of one concatenated string, and an array of 4 words, 
    match the words to the string
    */
    int temp;
    int counter = 1;
    std::vector<int> tempVec0;
    std::vector<std::string> tempVec1; 
    for (int i = 0; i < arr0[0].size(); i++) {
        // iterates only the concantenated string of index 0 of arr0
        // look into arr0
        // std::cout << "Comparing index of arr1: " << i << " and letter: " << arr0[0][i] << "\n";
        for (int j = 0; j < 4; j++) {
            // iterates through the words of arr1, hoping that size is always 4
            // about to start matching arr0 letters with arr1 starting letters
            if (arr0[0][i] == arr1[j][0]) { 
                // [0][i] i index of the first element of arr0 and [j][0] of the j element of the first letter of arr2 
                // if true, then attempt matching the rest of the letters
                std::cout << "A letter matches between arr0 and arr1\n";
                std::cout << "Index of arr0 is: [" << i << "] and the character is: " << arr0[0][i] << "\n";
                std::cout << "The word being: " << arr1[j] << "\n";
                temp = i;
                bool check = true;
                for (int k = 0; k < arr1[j].size(); k++) {
                    // using the word size of arr1[j], start the matching
                    // std::cout << "arr0: " << arr0[0][i] << "\n";
                    // std::cout << "arr1: " << arr1[j][k] << "\n";
                    
                    if (arr0[0][i] != arr1[j][k]) {
                        std::cout << arr0[0][i] << " != " << arr1[j][k] << "\n";
                        // instantly break 
                        check = false;
                        break;
                        i -= counter;
                        counter = 0;
                    } else {
                      i++;
                      counter++;
                    }
                    
                }
                counter = 1;
                i -= 1;
                if (check) {
                    // add index found 
                    std::cout << "At index " << temp << " " << arr1[j] << " is found.\n";
                    // pushes index and found word into their respective vectors
                    tempVec0.push_back(temp);
                    tempVec1.push_back(arr1[j]);
                    check = false;
                    temp = 0;
                } else {
                    // refresh check if failed
                    check = false;
                    temp = 0;
                }
            }
            // else continue to next word in arr1
        }
    }
    
    // print all elements of the indices found
    std::cout << "Indices: ";
    for (int i : tempVec0) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    // print all elements of the words found
    std::cout << "Words: ";
    for (std::string i : tempVec1) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "algo_one completed\n";
}


std::string algo_two(std::string str) {
    /*
    Given a string, output a string with repeats numbered
    */
 //   string adjStr = str;
    int counter = 0;
    bool check = false;
    int savePosition1 = 0, savePosition2 = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i+1] != str.size() && str[i] == str[i + 1]) {
            int j = i;
            // If its not the last index
            savePosition1 = i;
            do  {
                // if the next char is the same
                // counter incremented to track num of repetition
                // i incremented to move to next index
                counter++;
                
                j++;
                savePosition2 = j;
            } while (str[i] == str[j] && i != ' ');
            int awayFromEnd = str.size();

            char c = '0' + counter;
            awayFromEnd = awayFromEnd - savePosition2;
            str[savePosition1] = c;
            str.erase(str.begin() + savePosition1 +1 , str.end() - awayFromEnd-1);
        }
      counter = 0;
    }

    std::cout << "algo_two completed\n";
    return str;
}

std::vector<int> algo_three(std::vector<std::vector<int>> vec0) {
    /*
    Merge multiple "arrays" into one and sort from least to greatest
    */
   std::vector<int> blob;
   // Add all elements in the vectors of vec0 into one array
    for (int i = 0; i < vec0.size(); i++) {
        for (int j : vec0[i]) {
            blob.push_back(j);
        }
    }

    std::sort(blob.begin(), blob.end());
    return blob;
}

void looper(std::vector<int> vec0) {
    for (int i = 0; i < vec0.size(); i++) {
        std::cout << vec0[i] << " "; 
    }
    std::cout << "\n";
}

#endif
