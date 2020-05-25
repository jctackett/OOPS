#ifndef WAVE_PARSER_H
#define WAVE_PARSER_H

#include <paramparser.h>
#include <waveparameters.h>

// DO NOT MODIFY - This file is automatically generated during compilation.

class WaveParser : ParamParser{
  public:
    WaveParser() : ParamParser(1){}

    virtual ~WaveParser(){}

    virtual void updateParameters(std::string fname, Parameters* params);
};

#endif
