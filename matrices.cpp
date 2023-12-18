#include "matrices.h"
#include <cmath>
#include <cfloat>

#define CMP(x,y)                          \
  (fabsf((x)-(y)) <= FLT_EPSILON *        \
    fmaxf(1.0f,                           \
    fmaxf(fabsf(x), fabsf(y)))            \
  )

void Transpose(const float *srcMat, float *dstMat, int srcRows, int srcCols){
  for (int i = 0; i < srcRows * srcCols; i++){
    int row = i / srcRows;
    int col = i % srcRows;
    dstMat[i] = srcMat[srcCols * col + row];
  }
}

bool Multiply(float* out, const float *matA, int aRows, int aCols, const float *matB, int bRows, int bCols){
  if (aCols != bRows){
    return false;
  }
  for (int i = 0; i < aRows; ++i){
    for (int j = 0; j < bCols; ++j){
      out[bCols * i + j] = 0.0f;
      for (int k = 0; k < bRows; ++k){
        int a = aCols * i + k;
        int b = bCols * k + j;
        out[bCols * i + j] += matA[a] * matB[b];
      }
    }
  }
  return true;
}

float Determinant(const mat2& matrix){
  return matrix._11 * matrix._22 - matrix._12 * matrix._21;
}

mat2 Transpose(const mat2& matrix){
  mat2 result;
  Transpose  (matrix.asArray, result.asArray, 2, 2);
  return result;
}
mat2 operator*(const mat2& matrix, float scalar){
  mat2 result;
  for (int i = 0; i < 4; ++i){
    result.asArray[i] = matrix.asArray[i] * scalar;
  }
  return result;
}
mat2 operator*(const mat2& matA, const mat2& matB){
  mat2 res;
  Multiply(res.asArray, matA.asArray, 2, 2, matB.asArray, 2, 2);
  return res;
}
mat2 Cut(const mat3& mat, int row, int col){
  mat2 result;
  int index = 0;
  for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
      if (i == row || j == col){
        continue;
      }
      int target = index++;
      int source = 3 * i + j;
      result.asArray[target] = mat.asArray[source];
    }
  }
  return result;
}
mat2 Minor(const mat2& mat){
  return mat2(
    mat._22, mat._21,
    mat._12, mat._11
  );
}
std::ostream& operator<<(std::ostream& out, const mat2& m){
  return out << m._11 << " " << m._12 << "\n"
             << m._21 << " " << m._22;
}

mat3 Transpose(const mat3& matrix){
  mat3 result;
  Transpose(matrix.asArray, result.asArray, 3, 3);
  return result;
}
mat3 operator*(const mat3& matrix, float scalar){
  mat3 result;
  for (int i = 0; i < 9; ++i){
    result.asArray[i] = matrix.asArray[i] * scalar;
  }
  return result;
}
mat3 operator*(const mat3 matA, const mat3& matB){
  mat3 res;
  Multiply(res.asArray, matA.asArray, 3, 3, matB.asArray, 3, 3);
  return res;
}
mat3 Minor(const mat3& mat){
  mat3 result;
  for (int i = 0; i < 3; ++i){
    for (int j = 0; j < 3; ++j){
      result[i][j] = Determinant(Cut(mat, i, j));
    }
  }
  return result;
}
std::ostream& operator<<(std::ostream& out, const mat3& m){
  return out << m._11 << " " << m._12 << " " << m._13 << "\n"
             << m._21 << " " << m._22 << " " << m._23 << "\n"
             << m._31 << " " << m._32 << " " <<m._33;
}
mat4 Transpose(const mat4& matrix){
  mat4 result;
  Transpose(matrix.asArray, result.asArray, 4 ,4);
  return result;
}
mat4 operator*(const mat4& matrix, float scalar){
  mat4 result;
  for (int i = 0; i < 16; ++i){
    result.asArray[i] = matrix.asArray[i] * scalar;
  }
  return result;
}
mat4 operator*(const mat4& matA, const mat4& matB){
  mat4 res;
  Multiply(res.asArray, matA.asArray, 4, 4, matB.asArray, 4, 4);
  return res;
}
std::ostream& operator<<(std::ostream& out, const mat4& m){
  return out << m._11 << " " << m._12 << " " << m._13 << " " << m._14 << "\n"
             << m._21 << " " << m._22 << " " << m._23 << " " << m._24 << "\n"
             << m._31 << " " << m._32 << " " << m._33 << " " << m._34 << "\n"
             << m._41 << " " << m._42 << " " << m._43 << " " << m._44;
}
