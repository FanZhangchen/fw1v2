#include "Bkstress.h"

registerMooseObject("fw1v2App", Bkstress);

InputParameters
Bkstress::validParams()
{
  InputParameters params = Material::validParams();

  // Parameter for radius of the spheres used to interpolate permeability.
  params.addClassDescription("Compute the evolution equation of SSD density without source and sink");
  params.addParam<Real>("initial_backstress", 1.0,"The initial condition of SSD density");
  params.addRequiredCoupledVar("rhog", "variable for SSD density");
  return params;
}

Bkstress::Bkstress(const InputParameters & parameters)
  : DerivativeMaterialInterface<Material>(parameters),

    // Get the parameters of the initial condition of SSD density from the input file
    _initial_backstress(getParam<Real>("initial_backstress")),

    // Get the parameters of the coupled value of GND density
    _rhog(coupledValue("rhog")),
    _grad_rhog(coupledGradient("rhog")),

    // Declare the current value and older value of SSD density
    _backstress(declareProperty<Real>("backstress")),
    _backstress_old(getMaterialPropertyOld<Real>("backstress"))
{
}

void
Bkstress::initQpStatefulProperties()
{
  _backstress[_qp] = _initial_backstress;
}

void
Bkstress::computeQpProperties()
{
  _backstress[_qp] = _backstress_old[_qp];
}
