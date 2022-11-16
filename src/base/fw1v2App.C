#include "fw1v2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
fw1v2App::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

fw1v2App::fw1v2App(InputParameters parameters) : MooseApp(parameters)
{
  fw1v2App::registerAll(_factory, _action_factory, _syntax);
}

fw1v2App::~fw1v2App() {}

void
fw1v2App::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"fw1v2App"});
  Registry::registerActionsTo(af, {"fw1v2App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
fw1v2App::registerApps()
{
  registerApp(fw1v2App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
fw1v2App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  fw1v2App::registerAll(f, af, s);
}
extern "C" void
fw1v2App__registerApps()
{
  fw1v2App::registerApps();
}
