//хеш код
using namespace std;
#include <iostream>
#include <vector> 
#include <unordered_set>
#include <algorithm>  
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <chrono>

vector<string> random(vector<string>array, int n, int I){
    string newstr = "";
    char symbols[27]  = "abcdefghijklmnopqrstuvwxyz";
    int rnd;
    for(int j = 0; j < n; j++){
        for (int i = 0; i < I; i++) {
        rnd = rand()%(26);
        newstr += symbols[rnd];
        }
        array.push_back(newstr);
        newstr = "";
    }
    return array;
}

vector<string> removed(const vector<string>& array) {
    vector<string> Strings;
    unordered_set<string> Set;
    for (const auto& str : array) {
        if (Set.find(str) == Set.end()) {
            Set.insert(str);
            Strings.push_back(str);
        }
    }
    return Strings;
}

size_t HashCode(const string& str) {    // создание хеш кодов
    size_t hash = 0;
    for (char c : str) {
        hash = (hash * 131) + c; 
    }
    return hash;
}

int main()
{
    char symbols[27]  = "abcdefghijklmnopqrstuvwxyz";
    int rnd;
    string sr = "";
    int n;
    int I;
    cin >> n >> I; // n это количество строк, внешний цикл; I это количество символов в строке
    vector<string> array;
    array = random(array, n, I);
    
    auto start = chrono::steady_clock::now();
    array = removed(array);
    auto end = chrono::steady_clock::now();
    chrono::duration<double> time_array = end - start;

    vector<size_t> hashCodes;
    for (const auto& str : array) {
        hashCodes.push_back(HashCode(str));
    }

    start = chrono::steady_clock::now();
    unordered_set<size_t> HashCodes(hashCodes.begin(), hashCodes.end());
    end = chrono::steady_clock::now();
    chrono::duration<double> time_hash = end - start;

    cout << "обычная функция:" << time_array.count() << " секунд" << endl;
    cout << "удаление с помощью хеш кодов: " << time_hash.count() << " секунд" << endl;
    return 0;
}
