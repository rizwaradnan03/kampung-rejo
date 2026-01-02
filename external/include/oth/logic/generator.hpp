#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <string>

class Generator {
    public:
        static std::string generateId(const std::string& name);
};