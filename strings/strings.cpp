#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string one = "Gibberish!";
    char two[] = "Gibberish!";

    cout << "one: " << one << endl;
    cout << "two: " << two << endl;

    cout << "\nModify both strings\n\n";

    one[4] = '\0';
    two[4] = '\0';

    cout << "one: " << one << endl;
    cout << "Length of one: " << one.size() << endl;
    cout << "Sizeof(one): " << sizeof(one) << endl << endl;

    cout << "two: " << two << endl;
    cout << "Length of two: " << strlen(two) << endl;
    cout << "Sizeof(two): " << sizeof(two) << endl;

    return 0;
}