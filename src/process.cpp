#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(const int processId_) :
    processId_(processId_)
{
    user_ = LinuxParser::User(processId_);
    command_ = LinuxParser::Command(processId_);
}

// TODO: Return this process's ID
int Process::Pid() {
  return processId_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
  const int systemUpTimeSeconds = LinuxParser::UpTime();
  const int totalTimeActiveSeconds = LinuxParser::ActiveJiffies(processId_);
  const int processUpTimeSeconds = LinuxParser::UpTime(processId_);

  const int totalTimeSiceStartUp = systemUpTimeSeconds - processUpTimeSeconds;

  _cpuUsage = (1.0 * totalTimeActiveSeconds)/totalTimeSiceStartUp;
  return _cpuUsage; 
}

// TODO: Return the command that generated this process
string Process::Command() { return command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(processId_); }

// TODO: Return the user (name) that generated this process
string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { 
  return LinuxParser::UpTime(processId_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator>(Process const& a) const { 
  return this->_cpuUsage > a._cpuUsage; 
}
