#include "SgnFunction.h"

registerMooseObject("fw1v2App", SgnFunction);

InputParameters
SgnFunction::validParams()
{
  InputParameters params = Material::validParams();

  // Parameter for radius of the spheres used to interpolate permeability.
  params.addClassDescription("Compute the evolution equation of SSD density without source and sink");
  params.addRequiredCoupledVar("rhog", "variable for SSD density");
  return params;
}

SgnFunction::SgnFunction(const InputParameters & parameters)
  : DerivativeMaterialInterface<Material>(parameters),

    // Get the parameters of the coupled value of GND density
    _rhog(coupledValue("rhog")),

    // Declare the current value and older value of SSD density
    _sgn(declareProperty<Real>("sgn"))
{
}

void
SgnFunction::computeQpProperties()
{
  _sgn[_qp] = (_rhog[_qp] > 0) ? 1 : ((_rhog[_qp] < 0) ? -1 : 0);
}
