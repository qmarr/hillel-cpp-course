#include <CLI/CLI.hpp>
#include <spdlog/spdlog.h>
#include <fmt/format.h>

int main(int argc, char** argv) {
    CLI::App app{"ProjectManager CLI"};
    bool verbose = false;
    app.add_flag("-v,--verbose", verbose, "Enable verbose output");
    CLI11_PARSE(app, argc, argv);

    spdlog::set_level(verbose ? spdlog::level::debug : spdlog::level::info);
    spdlog::info("Hello from ProjectManager!");
    spdlog::debug("Debug on");

    fmt::print("fmt works: 2 + 2 = {}\n", 2 + 2);
    return 0;
}
