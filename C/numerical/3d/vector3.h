#include <math.h>

typedef struct
{
  float X;
  float Y;
  float Z;
} Vector3;

Vector3 Vec3Cross(Vector3 a, Vector3 b)
{
  return (Vector3)
  {
    .X = a.Y * b.Z - a.Z * b.Y,
    .Y = a.X * b.Z - a.Z * b.X,
    .Z = a.X * b.Z - a.Y * b.X
  };
};