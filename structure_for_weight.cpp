#include <vector> 
#include <iostream> 
 
using namespace std; 
 
int func_high(double weight){ 
    int high; 
    if (weight < 54.3){ 
            high = 158; 
        } 
    else if(weight < 55.3 && weight > 49.9){ 
        high = 160; 
    } 
    else if(weight < 56.8 && weight > 51.0){ 
        high = 162; 
    } 
    else if(weight < 58.2 && weight > 52.0){ 
        high = 164; 
    } 
    else if(weight < 59.8 && weight > 53.3){ 
        high = 166; 
    } 
    else if(weight < 61.5 && weight > 54.7){ 
        high = 168; 
    } 
    else if(weight < 62.9 && weight > 56.1){ 
        high = 170; 
    } 
    else if(weight < 64.3 && weight > 57.5){ 
        high = 172; 
    } 
    else if(weight < 65.8 && weight > 59.0){ 
        high = 174; 
    } 
    else if(weight < 67.2  && weight > 60.4){ 
        high = 176; 
    } 
    else if(weight < 68.6 && weight > 61.8){ 
        high = 178; 
    } 
    else if(weight < 70.1 && weight > 63.3){ 
        high = 180; 
    } 
    else if(weight < 71.5 && weight > 64.7){ 
        high = 182; 
    } 
    else { 
        high = 184; 
    } 
    return high; 
} 
 
struct Indicators { 
    int weight = 0; 
    int height = 0; 
}; 
 
int main() 
{ 
    int N; 
    cin >> N; 
    vector<Indicators> high_vect(N); 
    int min = 48; 
    int max = 72; 
    Indicators woman; 
    for(int i = 0; i < N; i ++){ 
        int weight = rand() % (max - min + 1) + min; 
        int high = func_high(weight); 
        woman.height = high; 
        woman.weight = weight; 
        high_vect.push_back(woman); 
    } 
    for(int i = 0; i < N; i ++){ 
        cout << "at a weight of " << high_vect[i].weight;  
        cout << " the height of an average build woman is " << high_vect[i].height <<'\n'; 
    } 
    return 0; 
}
