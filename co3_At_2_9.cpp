#include <iostream>
#include <fstream>
using namespace std;

class FileHandler {
    fstream file;

public:
    FileHandler() {
        file.open("data.txt",
                  ios::out);

        cout << "File Opened\n";
    }

    ~FileHandler() {
        file.close();

        cout << "File Closed\n";
    }
};

int main() {

    FileHandler f;

    cout << "Working with File\n";
}