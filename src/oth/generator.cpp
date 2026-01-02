#include <oth/logic/generator.hpp>

#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>

std::string Generator::generateId(const std::string& name){
    auto now = std::chrono::system_clock::now();
    std::time_t t_now = std::chrono::system_clock::to_time_t(now);

    std::tm* tm_now = std::localtime(&t_now);
    std::stringstream ss;
    ss << std::put_time(tm_now, "%Y%m%d%H%M%S");
    ss << "_" << name;

    return ss.str();
}