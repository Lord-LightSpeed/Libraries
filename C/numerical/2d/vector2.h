#include <math.h>

typedef struct 
{
  float X;
  float Y;
} Vector2;

Vector2 Vec2Add(Vector2 a, Vector2 b)
{
  return (Vector2)
  {
  .X = a.X + b.X,
  .Y = a.Y + b.Y
  };
};

Vector2 Vec2Subtract(Vector2 a, Vector2 b)
{
  return (Vector2)
  {
  .X = a.X - b.X,
  .Y = a.Y - b.Y
  };
};

Vector2 Vec2DivideByFloat(Vector2 a, float b)
{
  return (Vector2)
  {
  .X = a.X / b,
  .Y = a.Y / b
  };
};

Vector2 Vec2MultiplyByFloat(Vector2 a, float b)
{
  return (Vector2)
  {
  .X = a.X * b,
  .Y = a.Y * b
  };
};

float GetLengthVec2(Vector2 a)
{
  return sqrtf( (a.X + a.X) + (a.Y * a.Y) );
};

float GetAngleVec2(Vector2 a)
{
  float len = GetLengthVec2(a);
  float signtheta = a.Y;
  if (signtheta >= 0)
  {
    return acosf(a.X / len);
  }
  else
  {
    return ( - acosf(a.X / len));
  };
};

float Vec2DotProduct(Vector2 a, Vector2 b)
{
  return ((a.X * b.X) + (a.Y * b.Y));
};

Vector2 Vec2Normalise(Vector2 a)
{
  return Vec2MultiplyByFloat(a, Q_rsqrt(a.X * a.X + a.Y * a.Y));
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