#include "test_framework.hpp"

std::vector<Test_Result> test_results;

std::vector<std::function<void()>> string_tests;
std::vector<std::function<void()>> pair_tests;
std::vector<std::function<void()>> priority_queue_tests;
std::vector<std::function<void()>> vector_tests;
std::vector<std::function<void()>> unordered_map_tests;
std::vector<std::function<void()>> list_tests;

void unit_test(bool condition, const std::string &test_name, const std::string &fail_reason)
{
    Test_Result result;
    result.success = condition;
    result.test_name = test_name;

    if (!condition)
    {
        result.fail_reason = fail_reason.empty() ? "Unknown reason" : fail_reason;
    }

    test_results.push_back(result);
}

void run_tests(const std::vector<std::function<void()>> &tests, const std::string &group_name)
{
    std::cout << "Running tests for " << group_name << ":\n\n";

    for (auto &test : tests)
    {
        test();
    }

    size_t tests_counter{0};
    size_t tests_passed{0};

    for (const auto &result : test_results)
    {
        if (result.success)
        {
            tests_passed++;
        }
        else
        {
            std::cout << "  \033[31m\u2717\033[0m " << result.test_name;
            std::cout << " [Fail reason: " << result.fail_reason << "]\n";
        }

        tests_counter++;
    }

    if (tests_passed == tests_counter)
    {
        std::cout << "  \033[32m" << tests_passed << "/" << tests_counter << "\033[0m " << std::endl;
    }
    else
    {
        std::cout << "  \033[31m" << tests_passed << "/" << tests_counter << "\033[0m "
                  << ": " << (tests_counter - tests_passed) << " test failed" << std::endl;
    }

    std::cout << "\n";

    test_results.clear();
}
