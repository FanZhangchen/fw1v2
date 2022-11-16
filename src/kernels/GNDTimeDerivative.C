#include "GNDTimeDerivative.h"

registerMooseObject("fw1v2App", GNDTimeDerivative);

InputParameters
GNDTimeDerivative::validParams()
{
  InputParameters params = TimeDerivative::validParams();
  params.addClassDescription("The time derivative operator with the weak form of $(\\psi_i, "
                             "\\frac{\\partial rhog}{\\partial t})$.");
  return params;
}

GNDTimeDerivative::GNDTimeDerivative(const InputParameters & parameters)
  : TimeDerivative(parameters)
{
}

Real
GNDTimeDerivative::computeQpResidual()
{
  return _test[_i][_qp] * _u_dot[_qp];
}

Real
GNDTimeDerivative::computeQpJacobian()
{
  return _test[_i][_qp] * _phi[_j][_qp] * _du_dot_du[_qp];
}