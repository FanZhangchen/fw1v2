#pragma once

#include "TimeDerivative.h"

class GNDTimeDerivative : public TimeDerivative
{
public:
  static InputParameters validParams();

  GNDTimeDerivative(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;
};
