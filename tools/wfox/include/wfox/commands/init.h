#pragma once

#include <spdlog/spdlog.h>
#include <iostream>
#include <stdlib.h>

namespace init {
  struct init_option
  {
    std::string project_name;


  };

  class Init {
  public:
    explicit Init(init_option option);
    ~Init() = default;

    void run(init_option option);
    void check_git();
  private:
    init_option m_option;
  };

}
