#include <math.h>

typedef struct 
{
  float Re;
  float Im;
} Complex;

Complex ComplexAdd(Complex a, Complex b)
{
  return (Complex)
  {
  .Re = a.Re + b.Re,
  .Im = a.Im + b.Im
  };
};

Complex ComplexSubtract(Complex a, Complex b)
{
  return (Complex)
  {
  .Re = a.Re - b.Re,
  .Im = a.Im - b.Im
  };
};

Complex ComplexMultiply(Complex a, Complex b)
{
  return (Complex)
  {
  .Re = (a.Re * b.Re) - (a.Im * b.Im),
  .Im = (a.Im * b.Re) + (a.Re * b.Im)
  };
};

Complex ComplexConjugate(Complex a)
{
  return (Complex)
  {
    .Re = a.Re,
    .Im = - a.Im
  };
};

float ComplexConjugateMultiply(Complex a)
{
  return ((a.Re * a.Re) + (a.Im * a.Im));
};

Complex ComplexDivideByFloat(Complex a, float b)
{
  return (Complex)
  {
    .Re = a.Re / b,
    .Im = a.Im / b
  };
};

Complex ComplexMultiplyByFloat(Complex a, float b)
{
  return (Complex)
  {
    .Re = a.Re * b,
    .Im = a.Im * b
  };
};

float GetModulous(Complex a)
{
  return sqrtf( (a.Re + a.Re) + (a.Im * a.Im) );
};

float GetArgument(Complex a)
{
  float len = GetModulous(a);
  float signtheta = a.Im;
  if (signtheta >= 0)
  {
    return acosf(a.Re / len);
  }
  else
  {
    return ( - acosf(a.Re / len));
  };
};

Complex ComplexDivide(Complex a, Complex b)
{
  return ComplexDivideByFloat( ( ComplexMultiply( a , ComplexConjugate( b ) ) ) , ComplexConjugateMultiply( b ) );
};