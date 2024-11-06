#include <iostream>
#include <cstdarg>
using namespace std;


#define GENERATE_ERROR_MESSAGE(errorCode, ...) generateErrorMessage(errorCode, __VA_ARGS__, nullptr)


void generateErrorMessage(int errorCode, ...) {
    cout << "Error Code " << errorCode << ": ";

    va_list args;
    va_start(args, errorCode);

    const char* word;
    
    while ((word = va_arg(args, const char*)) != nullptr) {
        cout << word << " ";
    }

    va_end(args);
    cout << endl;
}

int main() {
    
    GENERATE_ERROR_MESSAGE(1, "File", "not", "found");
    GENERATE_ERROR_MESSAGE(2, "Invalid", "user", "input");
    GENERATE_ERROR_MESSAGE(3, "Connection", "timed", "out");

    return 0;
}
