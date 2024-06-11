#pragma once

#include <cstdint>
#include <string>

class RateKeeper {
public:
  RateKeeper(const std::string &name, float rate, float print_delay_threshold = 0);
  ~RateKeeper() {}
  bool keepTime();
  bool monitorTime();
<<<<<<< HEAD
  inline uint64_t frame() const { return frame_; }
=======
  inline double frame() const { return frame_; }
>>>>>>> 8b9791041 (sunnypilot v2024.06.11-2039)
  inline double remaining() const { return remaining_; }

private:
  double interval;
  double next_frame_time;
  double last_monitor_time;
  double remaining_ = 0;
  float print_delay_threshold = 0;
  uint64_t frame_ = 0;
  std::string name;
};
