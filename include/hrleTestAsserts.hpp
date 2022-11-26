#pragma once

#include <stdexcept>
#include <string>

// Fix for builds on Windows since MSVC does not expose __PRETTY_FUNCTION__
#ifdef _MSC_VER
#define __PRETTY_FUNCTION__ __FUNCSIG__
#endif

#define HRLETEST_ASSERT(condition)                                             \
  {                                                                            \
    if (!(condition)) {                                                        \
      throw std::runtime_error(std::string(__FILE__) + std::string(":") +      \
                               std::to_string(__LINE__) +                      \
                               std::string(" in ") +                           \
                               std::string(__PRETTY_FUNCTION__));              \
    }                                                                          \
  }
