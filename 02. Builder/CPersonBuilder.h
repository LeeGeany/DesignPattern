#pragma once

#include "CPersonBuilderBase.h"
#include "CPerson.h"

class CPersonBuilder : public CPersonBuilderBase
{
public:
    CPersonBuilder(CPerson& p)
    : CPersonBuilderBase{ p } {}
};