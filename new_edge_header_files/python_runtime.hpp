#ifndef PYTHON_RUNTIME_HPP
#define PYTHON_RUNTIME_HPP

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

namespace py = pybind11;
namespace python_ai_runtime {
    inline void initialize_runtime() {
        if (!Py_IsInitialized()) {
            py::initialize_interpreter();
            try {
                py::module_ sys = py::module_::import("sys");
                py::list path = sys.attr("path");
                std::string current_dir = std::filesystem::current_path().string();
                path.attr("insert")(0, current_dir);
            } catch (const py::error_already_set& e) {
                std::println(stderr, "[PythonRuntime Warning] Failed to configure sys.path: {}", e.what());
            }
        }
    }

    inline void process_code_block(std::string_view raw_code) {
        initialize_runtime();

        std::istringstream stream{std::string(raw_code)};
        std::string line;
        std::string python_buffer;

        while (std::getline(stream, line)) {
            size_t start = line.find_first_not_of(" \t\r\n");
            if (start == std::string::npos) continue;
            std::string trimmed = line.substr(start);

            if (trimmed.starts_with("!pip")) {
                std::string packages = trimmed.substr(4);
                size_t p_start = packages.find_first_not_of(" \t");
                if (p_start != std::string::npos) {
                    packages = packages.substr(p_start);
                    if (packages.starts_with("install")) {
                        packages = packages.substr(7);
                        size_t clean_start = packages.find_first_not_of(" \t");
                        if (clean_start != std::string::npos) packages = packages.substr(clean_start);
                    }
                }

                try {
                    std::println("[PythonRuntime] Managing packages via pip: {}", packages);
                    py::module_ subprocess = py::module_::import("subprocess");
                    py::module_ sys = py::module_::import("sys");
                    
                    py::list args;
                    args.append(sys.attr("executable"));
                    args.append("-m");
                    args.append("pip");
                    args.append("install");
                    
                    std::istringstream pkg_stream(packages);
                    std::string pkg;
                    while (pkg_stream >> pkg) {
                        args.append(pkg);
                    }
                    
                    subprocess.attr("check_call")(args);
                } catch (const py::error_already_set& e) {
                    std::println(stderr, "[PythonRuntime Error] Pip installation failed: {}", e.what());
                }
            } else {
                python_buffer += line + "\n";
            }
        }

        if (!python_buffer.empty()) {
            try {
                py::exec(python_buffer);
            } catch (const py::error_already_set& e) {
                std::println(stderr, "[PythonRuntime Error] Python execution failed:\n{}", e.what());
            }
        }
    }
}

#define PYTHON_RUNTIME(...) \
    [&]() { \
        constexpr std::string_view code_block = #__VA_ARGS__; \
        python_ai_runtime::process_code_block(code_block); \
    }()

#endif // PYTHON_RUNTIME_HPP
