#include <vector>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    // Input ranges
    std::vector<int> input_ranges = {10000, 50000, 100000};

    // Bubble sort times for ascending data
    std::vector<double> asc_times = {1.2, 1.3, 2.1};

    // Bubble sort times for descending data
    std::vector<double> desc_times = {1.3, 1.4, 2.2};

    // Bubble sort times for random data
    std::vector<double> random_times = {1.5, 1.5, 2.3};

    // Plot the data using named_plot
    plt::named_plot("Ascending Data", input_ranges, asc_times, "r-o");
    plt::named_plot("Descending Data", input_ranges, desc_times, "g-o");
    plt::named_plot("Random Data", input_ranges, random_times, "b-o");

    // Add labels and title
    plt::xlabel("Input Range");
    plt::ylabel("Time (s)");
    plt::title("Bubble Sort Performance");
    plt::legend();

    // Show the plot
    plt::show();

    return 0;
}

