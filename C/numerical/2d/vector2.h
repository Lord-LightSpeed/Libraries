#include <math.h>

typedef struct 
{
  float X;
  float Y;
} Vector2;

const Vector2 Vector2Add(Vector2 a, Vector2 b)
{
  return (Vector2)
  {
  .X = a.X + b.X,
  .Y = a.Y + b.Y
  };
};

const Vector2 Vector2Subtract(Vector2 a, Vector2 b)
{
  return (Vector2)
  {
  .X = a.X - b.X,
  .Y = a.Y - b.Y
  };
};

const Vector2 Vector2DivideByFloat(Vector2 a, float b)
{
  return (Vector2)
  {
  .X = a.X / b,
  .Y = a.Y / b
  };
};

const Vector2 Vector2MultiplyByFloat(Vector2 a, float b)
{
  return (Vector2)
  {
  .X = a.X * b,
  .Y = a.Y * b
  };
};

const float GetLengthVec2(Vector2 a)
{
  return sqrtf( (a.X + a.X) + (a.Y * a.Y) );
};

const float GetAngleVec2(Vector2 a)
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

const float DotProduct(Vector2 a, Vector2 b)
{
  return ((a.X * b.X) + (a.Y * b.Y));
};