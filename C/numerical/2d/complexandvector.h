#include "vector2.h"
#include "complexnums.h"

const Complex GetComplexFromVector(Vector2 a)
{
  return (Complex)
  {
    .Re = a.X,
    .Im = a.Y
  };
};
  
const Vector2 GetVectorFromComplex(Complex a)
{
  return (Vector2)
  {
    .X = a.Re,
    .Y = a.Im
  };
};