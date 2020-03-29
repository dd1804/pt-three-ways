#include "OrthoNormalBasis.h"

#include <cstdio>

OrthoNormalBasis OrthoNormalBasis::fromXY(const Vec3 &x, const Vec3 &y) {
  auto xx = x.normalised();
  auto zz = x.cross(y).normalised();
  auto yy = zz.cross(xx);
  return OrthoNormalBasis(xx, yy, zz);
}

OrthoNormalBasis OrthoNormalBasis::fromYX(const Vec3 &y, const Vec3 &x) {
  auto yy = y.normalised();
  auto zz = x.cross(y).normalised();
  auto xx = yy.cross(zz);
  return OrthoNormalBasis(xx, yy, zz);
}

OrthoNormalBasis OrthoNormalBasis::fromXZ(const Vec3 &x, const Vec3 &z) {
  auto xx = x.normalised();
  auto yy = z.cross(x).normalised();
  auto zz = xx.cross(yy);
  return OrthoNormalBasis(xx, yy, zz);
}

OrthoNormalBasis OrthoNormalBasis::fromZX(const Vec3 &z, const Vec3 &x) {
  auto zz = z.normalised();
  auto yy = z.cross(x).normalised();
  auto xx = yy.cross(zz);
  return OrthoNormalBasis(xx, yy, zz);
}

OrthoNormalBasis OrthoNormalBasis::fromYZ(const Vec3 &y, const Vec3 &z) {
  auto yy = y.normalised();
  auto xx = y.cross(z).normalised();
  auto zz = xx.cross(yy);
  return OrthoNormalBasis(xx, yy, zz);
}

OrthoNormalBasis OrthoNormalBasis::fromZY(const Vec3 &z, const Vec3 &y) {
  auto zz = z.normalised();
  auto xx = y.cross(z).normalised();
  auto yy = zz.cross(xx);
  return OrthoNormalBasis(xx, yy, zz);
}

namespace {
const double Coincident = 0.9999;
}

OrthoNormalBasis OrthoNormalBasis::fromZ(const Vec3 &z) {
  auto zz = z.normalised();
  auto xx =
      (fabs(zz.dot(Vec3::xAxis())) > Coincident ? Vec3::yAxis() : Vec3::xAxis())
          .cross(zz)
          .normalised();
  auto yy = zz.cross(xx).normalised();
  return OrthoNormalBasis(xx, yy, zz);
}
