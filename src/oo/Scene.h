#pragma once

#include <vector>
#include <memory>

#include "oo/Primitive.h"

class Scene : public Primitive {
  std::vector<std::unique_ptr<Primitive>> primitives_;
public:
  void add(std::unique_ptr<Primitive> primitive);
  [[nodiscard]] std::optional<IntersectionRecord> intersect(const Ray &ray) const override;
};
