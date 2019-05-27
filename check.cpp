#include <iostream>
#include "mygetch.h"

    using namespace std;

int main() {
    while(_kbhit) {
        cout << mygetch();
    }
    return 0;
}