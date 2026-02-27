#include <iostream>
using namespace std;

class Logger {
    public :
    void log(string message) {
        cout << "[LOG] : " << message << endl;
    }
};

class FileManager : private Logger {
    public :
    void saveFile(string fileName) {
        log("Attempting to save" + fileName);
        cout << "File Saved : " << fileName;
    }
};

int main() {
    FileManager myFiles;
    myFiles.saveFile("helloworld.cpp");
    myFiles.log("Updated.");
    /*Function call fails because FileManager class privately inherents all public member 
      members and functions of Logger Class. So, they become inaccessible in main.*/
    return 0;
}