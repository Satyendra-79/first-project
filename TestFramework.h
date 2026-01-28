#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>

/**
 * @brief Simple test framework for unit testing
 */
class TestFramework {
private:
    struct TestCase {
        std::string name;
        std::function<void()> testFunc;
    };

    std::vector<TestCase> tests;
    int passedTests;
    int failedTests;

public:
    TestFramework() : passedTests(0), failedTests(0) {}

    /**
     * @brief Register a test
     */
    void addTest(const std::string& name, std::function<void()> testFunc) {
        tests.push_back({name, testFunc});
    }

    /**
     * @brief Run all registered tests
     */
    int runAll() {
        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "    Running Unit Tests\n";
        std::cout << "========================================\n\n";

        for (const auto& test : tests) {
            try {
                std::cout << "Running: " << test.name << "... ";
                test.testFunc();
                std::cout << "✓ PASSED\n";
                passedTests++;
            } catch (const std::exception& e) {
                std::cout << "✗ FAILED\n";
                std::cout << "  Error: " << e.what() << "\n";
                failedTests++;
            }
        }

        std::cout << "\n";
        std::cout << "========================================\n";
        std::cout << "    Test Summary\n";
        std::cout << "========================================\n";
        std::cout << "Total Tests: " << tests.size() << "\n";
        std::cout << "Passed: " << passedTests << "\n";
        std::cout << "Failed: " << failedTests << "\n";
        std::cout << "========================================\n\n";

        return failedTests > 0 ? 1 : 0;
    }
};

/**
 * @brief Assertion macros
 */
#define ASSERT_TRUE(condition) \
    if (!(condition)) { \
        throw std::runtime_error("Assertion failed: " #condition); \
    }

#define ASSERT_FALSE(condition) \
    if (condition) { \
        throw std::runtime_error("Assertion failed: NOT " #condition); \
    }

#define ASSERT_EQUAL(expected, actual) \
    if ((expected) != (actual)) { \
        throw std::runtime_error("Expected: " + std::to_string(expected) + \
                                ", Got: " + std::to_string(actual)); \
    }

#define ASSERT_NOT_EQUAL(expected, actual) \
    if ((expected) == (actual)) { \
        throw std::runtime_error("Values should not be equal"); \
    }

#define ASSERT_NULL(ptr) \
    if ((ptr) != nullptr) { \
        throw std::runtime_error("Pointer should be NULL"); \
    }

#define ASSERT_NOT_NULL(ptr) \
    if ((ptr) == nullptr) { \
        throw std::runtime_error("Pointer should not be NULL"); \
    }

#endif // TEST_FRAMEWORK_H
