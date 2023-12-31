#ifndef _H_MATH_VECTORS_
#define _H_MATH_VECTORS_
#define RAD2DEG(x) ((x) * 57.295754f)
#define DEG2RAD(x) ((x) * 0.0174533f)
#include <ostream>

typedef struct vec2{
  union{
    struct{
      float x;
      float y;
    };
    float asArray[2];
  };
  float& operator[](int i){
    return asArray[i];
  }
} vec2;

typedef struct vec3{
  union{
    struct{
      float x;
      float y;
      float z;
    };
    float asArray[3];
  };
  float& operator[](int i){
    return asArray[i];
  }
} vec3;

vec2 operator+(const vec2& l, const vec2& r);
vec2 operator-(const vec2& l, const vec2& r);
vec2 operator*(const vec2& l, const vec2& r);
vec2 operator*(const vec2& l, float r);
bool operator==(const vec2& l, const vec2& r); 
bool operator!=(const vec2& l, const vec2& r); 
float Dot(const vec2& l, const vec2& r);
float Magnitude(const vec2& v);
float Magnitude(const vec2& l, const vec2& r);
float MagnitudeSq(const vec2& v);
void Normalize(vec2& v);
vec2 Normalized(const vec2& v);
float Angle(const vec2& l, const vec2& r);
vec2 Project(const vec2& len, const vec2& dir);
vec2 Perpendicular(const vec2& len, const vec2& dir);
vec2 Reflection(const vec2& vec, const vec2& normal);
std::ostream& operator<<(std::ostream& out, const vec2& v);

vec3 operator+(const vec3& l, const vec3& r);
vec3 operator-(const vec3& l, const vec3& r);
vec3 operator*(const vec3& l, const vec3& r);
vec3 operator*(const vec3& l, float r);
bool operator==(const vec3& l, const vec3& r); 
bool operator!=(const vec3& l, const vec3& r); 
float Dot(const vec3& l, const vec3& r);
float Magnitude(const vec3& v);
float Magnitude(const vec3& l, const vec3& r);
float MagnitudeSq(const vec3& v);
void Normalize(vec3& v);
vec3 Normalized(const vec3& v);
vec3 Cross(const vec3& l, const vec3& r);
float Angle(const vec3& l, const vec3& r);
vec3 Project(const vec3& len, const vec3& dir);
vec3 Perpendicular(const vec3& len, const vec3& dir);
vec3 Reflection(const vec3& vec, const vec3& normal);
std::ostream& operator<<(std::ostream& out, const vec3& v);

#endif
