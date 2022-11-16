#pragma once

#include "Material.h"

// A helper class from MOOSE that linear interpolates x,y data
#include "DerivativeMaterialInterface.h"

/**
 * Material objects inherit from Material and override computeQpProperties.
 *
 * Their job is to declare properties for use by other objects in the
 * calculation such as Kernels and BoundaryConditions.
 */
class Bkstress : public DerivativeMaterialInterface<Material>
{
public:
  static InputParameters validParams();

  Bkstress(const InputParameters & parameters);

protected:
  /// Necessary override. This is where the values of the properties are computed.
  virtual void computeQpProperties();
  virtual void initQpStatefulProperties();

private:
  const VariableValue & _rhog;
  const VariableGradient & _grad_rhog;

  Real _initial_backstress;

  MaterialProperty<Real> & _backstress;
  const MaterialProperty<Real> & _backstress_old;
};
