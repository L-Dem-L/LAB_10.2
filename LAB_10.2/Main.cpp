#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void processFile(const string& inputFileName, const string& outputFileName) {
    // Opening files for reading and writing
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // Check if files were opened successfully
    if (!inputFile.is_open()) {
        cout << "Failed to open the input file " << inputFileName << endl;
        return;
    }

    if (!outputFile.is_open()) {
        cout << "Failed to open the output file " << outputFileName << endl;
        return;
    }

    // Reading lines from the input file
    string line;
    while (getline(inputFile, line)) {
        // Finding the first space in the line
        size_t spacePos = line.find(' ');
        if (spacePos != string::npos) {
            // Writing characters before the first space to the output file
            for (size_t i = 0; i < spacePos; ++i) {
                if (isalpha(line[i])) {
                    outputFile << line[i];
                }
            }
            // End the loop as the first space is found
            break;
        }
    }

    // Closing files
    inputFile.close();
    outputFile.close();

    cout << "Done!" << endl;
}

int main() {
    // File name input
    string inputFileName, outputFileName;
    cout << "Enter the name of the input file: ";
    cin >> inputFileName;
    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    processFile(inputFileName, outputFileName);

    return 0;
}
