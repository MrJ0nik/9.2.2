#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <sstream>

#include "../9.2.2/9.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestGenerateErrorMessage_FileNotFound)
        {
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            // Test case for "File not found" message
            GENERATE_ERROR_MESSAGE(1, "File", "not", "found");

            // Restore std::cout
            std::cout.rdbuf(oldCout);

            // Verify the output
            Assert::AreEqual(std::string("Error Code 1: File not found \n"), buffer.str());
        }

        TEST_METHOD(TestGenerateErrorMessage_InvalidUserInput)
        {
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            // Test case for "Invalid user input" message
            GENERATE_ERROR_MESSAGE(2, "Invalid", "user", "input");

            // Restore std::cout
            std::cout.rdbuf(oldCout);

            // Verify the output
            Assert::AreEqual(std::string("Error Code 2: Invalid user input \n"), buffer.str());
        }

        TEST_METHOD(TestGenerateErrorMessage_ConnectionTimedOut)
        {
            std::stringstream buffer;
            std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());

            // Test case for "Connection timed out" message
            GENERATE_ERROR_MESSAGE(3, "Connection", "timed", "out");

            // Restore std::cout
            std::cout.rdbuf(oldCout);

            // Verify the output
            Assert::AreEqual(std::string("Error Code 3: Connection timed out \n"), buffer.str());
        }
    };
}
