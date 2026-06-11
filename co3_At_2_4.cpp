#include <iostream>
using namespace std;

class Box {
    int volume;

public:
    Box(int v) {
        volume = v;
    }

    bool operator>(Box b) {
        return volume > b.volume;
    }
};

int main() {

    Box b1(100), b2(150);

    if(b1 > b2)
        cout << "Box 1 Greater";
    else
        cout << "Box 2 Greater";
}