

/*** 
 * @Author: suyufox shenming26@outlook.com
 * @Date: 2025-07-23 17:56:57 +0800
 * @LastEditors: suyufox shenming26@outlook.com
 * @LastEditTime: 2025-07-25 16:27:27 +0800
 * @FilePath: \\winterYufox\\tools\\wfox\\src\\main.cpp
 * @Description: 
 * @
 * @Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <wfox/main.h>
#include <wfox/command.h>
#include <wfox/commands/build.h>

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
      [&]() {
        spdlog::info("build");
        using build::build_option;
        using build::Build;
        build_option option {
          .release = build_release,
        };
        Build build { option };
      },
      [&](CLI::App* cmd) {
        cmd->add_flag("--release", build_release, "Release build | 发布模式构建");
      });
  }

  {
    app.add_subcommand("bundle", "Bundle Project | 打包项目",
      [&]() {

      },
      [&](CLI::App*) {

      });
  }

  {
    app.add_subcommand("dev", "Run Project | 运行项目",
      [&]() {

      },
      [&](CLI::App*) {

      });
  }

  {
    string project_name;
    app.add_subcommand("new", "Create Project | 创建项目",
      [&]() {

      },
      [&](CLI::App* cmd) {
        cmd->add_option("name", project_name, "Project name")->required();
      });
  }

  {
    string project_name;
    bool is_workspace{ false };
    bool is_bin{ true };
    app.add_subcommand("init", "Init Project | 初始化项目",
      [&]() {

      },
      [&](CLI::App* cmd) {
        cmd->add_option("name", project_name, "Project Name");

        auto workspace_flag = cmd->add_flag("-w,--workspace", is_workspace, "Create a workspace?");
        auto bin_flag = cmd->add_flag("--bin", is_bin, "Create a binary project (default)");
        auto lib_flag = cmd->add_flag("--lib", [&](size_t count) {is_bin = (count == 0);}, "Create a library project");

        bin_flag->excludes(lib_flag);
        lib_flag->excludes(bin_flag);
        workspace_flag->excludes(lib_flag);
        workspace_flag->excludes(bin_flag);
      });
  }

  return app.run(argc, argv);
}
