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

float DotProduct(Vector3 a, Vector3 b)
{
  return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
};

Vector3 Normalise(Vector3 a)
{
  float isqr;
  isqr = Q_rsqrt(a.X * a.X + a.Y * a.Y + a.Z * a.Z);
  return (Vector3)
  {
    .X = a.X * isqr,
    .Y = a.Y * isqr,
    .Z = a.Z * isqr
  };
};

float Q_rsqrt(float number)
{
  // credit to Greg Walsh
  // comments left in because I like them
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;                       // evil floating point bit level hacking
  i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
  y  = * ( float * ) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
  // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

  return y;
};