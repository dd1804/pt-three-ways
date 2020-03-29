#pragma once

#include <vector>
#include <mutex>
#include <optional>

#include "Progressifier.h"

template <typename WorkItem> class WorkQueue {
  std::mutex mutex_;
  std::vector<WorkItem> todo_;
  Progressifier progress_;

public:
  explicit WorkQueue(std::vector<WorkItem> todo) noexcept
      : todo_(std::move(todo)), progress_(todo_.size()) {}

  std::optional<WorkItem> pop() noexcept {
    std::unique_lock lock(mutex_);
    progress_.update(todo_.size());
    if (todo_.empty())
      return {};
    auto tile = todo_.back();
    todo_.pop_back();
    return tile;
  }
};
