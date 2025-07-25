#include <wfox/command.h>

Application::Application(string name) {
  app.name(name);
}

void Application::set_description(const std::string& description) {
  app.description(description);
}

int Application::run(int argc, char** argv) {
	bool verbose{ false };
	app.add_flag("-v,--verbose", verbose, "详细输出 | Detailed output");

	try {
		app.parse(argc, argv);

		if (verbose) {
			spdlog::set_level(spdlog::level::debug);
		}

		if (app.get_subcommands().empty()) {
			return app.exit(CLI::CallForHelp());
		}
		return 0;
	}
	catch (const CLI::ParseError& e) {
		return app.exit(e);
	}
}
