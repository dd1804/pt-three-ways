#pragma once

#include <cstddef>

class Progressifier {
  size_t numWork_{};
  double minProgress_{5.0};
  double lastProgress_{};

public:
  explicit Progressifier(size_t numWork);

  void update(double numDone) noexcept;
};
