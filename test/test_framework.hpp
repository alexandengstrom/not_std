#ifndef TEST_FRAMEWORK_HPP
#define TEST_FRAMEWORK_HPP

#include <vector>
#include <string>
#include <iostream>
#include <functional>

struct Test_Result
{
    bool success;
    std::string test_name;
    std::string fail_reason;
};

extern std::vector<Test_Result> test_results;

void unit_test(bool condition, const std::string &test_name, const std::string &fail_reason = "");
void run_tests(const std::vector<std::function<void()>> &tests, const std::string &group_name);

extern std::vector<std::function<void()>> string_tests;
extern std::vector<std::function<void()>> pair_tests;
extern std::vector<std::function<void()>> priority_queue_tests;
extern std::vector<std::function<void()>> vector_tests;
extern std::vector<std::function<void()>> unordered_map_tests;

#define REGISTER_TEST(group, test) group.push_back(test)

void register_string_tests();
void register_pair_tests();
void register_priority_queue_tests();
void register_vector_tests();
void register_unordered_map_tests();

#endif