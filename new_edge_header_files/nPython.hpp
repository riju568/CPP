#pragma once

#include "python_runtime.hpp"
#include 'robotics_ai.hpp"

inline int nPython() {
    std::println("Initializing Full-Stack nPython.");

    // C++ code with Python runtime macros 
    PYTHON_RUNTIME(
        !pip install fastapi uvicorn numpy

        // 2. Import your separate Python files (e.g., settings.py, setup.py, server.py)
        import settings
        import setup
        import server

        print("--- Executing Python Modules ---")
        
        # 3. Call functions in python files
        setup.initialize_environment()
        
        print(f"Server Configuration Loaded from settings.py: port={settings.PORT}")
        
        server.start_server()
    );

    std::println("C++ Application finished successfully.");
    return 0;
}
