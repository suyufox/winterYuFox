

/***
 * @Author: suyufox shenming26@outlook.com
 * @Date: 2025-07-25 11:35:43 +0800
 * @LastEditors: suyufox shenming26@outlook.com
 * @LastEditTime: 2025-07-25 16:00:04 +0800
 * @FilePath: \\winterYufox\\tools\\wfox\\src\\commands\\build.cpp
 * @Description:
 * @
 * @Copyright (c) 2025 by ${git_name_email}, All Rights Reserved.
 */

#include <wfox/commands/build.h>

namespace build {
  Build::Build(build_option option) : m_option(option) {
    spdlog::debug("Build configuration:");
    spdlog::debug("Release mode: {}", m_option.release);

    // 实际构建逻辑示例
    if (m_option.release) {
      spdlog::info("Building in release mode...");
    } else {
      spdlog::info("Building in debug mode...");
    }
  }

    //void handle_build() {
    //    spdlog::info("Building project...");
    //}

    //void handle_dev() {
    //    spdlog::info("Running project...");
    //}

    //void handle_new(const string& project_name) {
    //    spdlog::info("Creating new project: {}", project_name);

    //    try {
    //        fs::create_directory(project_name);
    //    }
    //    catch (const fs::filesystem_error& e) {
    //        spdlog::error("Failed to create project: {}", e.what());
    //    }
    //}

    //void handle_init(string project_name, bool is_workspace, bool is_bin) {
    //    spdlog::info("Initializing project...");

    //    toml::table config;

    //    if (is_workspace) {
    //        auto workspace = toml::table{
    //            {"project_name", project_name}
    //        };
    //        config.insert("workspace", workspace);
    //    }
    //    else {
    //        if (is_bin) {
    //            auto package = toml::table{
    //                {"name", project_name},
    //                {"version", string{"1.0.0"}},
    //                {"description", string{"a app"}}
    //            };

    //            auto bin = toml::table{

    //            };
    //            config.insert("bin", bin);
    //            config.insert("package", package);
    //        }
    //        else {
    //            auto package = toml::table{
    //                {"name", project_name},
    //                {"version", string{"1.0.0"}},
    //                {"description", string{"a lib"}}
    //            };
    //            auto lib = toml::table{

    //            };
    //            config.insert("lib", lib);
    //            config.insert("package", package);
    //        }if (is_bin) {
    //            auto package = toml::table{
    //                {"name", project_name},
    //                {"version", string{"1.0.0"}},
    //                {"description", string{"a app"}}
    //            };

    //            auto bin = toml::table{

    //            };
    //            config.insert("bin", bin);
    //            config.insert("package", package);
    //        }
    //        else {
    //            auto package = toml::table{
    //                {"name", project_name},
    //                {"version", string{"1.0.0"}},
    //                {"description", string{"a lib"}}
    //            };
    //            auto lib = toml::table{

    //            };
    //            config.insert("lib", lib);
    //            config.insert("package", package);
    //        }
    //    }

    //    try {
    //        std::ofstream file("wfox.toml");
    //        file << config;
    //    }
    //    catch (const fs::filesystem_error& e) {
    //        std::cerr << "文件系统错误: " << e.what() << std::endl;
    //    }
    //}
}
