#include <math.h>

typedef struct 
{
  float X;
  float Y;
} Vector2;

const Vector2 Vector2Add(Vector2 a, Vector2 b)
{
  Vector2 result;
  result.X = a.X + b.X;
  result.Y = a.Y + b.Y;
  return result;
};

const Vector2 Vector2Subtract(Vector2 a, Vector2 b)
{
  Vector2 result;
  result.X = a.X - b.X;
  result.Y = a.Y - b.Y;
  return result;
};

const Vector2 Vector2DivideByFloat(Vector2 a, float b)
{
  Vector2 result;
  result.X = a.X / b;
  result.Y = a.Y / b;
  return result;
};

const Vector2 Vector2MultiplyByFloat(Vector2 a, float b)
{
  Vector2 result;
  result.X = a.X * b;
  result.Y = a.Y * b;
  return result;
};

const float GetLength(Vector2 a)
{
  return sqrtf( (a.X + a.X) + (a.Y * a.Y) );
};

const float GetAngle(Vector2 a)
{
  float len = GetLength(a);
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

#ifdef PolarCoordinate

  const PolarCoordinate GetPolarFromVector(Vector2 a)
  {
    PolarCoordinate result;
    result.Length = GetLength(a);
    result.Angle = GetAngle(a);
    return result;
  };

  const Vector2 GetVectorFromPolar(PolarCoordinate a)
  {
    Vector2 result;
    result.X = a.Length * cosf(a.Angle);
    result.Y = a.Length * sinf(a.Angle);
    return result;
  };

#endif

#ifdef Complex

  const Complex GetComplexFromVector(Vector2 a)
  {
    Complex result;
    result.Re = a.X;
    result.Im = a.Y;
    return result;
  };
  
  const Vector2 GetVectorFromComplex(Complex a)
  {
    Vector2 result;
    result.X = a.Re;
    result.Y = a.Im;
    return result;
  };

#endif