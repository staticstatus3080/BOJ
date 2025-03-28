#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 1);
    if (dis(gen) % 2 == 1) {
        cout << "Korea";
    }
    else {
        cout << "Yonsei";
    }
}