#pragma once

#include <optional>
#include <utility>

#include "oo/Material.h"
#include "math/Hit.h"
#include "math/Ray.h"

class Primitive {
public:
  virtual ~Primitive() = default;
  struct IntersectionRecord{
    Hit hit;
    Material material;
  };
  virtual std::optional<IntersectionRecord> intersect(const Ray &ray) const = 0;
};
