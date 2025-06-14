#include <iostream>
#include <iomanip>
#include "far.h"
#include "compare.h"

using namespace far;

int main([[maybe_unused]]int argc, char** argv){

  std::cout << "Testing spacing " << argv[0] << "\n";

		if (std::numeric_limits<float>::is_iec559) {
      std::cout << "IEEE 754 float support found. Testing true spacing\n";
      if (spacing(0.0f)!=1.175494350822287507968736537222245677819e-38) {
        std::cout << "Error: spacing(0.0f) != 0.0f\n";
        return -1;
      }
      if (spacing(1.0f)!=1.1920928955078125e-7) {
        std::cout << "Error: spacing(1.0f) != 1.1920928955078125e-7\n";
        return -1;
      }
      if (spacing(299792458.0f)!=32.0) {
        std::cout << "Error: spacing(299792458.0f) != 32.0\n";
        return -1;
      }
    }
    if (!std::isnan(spacing(std::numeric_limits<float>::quiet_NaN()))) {
      std::cout << "Error: spacing(std::numeric_limits<float>::quiet_NaN()) != std::numeric_limits<float>::quiet_NaN()\n";
      return -1;
    }
    if (!std::isnan(spacing(std::numeric_limits<float>::infinity()))) {
      std::cout << "Error: spacing(std::numeric_limits<float>::infinity()) != std::numeric_limits<float>::quiet_NaN()\n";
      return -1;
    }

    if (std::numeric_limits<double>::is_iec559) {
      std::cout << "IEEE 754 double support found. Testing true spacing\n";
      if (spacing(0.0)!=2.225073858507201383090232717332404064219e-308) {
        std::cout << "Error: spacing(0.0) != 2.220446049250313080847263336181640625e-16\n";
        std::cout << spacing(0.0) << std::endl;
        return -1;
      }
      if (spacing(1.0)!=2.220446049250313080847263336181640625e-16) {
        std::cout << "Error: spacing(1.0) != 2.220446049250313080847263336181640625e-16\n";
        std::cout << spacing(1.0) << std::endl;
        return -1;
      }
      if (spacing(299792458.0)!=5.9604644775390625e-08) {
        std::cout << "Error: spacing(299792458.0) != 64.0\n";
        return -1;
      }
    }

  std::cout << "All tests passed\n";

}
