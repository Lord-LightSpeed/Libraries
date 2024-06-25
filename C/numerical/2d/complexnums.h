#include <math.h>

typedef struct 
{
  float Re;
  float Im;
} Complex;

const Complex ComplexAdd(Complex a, Complex b)
{
  return (Complex)
  {
  .Re = a.Re + b.Re,
  .Im = a.Im + b.Im
  };
};

const Complex ComplexSubtract(Complex a, Complex b)
{
  return (Complex)
  {
  .Re = a.Re - b.Re,
  .Im = a.Im - b.Im
  };
};

const Complex ComplexMultiply(Complex a, Complex b)
{
  return (Complex)
  {
  .Re = (a.Re * b.Re) - (a.Im * b.Im),
  .Im = (a.Im * b.Re) + (a.Re * b.Im)
  };
};

const Complex ComplexConjugate(Complex a)
{
  return (Complex)
  {
    .Re = a.Re,
    .Im = - a.Im
  };
};

const float ComplexConjugateMultiply(Complex a)
{
  return ((a.Re * a.Re) + (a.Im * a.Im));
};

const Complex ComplexDivideByFloat(Complex a, float b)
{
  return (Complex)
  {
    .Re = a.Re / b,
    .Im = a.Im / b
  };
};

const Complex ComplexMultiplyByFloat(Complex a, float b)
{
  return (Complex)
  {
    .Re = a.Re * b,
    .Im = a.Im * b
  };
};

const float GetModulous(Complex a)
{
  return sqrtf( (a.Re + a.Re) + (a.Im * a.Im) );
};

const float GetArgument(Complex a)
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

const Complex ComplexDivide(Complex a, Complex b)
{
  return ComplexDivideByFloat( ( ComplexMultiply( a , ComplexConjugate( b ) ) ) , ComplexConjugateMultiply( b ) );
};