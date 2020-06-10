#include <waveparser.h>
#include <iostream>

using namespace std;

// DO NOT MODIFY - This file is automatically generated during compilation.

void WaveParser::updateParameters(string fname, Parameters* params){
  if(!checkId(params)){
    return;
  }
  reader.clearData();
  ParamReader::ParamResult result = reader.readFile(fname);
  if(result != ParamReader::SUCCESS){
    cout << "An error occurred while trying to read " << fname << ".\n";
    return;
  }
  WaveParameters *pars = (WaveParameters*) params;

  if(!reader.hasSection(string("Wave"))){
    return;
  }

  if(reader.hasParameter(string("Wave"),string("InitialConditions"))){
    string result = reader.readAsString(string("Wave"),string("InitialConditions"));
    if(result.compare("GAUSSIAN") == 0){
      pars->setInitialConditions(WaveParameters::GAUSSIAN);
    }
    else if(result.compare("SINE") == 0){
      pars->setInitialConditions(WaveParameters::SINE);
    }
    else {
      cout << "The value for parameter InitialConditions is out of range.\n";
    }
  }

  if(reader.hasParameter(string("Wave"),string("GaussianSigma"))){
    double result = reader.readAsDouble(string("Wave"),string("GaussianSigma"));
    if(result <= 1.000000e+06 && result >= 1.000000e-03){
      pars->setGaussianSigma(result);
    }
    else{
      cout << "Parameter GaussianSigma out of range.\n";
    }
  }

  if(reader.hasParameter(string("Wave"),string("GridPoints"))){
    int result = reader.readAsInt(string("Wave"),string("GridPoints"));
    if(result <= 128000 && result >= 7){
      pars->setGridPoints(result);
    }
    else{
      cout << "Parameter GridPoints out of range.\n";
    }
  }

  if(reader.hasParameter(string("Wave"),string("KOSigma"))){
    double result = reader.readAsDouble(string("Wave"),string("KOSigma"));
    if(result <= 1.000000e+00 && result >= 0.000000e+00){
      pars->setKOSigma(result);
    }
    else{
      cout << "Parameter KOSigma out of range.\n";
    }
  }

  if(reader.hasParameter(string("Wave"),string("GaussianAmplitude"))){
    double result = reader.readAsDouble(string("Wave"),string("GaussianAmplitude"));
    if(result <= 1.000000e+01 && result >= 0.000000e+00){
      pars->setGaussianAmplitude(result);
    }
    else{
      cout << "Parameter GaussianAmplitude out of range.\n";
    }
  }

  if(reader.hasParameter(string("Wave"),string("ErrorTolerance"))){
    double result = reader.readAsDouble(string("Wave"),string("ErrorTolerance"));
    if(result <= 1.000000e+00 && result >= 0.000000e+00){
      pars->setErrorTolerance(result);
    }
    else{
      cout << "Parameter ErrorTolerance out of range.\n";
    }
  }

  if(reader.hasParameter(string("Wave"),string("MinCFL"))){
    double result = reader.readAsDouble(string("Wave"),string("MinCFL"));
    if(result <= 1.000000e+00 && result >= 1.000000e-06){
      pars->setMinCFL(result);
    }
    else{
      cout << "Parameter MinCFL out of range.\n";
    }
  }

  if(reader.hasParameter(string("Wave"),string("MaxCFL"))){
    double result = reader.readAsDouble(string("Wave"),string("MaxCFL"));
    if(result <= 1.000000e+00 && result >= 1.000000e-06){
      pars->setMaxCFL(result);
    }
    else{
      cout << "Parameter MaxCFL out of range.\n";
    }
  }

}
