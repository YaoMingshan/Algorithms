#pragma once
#include <chrono>
#include <functional>
#include <iostream>
#include <optional>
#include <random>
#include <type_traits>
#include <utility>

template <typename T>
std::vector<T> GenRandomInput(uint32_t size, int32_t min = 0,
                              int32_t max = 10) {
  // std::random_device rd;
  auto seed = 0x1234;
  std::mt19937 engine(seed);

  std::uniform_int_distribution<T> dist(min, max);
  std::vector<T> input;
  for (uint32_t i = 0; i < size; ++i) {
    input.push_back(dist(engine));
  }

  return input;
}

auto TimeNow() { return std::chrono::high_resolution_clock::now(); }

uint64_t DurationSeconds(std::chrono::_V2::system_clock::time_point start,
                         std::chrono::_V2::system_clock::time_point end) {
  auto duration =
      std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
  std::cout << "Run duration: " << duration << " Seconds" << std::endl;
  return duration;
}

template <typename Func, typename... Args>
auto MeasureFuncExecTime(Func func, Args&&... args)
    -> std::enable_if_t<
        !std::is_void_v<decltype(func(std::forward<Args>(args)...))>,
        std::pair<std::optional<decltype(func(std::forward<Args>(args)...))>,
                  uint64_t>> {
  auto start = TimeNow();
  std::optional<decltype(func(std::forward<Args>(args)...))> result;
  try {
    result = func(std::forward<Args>(args)...);
  } catch (...) {
    throw;
  }
  auto end = TimeNow();
  auto seconds = DurationSeconds(start, end);
  return std::make_pair(result, seconds);
}

template <typename Func, typename... Args>
auto MeasureFuncExecTime(Func func, Args&&... args)
    -> std::enable_if_t<
        std::is_void_v<decltype(func(std::forward<Args>(args)...))>,
        std::pair<std::optional<std::monostate>, uint64_t>> {
  auto start = TimeNow();
  try {
    func(std::forward<Args>(args)...);
  } catch (...) {
    throw;
  }
  auto end = TimeNow();
  auto seconds = DurationSeconds(start, end);
  return std::make_pair(std::optional<std::monostate>{std::monostate{}},
                        seconds);
}