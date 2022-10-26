// Copyright 2009-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "platform.h"
#include <chrono>

namespace oidn {

  class Timer
  {
  public:
    Timer()
    {
      reset();
    }

    void reset()
    {
      start = clock::now();
    }

    double query() const
    {
      auto end = clock::now();
      return std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
    }

  private:
    using clock = std::chrono::steady_clock;

    std::chrono::time_point<clock> start;
  };

} // namespace oidn
