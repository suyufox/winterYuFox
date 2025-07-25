#include <wfox/main.h>
#include <wfox/command.h>
#include <wfox/commands/build.h>
#include <wfox/commands/init.h>

using fmt::print;
using std::string;
namespace fs = std::filesystem;

int main(int argc, char** argv) {
  spdlog::info("Initializing the scaffolding... | 初始化脚手架中...");
  fmt::println("-----------------------------------------------------");
  Application app{ string{"wfox"} };

  app.set_description(string{ "winter fox cli | winter fox 脚手架工具" });

  {
    bool build_release{ false };
    app.add_subcommand("build", "Build Project | 构建项目",
      [&](CLI::App* cmd) {
        cmd->add_flag("--release", build_release, "Release build | 发布模式构建");
      },
      [&]() {
        spdlog::info("build");
        using build::build_option;
        using build::Build;
        build_option option;

        option.release = build_release;
        
        Build build { option };
      });
  }

  {
    string project_name;
    app.add_subcommand("init", "Init Project | 初始化项目",
      [&](CLI::App* cmd) {
        cmd->add_option("name", project_name, "Project Name")->required();
        
      },
      [&]() {
        using init::init_option;
        using init::Init;

        init_option option;

        option.project_name = project_name;

        Init init{ option };

        spdlog::info("Initializing the environment... | 初始化环境中...");
        init.check_git();

        //spdlog::info("In the pull template... | 拉取模版中...");
        init.run(option);
      });
  }

  return app.run(argc, argv);
}
