#include <iostream>
#include <string>

using namespace std;

int main() {
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    cout << "Enter your message to encrypt: ";
    string message {};
    getline(cin, message);
    
    cout << "\nEncrypted message: ";
    for (auto &c: message) {
        size_t found = alphabet.find(c);
        if (found != string::npos) {
            c = key.at(found);
        }
    }
    cout << message << endl;
    
    cout << "Decrypted message: ";
    for (auto &c: message) {
        size_t found = key.find(c);
        if (found != string::npos) {
            c = alphabet.at(found);
        }
    }
    cout << message << endl;
    
    return 0;
}