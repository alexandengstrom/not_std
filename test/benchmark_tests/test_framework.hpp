#ifndef TEST_FRAMEWORK_HPP
#define TEST_FRAMEWORK_HPP

#include <functional>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <sstream>
#include <locale>

void compare_benchmarks(
    const std::string &data_structure,
    const std::function<void()> &not_std_benchmark,
    const std::function<void()> &std_benchmark,
    int iterations);

void print_results(
    const std::string &data_structure,
    double not_std_duration,
    double std_duration,
    int iterations);

void register_vector_test();
void register_unordered_map_test();
void register_list_test();
void register_priority_queue_test();
void register_string_test();
void register_set_test();
void register_bitset_test();

#endif