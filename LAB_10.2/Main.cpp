#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void processFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cout << "Failed to open the input file " << inputFileName << endl;
        return;
    }

    if (!outputFile.is_open()) {
        cout << "Failed to open the output file " << outputFileName << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        size_t spacePos = line.find(' ');
        if (spacePos != string::npos) {
            for (size_t i = 0; i < spacePos; ++i) {
                if (isalpha(line[i])) {
                    outputFile << line[i];
                }
            }
            break;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Done!" << endl;
}

int main() {
    string inputFileName, outputFileName;
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    processFile(inputFileName, outputFileName);

    return 0;
}
