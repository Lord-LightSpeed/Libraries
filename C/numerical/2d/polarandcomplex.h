#include "polarcoordinates.h"
#include "complexnums.h"

PolarCoordinate GetPolarFromComplex(Complex a)
{
  return (PolarCoordinate)
  {
    .Angle = GetArgument(a),
    .Length = GetModulous(a)
  };
};

Complex GetComplexFromPolar(PolarCoordinate a)
{
  return (Complex)
  {
    .Re = a.Length * cosf(a.Angle),
    .Im = a.Length * sinf(a.Angle)
  };
};