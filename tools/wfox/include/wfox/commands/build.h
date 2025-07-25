#pragma once

#include <spdlog/spdlog.h>

namespace build {
  struct build_option
  {
    bool release{false};
  };

  class Build {
  public:
    explicit Build(build_option option);
    ~Build() = default;
  private:
    build_option m_option;
  };

}
