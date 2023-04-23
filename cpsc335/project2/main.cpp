#include "Algo.h"


int main() {


    cout << "Inputting for algorithm 1" << endl;
    string array1[1], array2[4];

    ifstream inFile;
    inFile.open("test1.txt");



    while (inFile >> array1[0]>> array2[0]>> array2[1] >> array2[2] >> array2[3])
    {
        algo_one(array1, array2);
        cout << endl;
    }

    inFile.close();



    //std::cout << "Testing Algorithm 1.\n";
    //// IT IS ADVISABLE TO COMMENT OUT THE REST OF THE algo_one()
    //// TO FOR READABILITY AND FOCUS
    //std::string A[1] = { "thismetoaklandrialtofullertonmarcolongchinofresnovallejoclovissimithound" };
    //std::string B[4] = { "oakland", "rialto", "marco", "clovis" };
    //algo_one(A, B);
    //std::cout << "\n";

    //std::string a1[1] = { "sanoaklandrialtofullertonmarcolongbreacoronamodestoclovissimithousand" };
    //std::string b1[4] = { "brea", "modesto", "clovis", "corona" };
    //algo_one(a1, b1);
    //std::cout << "\n";

    //std::string a2[1] = { "marcopolmonafremontrialtofullertonmarcolongfresnochinoclovissimisalinas" };
    //std::string b2[4] = { "fullerton", "chino", "fremont", "fresno" };
    //algo_one(a2, b2);
    //std::cout << "\n";

    //std::string a3[1] = { "torranceoaklandrialtomarcooxnardchinofresnoirvineclovissimiorange" };
    //std::string b3[4] = { "oxnard", "irvine", "orange", "marco" };
    //algo_one(a3, b3);
    //std::cout << "\n";

    std::cout << "\nTesting Algorithm 2. \n";
    std::string tempInput;
    while (tempInput != "DONE") {
        std::cout << "Give me an input or type in \"DONE\": ";
        std::cin >> tempInput;
        if (tempInput == "DONE") {
            break;
        }
        std::cout << algo_two(tempInput) << "\n";
    }

    std::cout << "\nTesting Algorithm 3. \n";
    std::vector<std::vector<int>> all_lists = { {2, 5, 9, 21}, {-1, 0, 2}, {-10, 81, 121}, {4 ,6, 12, 20, 150} };
    looper(algo_three(all_lists));
    std::cout << "\n";

    std::vector<std::vector<int>> Array_2 = { {10, 17, 18, 21, 29}, {-3, 0, 3, 7, 8, 11}, {81, 88, 121, 131}, {9, 11, 12, 19, 29} };
    looper(algo_three(Array_2));
    std::cout << "\n";

    std::vector<std::vector<int>> Array_3 = { {-4, -2, 0, 2, 7}, {4, 6, 12, 14}, {10, 15, 25}, {5, 6, 10, 20, 24} };
    looper(algo_three(Array_3));

    return 0;
};
