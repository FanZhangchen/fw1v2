#include "GNDDenFlux.h"

registerMooseObject("fw1v2App", GNDDenFlux);

InputParameters
GNDDenFlux::validParams()
{
  InputParameters params = Kernel::validParams();
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial rhog}{\\partial t})$.");
  return params;
}

GNDDenFlux::GNDDenFlux(const InputParameters & parameters)
  : Kernel(parameters),
    _backstress(getMaterialProperty<Real>("backstress")),
    _rhos(getMaterialProperty<Real>("rhos")),
    _sgn(getMaterialProperty<Real>("sgn"))
{
}

Real
GNDDenFlux::computeQpResidual()
{
  return -_grad_test[_i][_qp](0) * (_rhos[_qp] +std::abs(_u[_qp]))
    + _backstress[_qp] * (_grad_test[_i][_qp] * _grad_u[_qp]);
}

Real
GNDDenFlux::computeQpJacobian()
{
  return - _sgn[_qp]*_phi[_j][_qp]*_grad_test[_i][_qp](0)
    + _backstress[_qp] * (_grad_test[_i][_qp] * _grad_phi[_j][_qp]);
}