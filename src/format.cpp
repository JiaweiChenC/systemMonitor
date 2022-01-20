#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  string time = "00:00:00";
  long num = 0;
  if (seconds > 0) {
    num   = seconds / 3600;
    time += TimeValueToString(num) + ":";
    num   = (seconds / 60 ) % 60;
    time += TimeValueToString(num) + ":";
    num   = seconds % 60;
    time += TimeValueToString(num) + ":";
  }
  return time;
}
  
std::string Format::TimeValueToString(long time) {
  if (time < 10)
    return "0" + std::to_string(time);
  else
    return std::to_string(time);
}
