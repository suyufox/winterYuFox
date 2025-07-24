/*** 
 * @Author: suyufox shenming26@outlook.com
 * @Date: 2025-07-23 17:56:57 +0800
 * @LastEditors: suyufox shenming26@outlook.com
 * @LastEditTime: 2025-07-24 12:48:17 +0800
 * @FilePath: \\winterYufox\\tools\\wfox\\src\\main.cpp
 * @Description: 
 * @
 * @Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <wfox/main.h>


using fmt::print;
using std::string;

int main(int argc, char** argv) {
    CLI::App app;

    app.name(string{ "wfox" });
    app.description(string{ "winter fox manager" });

    auto build_command = app.add_subcommand("build",  "Build Project | 构建项目");
    auto run_command   = app.add_subcommand("run",    "Run Project | 运行项目");
    auto new_command   = app.add_subcommand("new",    "Create Project | 创建项目");

    app.add_flag("-v,--verbose", "详细输出 | Detailed output");

    try {
        app.parse(argc, argv);

        if (app.get_subcommands().empty()) {
            return app.exit(CLI::CallForHelp());
        }
    }
    catch (const CLI::ParseError& e) {
        return app.exit(e);
    }
    // 2. 使用spdlog记录
    //spdlog::info("启动服务，端口: {}", port);

    // 3. 显示进度条
    // indicators::ProgressBar bar{
    //     indicators::option::BarWidth{50},
    //     indicators::option::Start{"["},
    //     indicators::option::End{"]"},
    //     indicators::option::ShowPercentage{true}
    // };

    // for (int i = 0; i <= 100; ++i) {
    //     bar.set_progress(i);
    //     std::this_thread::sleep_for(std::chrono::milliseconds(50));
    // }

    return 0;
}