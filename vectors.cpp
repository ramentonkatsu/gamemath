#include "vectors.h"
#include <cmath>
#include <cfloat>

#define CMP(x,y)                          \
  (fabsf((x)-(y)) <= FLT_EPSILON *        \
    fmaxf(1.0f,                           \
    fmaxf(fabsf(x), fabsf(y)))            \
  )

vec2 operator+(const vec2& l, const vec2& r){
  return { l.x + r.x, l.y + r.y };
}
vec2 operator-(const vec2& l, const vec2& r){
  return { l.x - r.x, l.y - r.y };
}
vec2 operator*(const vec2& l, const vec2& r){
  return { l.x * r.x, l.y * r.y };
}
vec2 operator*(const vec2& l, float r){
  return { l.x * r, l.y * r };
}
bool operator==(const vec2& l, const vec2& r){
  return CMP(l.x, r.x) && CMP(l.y, r.y);
}
bool operator!=(const vec2& l, const vec2& r){
  return !(l==r);
}
float Dot(const vec2& l, const vec2& r){
  return l.x * r.x + l.y * r.y;
}
//Length of one vector
float Magnitude(const vec2 &v){
  return sqrt(Dot(v,v));
}
//Length between two vectors
float Magnitude(const vec2 &l, const vec2 &r) {
  float x = l.x - r.x;
  float y = l.y - r.y;
  return sqrt(x*x + y*y);
}
float MagnitudeSq(const vec2& v){
  return Dot(v,v);
}
void Normalize(vec2& v){
  v = v * (1.0f/Magnitude(v));
}
vec2 Normalized(const vec2& v)
{
  return v * (1.0f/(Magnitude(v)));
}
float Angle(const vec2& l, const vec2& r){
  float m = sqrtf(MagnitudeSq(l) * MagnitudeSq(r));
  return acos(Dot(l,r) / m);
}
vec2 Project(const vec2& len, const vec2& dir){
  float dot = Dot(len, dir);
  float magSq = MagnitudeSq(dir);
  return dir * (dot / magSq);
}
vec2 Perpendicular(const vec2& len, const vec2& dir){
 return len - Project(len, dir);
}
vec2 Reflection(const vec2& sourceVector, const vec2& normal){
  float d = Dot(sourceVector,normal);
  return sourceVector - normal * (d * 2.0f);
}
std::ostream& operator<<(std::ostream& out, const vec2& v){
  return out << "("<< v.x << ", " << v.y << ")";
}


vec3 operator+(const vec3& l, const vec3& r){
  return { l.x + r.x, l.y + r.y, l.z + r.z };
}
vec3 operator-(const vec3& l, const vec3& r){
  return { l.x - r.x, l.y - r.y, l.z - r.z };
}
vec3 operator*(const vec3& l, const vec3& r){
  return { l.x * r.x, l.y * r.y, l.z * r.z };
}
vec3 operator*(const vec3& l, float r){
  return { l.x * r, l.y * r, l.z * r };
}
bool operator==(const vec3& l, const vec3& r){
  return CMP(l.x, r.x) && CMP(l.y, r.y) && CMP(l.z, r.z);
}
bool operator!=(const vec3& l, const vec3& r){
  return !(l==r);
}
float Dot(const vec3& l, const vec3& r){
  return l.x * r.x + l.y * r.y + l.z * r.z;
}
//Length of one vector
float Magnitude(const vec3 &v){
  return sqrt(Dot(v,v));
}
//Length between two vectors
float Magnitude(const vec3 &l, const vec3 &r) {
  float x = l.x - r.x;
  float y = l.y - r.y;
  float z = l.z - r.z;
  return sqrt(x*x + y*y + z*z);
}
float MagnitudeSq(const vec3& v){
  return Dot(v,v);
}
void Normalize(vec3& v)
{
  v = v * (1.0f/Magnitude(v));
}
vec3 Normalized(const vec3& v){
  return v * (1.0f/Magnitude(v));
}
vec3 Cross(const vec3& l, const vec3& r)
{
  vec3 result;
  result.x = l.y * r.z - l.z * r.y;
  result.y = l.z * r.x - l.x * r.z;
  result.z = l.x * r.y - l.y * r.x;
  return result;
}
float Angle(const vec3& l, const vec3& r){
  float m = sqrtf(MagnitudeSq(l) * MagnitudeSq(r));
  return acos(Dot(l,r)/m);
}
vec3 Project(const vec3& len, const vec3& dir){
  float dot = Dot(len, dir);
  float magSq = MagnitudeSq(dir);
  return dir * (dot / magSq);
}
vec3 Perpendicular(const vec3& len, const vec3& dir){
 return len - Project(len, dir);
}
vec3 Reflection(const vec3& sourceVector, const vec3& normal){
  float d = Dot(sourceVector,normal);
  return sourceVector - normal * (d * 2.0f);
}
std::ostream& operator<<(std::ostream& out, const vec3& v){
  return out << "("<< v.x << ", " << v.y << ", " << v.z << ")";
}
