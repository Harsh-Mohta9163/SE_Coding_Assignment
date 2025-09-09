#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;

// Helper to get a formatted timestamp string
inline string getCurrentTimestamp() {
    auto now = chrono::system_clock::now();
    auto in_time_t = chrono::system_clock::to_time_t(now);
    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}