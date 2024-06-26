#include "vector2.h"
#include "complexnums.h"

Complex GetComplexFromVector(Vector2 a)
{
  return (Complex)
  {
    .Re = a.X,
    .Im = a.Y
  };
};
  
Vector2 GetVectorFromComplex(Complex a)
{
  return (Vector2)
  {
    .X = a.Re,
    .Y = a.Im
  };
};