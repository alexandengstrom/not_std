#include "test_framework.hpp"

std::string format_with_spaces(int value)
{
    struct space_out : std::numpunct<char>
    {
        char do_thousands_sep() const override { return ' '; }
        std::string do_grouping() const override { return "\3"; }
    };

    std::stringstream ss;
    ss.imbue(std::locale(ss.getloc(), new space_out));
    ss << value;
    return ss.str();
}

void print_results(const std::string &data_structure, double not_std_duration, double std_duration, int iterations)
{
    const char BLUE_COLOR[] = "\033[36m";
    const char GREEN_COLOR[] = "\033[32m";
    const char RED_COLOR[] = "\033[31m";
    const char YELLOW_COLOR[] = "\033[33m";
    const char RESET_COLOR[] = "\033[0m";
    const double TOLERANCE = 0.1;

    double percentage_difference = ((not_std_duration - std_duration) / std_duration) * 100;

    std::cout << BLUE_COLOR << "Benchmark Report:" << RESET_COLOR << std::endl;
    std::cout << "Data Structure: " << data_structure << std::endl;
    std::cout << "Iterations: " << format_with_spaces(iterations) << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(20) << std::left << "not_std duration:" << not_std_duration << " ms" << std::endl;
    std::cout << std::setw(20) << std::left << "std duration:" << std_duration << " ms" << std::endl;

    std::cout << "Performance Analysis:" << std::endl;
    if (std::abs(percentage_difference) <= TOLERANCE)
    {
        std::cout << YELLOW_COLOR << "  - Performance is almost identical. Difference: "
                  << percentage_difference << "%" << RESET_COLOR << std::endl;
    }
    else if (not_std_duration < std_duration)
    {
        std::cout << GREEN_COLOR << "  - Performance improvement! " << percentage_difference
                  << "% faster than std version." << RESET_COLOR << std::endl;
    }
    else
    {
        std::cout << RED_COLOR << "  - Performance degradation. " << -percentage_difference
                  << "% slower than std version." << RESET_COLOR << std::endl;
    }

    // Footer
    std::cout << "------------------------------------------\n"
              << std::endl;
}

void compare_benchmarks(
    const std::string &data_structure,
    const std::function<void()> &not_std_benchmark,
    const std::function<void()> &std_benchmark,
    int iterations)
{
    auto run_and_time = [](const std::function<void()> &func) -> double
    {
        auto start_time = std::chrono::high_resolution_clock::now();
        func();
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        return static_cast<double>(duration.count());
    };

    double not_std_duration = run_and_time(not_std_benchmark);
    double std_duration = run_and_time(std_benchmark);

    print_results(data_structure, not_std_duration, std_duration, iterations);
}