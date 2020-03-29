#pragma once

#include "Vec3.h"

class Ray {
  Vec3 origin_;
  Vec3 direction_;

  constexpr Ray(const Vec3 &origin, const Vec3 &direction) noexcept
      : origin_(origin), direction_(direction) {}

public:
  static Ray fromTwoPoints(const Vec3 &point1, const Vec3 &point2) {
    // TODO assert point1 != point2?
    return Ray(point1, (point2 - point1).normalised());
  }
  static Ray fromOriginAndDirection(const Vec3 &origin, const Vec3 &direction) {
    // TODO assert dir is normal?
    return Ray(origin, direction);
  }

  [[nodiscard]] constexpr const Vec3 &origin() const noexcept { return origin_; }
  [[nodiscard]] constexpr const Vec3 &direction() const noexcept { return direction_; }

  [[nodiscard]] constexpr Vec3 positionAlong(double alongRay) const noexcept {
    return origin_ + direction_ * alongRay;
  }
};
