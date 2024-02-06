//генерация строк 
 
#include <iostream> 
#include <vector>  
#include <unordered_set> 
using namespace std; 
 
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
 
int main() 
{ 
    char symbols[27]  = "abcdefghijklmnopqrstuvwxyz"; 
    int rnd; 
    string sr = ""; 
     
    cout << sr; 
    int n; 
    int I; 
    cin >> n >> I; // n это количество строк, внешний цикл; I это количество символов в строке 
    vector<string> array; 
    array = random(array, n, I); 
    for(int i = 0; i < n; i++){ 
        cout << array[i] << '\n'; 
    } 
    cout << '\n' << "вектор, не содержащий повторяющихся строк:" << '\n'; 
    array = removed(array); 
    for(int i = 0; i < n; i++){ 
        cout << array[i] << '\n'; 
    } 
    return 0; 
}
