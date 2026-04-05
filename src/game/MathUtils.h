#ifndef MATHUTILS_H
#define MATHUTILS_H

class MathUtils {
public:
    // Template function to keep a value between a min and max
    template <typename T>
    static T clamp(T value, T min, T max) {
        if (value < min) return min;
        if (value > max) return max;
        return value;
    }
};

#endif
