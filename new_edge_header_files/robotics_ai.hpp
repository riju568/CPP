#ifndef ROBOTICS_AI_HPP
#define ROBOTICS_AI_HPP

#pragma once

// C++23 Standard Headers

#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <chrono>
#include <cmath>
#include <concepts>
#include <condition_variable>
#include <execution>
#include <expected>
#include <filesystem>
#include <format>
#include <functional>
#include <future>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <memory>
#include <mutex>
#include <numbers>
#include <numeric>
#include <optional>
#include <print>
#include <queue>
#include <random>
#include <ranges>
#include <span>
#include <stack>
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
#include <vector>
#include <concepts>
#include <span>
#include <bit>
#include <ranges>
#include <expected>     // Modern error handling
#include <mdspan>       // Multidimensional array views
#include <print>        // std::print / std::println
#include <flat_map>     // Cache-friendly continuous memory associative map
#include <flat_set>     // Continuous memory set
#include <generator>    // Coroutine generators
#include <stacktrace>   // Native stack traces for debugging
#include <spanstream>  // Fixed-buffer stream I/O
#include <stdfloat>     // Extended floating-point types (e.g., std::float16_t)

// Data Structures and Containers
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
#include <map>
#include <tuple>
#include <optional>
#include <variant>

// Algorithms, Math, and Numerics
#include <algorithm>
#include <numeric>
#include <cmath>
#include <random>
#include <limits>

// Stream Handling and Text I/O
#include <iostream>
#include <sstream>
#include <fstream>

// Memory Management and System Utilities
#include <memory>
#include <utility>
#include <type_traits>
#include <chrono>
#include <functional>

// Concurrency and Threading Infrastructure
#include <thread>
#include <mutex>
#include <future>
#include <atomic>
#include <condition_variable>
#include <execution>


// 2. THIRD-PARTY LINEAR ALGEBRA AND NUMERICAL HEADERS


#ifdef USE_EIGEN
    #include <Eigen/Core>
    #include <Eigen/Dense>
#endif

#ifdef USE_MLPACK
    #include <mlpack/core.hpp>
#endif

#ifdef USE_DLIB
    #include <dlib/matrix.h>
#endif


// 3. COMPUTER VISION AND PERCEPTION HEADERS

#ifdef USE_OPENCV
    #include <opencv2/opencv.hpp>
    #include <opencv2/core.hpp>
    #include <opencv2/imgproc.hpp>
    #include <opencv2/highgui.hpp>
#endif


// 4. DEEP LEARNING INFERENCE ENGINE HEADERS


#ifdef USE_LIBTORCH
    #include <torch/torch.h>
    #include <torch/script.h>
#endif

#ifdef USE_TENSORFLOW
    #include <tensorflow/core/public/session.h>
    #include <tensorflow/core/platform/env.h>
#endif


// 5. NATURAL LANGUAGE PROCESSING (NLP) HEADERS


#ifdef USE_FASTTEXT
    #include <fasttext/fasttext.h>
#endif


// 6. HARDWARE ACCELERATION AND PARALLEL COMPUTE HEADERS


#ifdef USE_CUDA
    #include <cuda_runtime.h>
    #include <cublas_v2.h>
#endif

#ifdef USE_OPENCL
    #include <CL/cl.h>
#endif


// 7. Standard C++23 Core & Utilities

#include <cstdint>
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <functional>
#include <system_error>

// POSIX Networking, Sockets & Transport Protocols

#if defined(__linux__) || defined(__APPLE__)
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/mman.h>     // MMIO & DMA buffer management
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#endif


// Low-Level Hardware Drivers & Bus Protocols (Linux Kernel Interfaces)

#if defined(__linux__)
// CAN Bus (SocketCAN, ISO-TP, BCM)
#include <linux/can.h>
#include <linux/can/raw.h>
#include <linux/can/bcm.h>
#include <linux/can/error.h>
#include <linux/can/isotp.h>

// Serial, I2C, SPI, GPIO, USB Hardware
#include <linux/serial.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <linux/spi/spidev.h>
#include <gpiod.h>             // Modern Linux libgpiod interface
#include <libusb-1.0/libusb.h> // Raw USB transfer driver interface

// Camera, Audio & Input Device Hardware Drivers
#include <linux/videodev2.h>  // Video4Linux2 (V4L2) camera driver stack
#include <linux/input.h>     // Linux input subsystem (Joysticks/Sensors)
#include <linux/uinput.h>    // Userland input device driver emulator
#include <sound/asoundlib.h>  // ALSA native audio driver API

// Wireless Hardware, Wi-Fi 5/6/7 ISM Bands & SoftAP Interfaces
#include <linux/wireless.h>
#include <netlink/netlink.h>
#include <netlink/genl/genl.h>
#include <linux/nl80211.h>   // Low-level netlink Wi-Fi driver interface

// Bluetooth Protocol Stack Drivers (HCI, L2CAP, RFCOMM, BNEP/PAN)
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/l2cap.h>
#include <bluetooth/bnep.h>   // Bluetooth Network Encapsulation Protocol (PAN)
#include <bluetooth/sco.h>
#endif

// Network File Protocols, Security & Service Discovery

#include <curl/curl.h>        // FTP, SFTP, HTTP client transfers
#include <libssh2.h>          // Direct SFTP/SSH hardware access
#include <openssl/ssl.h>      // TLS/SSL Encryption
#include <openssl/err.h>

#if defined(__linux__) || defined(__APPLE__)
#include <avahi-client/client.h>          // mDNS / Zeroconf service discovery
#include <avahi-common/simple-watch.h>    // Used for Wireless ADB / SoftAP discovery
#endif


// Mobile Debugging & Tethering Protocols (Android ADB & iOS usbmuxd)

#if defined(__linux__) || defined(__APPLE__)
#include <libimobiledevice/libimobiledevice.h>
#include <libimobiledevice/lockdown.h>
#include <libimobiledevice/usbmuxd.h>     // iOS Developer Mode USB multiplexer
#endif


// WebAssembly Runtime (Wasmtime Sandbox Engine)

#include <wasm.h>
#include <wasmtime.h>
#include <wasmtime-platform.h>


// Visualization & GUI (Dear ImGui)

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>


// Web Framework & Serialization

#include <drogon/drogon.h>
#include <drogon/HttpAppFramework.h>
#include <nlohmann/json.hpp>


// Math & Linear Algebra

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>


// Computer Vision

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


// Robotics Middleware (ROS 1 & ROS 2)

#include <rclcpp/rclcpp.hpp>

#ifdef USE_ROS1
#include <ros/ros.h>
#endif


// Deep Learning & Machine Learning

#include <torch/torch.h>             // LibTorch (PyTorch C++ API)
#include <torch/script.h>
#include <onnxruntime_cxx_api.h>     // ONNX Runtime
#include <tensorflow/core/public/session.h> // TensorFlow C++
#include <tensorflow/core/platform/env.h>
#include <dlib/matrix.h>             // Dlib
#include <dlib/image_processing.h>
#include <dlib/dnn.h>
#include <mlpack/core.hpp>           // MLpack

#endif // ROBOTICS_AI_HPP

