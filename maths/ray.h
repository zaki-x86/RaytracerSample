#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/**
 * @brief A ray is a function of the form p(t) = A + tb, where A is the ray's origin, b is the ray's direction, and t is a real number.
 * 
 */
class ray {
    public:
        ray() {}
        ray(const point3& origin, const vec3& direction)
            : orig(origin), dir(direction)
        {}

        point3 origin() const  { return orig; }
        vec3 direction() const { return dir; }

        /// @brief Returns the point at parameter t along the ray.
        point3 at(double t) const {
            return orig + t*dir;
        }

    public:
        point3 orig;
        vec3 dir;
};

#endif