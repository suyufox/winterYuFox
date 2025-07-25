#include <wfox/commands/init.h>

namespace init {
  Init::Init(init_option option) : m_option(option) {
    spdlog::debug("Build configuration:");

  }

  void Init::run(init_option option) {

  }

  void Init::check_git() {
    spdlog::info("Check the availability of Git | 检查 Git 可用性");
    std::cout << "------------------------" << "\n";
    std::cout << "Git Cheak:" << "\n";
    std::cout << "------------------------" << "\n";
    std::system("git --version");
    std::cout << "------------------------" << "\n";
  }
}

