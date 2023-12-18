#include <iostream>
#include "vectors.h"
#include "matrices.h"
#include <cmath>

int main(){
  mat2 m1(
          2.0f, 1.0f, 
          1.0f, 1.0f
          );

  mat3 m2(
            1.0f, 1.0f, 1.0f, 
            1.0f, 1.0f, 1.0f, 
            1.0f, 1.0f, 1.0f
          );
  m2 = m2 * 5;

  mat4 m3(
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f
          );

  mat3 m4(
            1.0f, 8.0f, 7.0f, 
            3.0f, 9.0f, 5.0f, 
            1.0f, 0.0f, 4.0f
          );
  std::cout << Minor(m4) << std::endl;
  return 0;
}
