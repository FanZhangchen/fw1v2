#pragma once

#include "Kernel.h"

class GNDDenFlux : public Kernel
{
public:
  static InputParameters validParams();

  GNDDenFlux(const InputParameters & parameters);

protected:

  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  const MaterialProperty<Real> & _backstress;

  const MaterialProperty<Real> & _rhos;

  const MaterialProperty<Real> & _sgn;
};
