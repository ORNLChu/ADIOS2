/*
 * Distributed under the OSI-approved Apache License, Version 2.0.  See
 * accompanying file Copyright.txt for details.
 *
 * AttributeBase.cpp
 *
 *  Created on: Aug 1, 2017
 *      Author: William F Godoy godoywf@ornl.gov
 */

#include "AttributeBase.h"

namespace adios2
{

AttributeBase::AttributeBase(const std::string &name, const std::string type,
                             const size_t elements, const bool isSingleValue)
: m_Name(name), m_Type(type), m_Elements(elements),
  m_IsSingleValue(isSingleValue)
{
}

} // end namespace adios2
