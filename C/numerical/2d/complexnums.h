#include <math.h>

typedef struct 
{
  float Re;
  float Im;
} Complex;

const Complex ComplexAdd(Complex a, Complex b)
{
  Complex result;
  result.Re = a.Re + b.Re;
  result.Im = a.Im + b.Im;
  return result;
};

const Complex ComplexSubtract(Complex a, Complex b)
{
  Complex result;
  result.Re = a.Re - b.Re;
  result.Im = a.Im - b.Im;
  return result;
};

const Complex ComplexMultiply(Complex a, Complex b)
{
  Complex result;
  result.Re = (a.Re * b.Re) - (a.Im * b.Im);
  result.Im = (a.Im * b.Re) + (a.Re * b.Im);
  return result;
};

const Complex ComplexConjugate(Complex a)
{
  Complex result;
  result.Re = a.Re;
  result.Im = - a.Im;
  return result;
};

const float ComplexConjugateMultiply(Complex a)
{
  return ((a.Re * a.Re) + (a.Im * a.Im));
};

const Complex ComplexDivideByFloat(Complex a, float b)
{
  Complex result;
  result.Re = a.Re / b;
  result.Im = a.Im / b;
  return result;
};

const Complex ComplexMultiplyByFloat(Complex a, float b)
{
  Complex result;
  result.Re = a.Re * b;
  result.Im = a.Im * b;
  return result;
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

#ifdef PolarCoordinate

  const PolarCoordinate GetPolarFromComplex(Complex a)
  {
    PolarCoordinate result;
    result.Length = GetModulous(a);
    result.Angle = GetArgument(a);
    return result;
  };

  const Complex GetComplexFromPolar(PolarCoordinate a)
  {
    Complex result;
    result.Re = a.Length * cosf(a.Angle);
    result.Im = a.Length * sinf(a.Angle);
    return result;
  };

#endif

#ifdef Vector2

  const Vector2 GetVectorFromComplex(Complex a)
  {
    Vector2 result;
    result.X = a.Re;
    result.Y = a.Im;
    return result;
  };

  const Complex GetComplexFromVector(Vector2 a)
  {
    Complex result;
    result.Re = a.X;
    result.Im = a.Y;
    return result;
  };

#endif