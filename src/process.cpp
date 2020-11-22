#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() {
    return pid_;
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { return 0; }

// TODO: Return the command that generated this process
string Process::Command() {
    return LinuxParser::Command(pid_);
}

// TODO: Return this process's memory utilization
string Process::Ram() {
    string ram_kb = LinuxParser::Ram(pid_);
    Process::ram_mb = std::stoi(ram_kb)/1000;
    return to_string(Process::ram_mb);
}

// TODO: Return the user (name) that generated this process
string Process::User() {
    Process::user_name = LinuxParser::User(pid_);
    return Process::user_name;
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {
    return LinuxParser::UpTime(pid_);
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
    // logic for sorting by ram
    int ram_a = this->ram_mb;
    int ram_b = a.ram_mb;
    return ram_a > ram_b;
}