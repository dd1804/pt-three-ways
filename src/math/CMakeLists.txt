add_library(math Vec3.cpp Vec3.h Sphere.cpp Sphere.h Ray.cpp Ray.h Hit.h CeSupt.h Camera.cpp Camera.h OrthoNormalBasis.cpp OrthoNormalBasis.h)
target_include_directories(math INTERFACE ..)