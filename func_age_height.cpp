
#include <iostream>

using namespace std;

double func_weight(int height, int age){
    double res = 50 + 0.75*(height - 150) + (age - 20)/4;
    return res;
}

int main()
{
    int height, age;
    cin >> height;
    cin >> age;
    double weight = func_weight(height, age);
    cout << "For a height of " << height << "cm, the average weight is " << weight << " kg";
    return 0;
}
