#include "vector2.h"
#include "polarcoordinates.h"

PolarCoordinate GetPolarFromVector(Vector2 a)
{
  return (PolarCoordinate)
  {
    .Angle = GetAngleVec2(a),
    .Length = GetLengthVec2(a)
  };
};

Vector2 GetVectorFromPolar(PolarCoordinate a)
{
  return (Vector2)
  {
    .X = a.Length * cosf(a.Angle),
    .Y = a.Length * sinf(a.Angle)
  };
};