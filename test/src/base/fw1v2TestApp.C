//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "fw1v2TestApp.h"
#include "fw1v2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
fw1v2TestApp::validParams()
{
  InputParameters params = fw1v2App::validParams();
  return params;
}

fw1v2TestApp::fw1v2TestApp(InputParameters parameters) : MooseApp(parameters)
{
  fw1v2TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

fw1v2TestApp::~fw1v2TestApp() {}

void
fw1v2TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  fw1v2App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"fw1v2TestApp"});
    Registry::registerActionsTo(af, {"fw1v2TestApp"});
  }
}

void
fw1v2TestApp::registerApps()
{
  registerApp(fw1v2App);
  registerApp(fw1v2TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
fw1v2TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fw1v2TestApp::registerAll(f, af, s);
}
extern "C" void
fw1v2TestApp__registerApps()
{
  fw1v2TestApp::registerApps();
}
