#pragma once

#include <fmt/core.h>
#include <fmt/color.h>
#include <CLI/CLI.hpp>
#include <filesystem>
#include <spdlog/spdlog.h>
#include <fstream>
#include <iostream>
#include <optional>
#include <functional>
#include <memory>
#include <string>
#include <utility>

using std::string;

class Application {
public:
	CLI::App app;

	explicit Application(string name);
	~Application() = default;
	void set_description(const std::string& description);

	template <typename Callback>
	CLI::App* add_subcommand(const std::string& name,
		const std::string& description,
    std::function<void(CLI::App*)> setup,
		Callback&& callback) {
		auto* cmd = app.add_subcommand(name, description);
		setup(cmd);
		cmd->callback(std::forward<Callback>(callback));
		return cmd;
	}

	int run(int argc, char** argv);
private:

};

