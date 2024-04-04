#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_10.2/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        TEST_METHOD(TestProcessFile)
        {
            // Prepare test files
            std::ofstream inputFile("input.txt");
            inputFile << "123abc def";
            inputFile.close();

            std::string outputFileName = "output.txt";

            // Call the function to be tested
            processFile("input.txt", outputFileName);

            // Check if output file was created
            std::ifstream outputFile(outputFileName);
            Assert::IsTrue(outputFile.is_open());

            // Read the content of the output file
            std::string outputContent;
            std::getline(outputFile, outputContent);

            // Check if the content is correct
            Assert::AreEqual(std::string("abc"), outputContent);

            // Clean up
            outputFile.close();
            std::remove("input.txt");
            std::remove(outputFileName.c_str());
        }
    };
}
