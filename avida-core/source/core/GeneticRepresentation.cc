/*
 *  core/GeneticRepresentation.cc
 *  avida-core
 *
 *  Created by David on 12/8/11.
 *  Copyright 2011 Michigan State University. All rights reserved.
 *  http://avida.devosoft.org/
 *
 *
 *  This file is part of Avida.
 *
 *  Avida is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 *
 *  Avida is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License along with Avida.
 *  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Authors: David M. Bryson <david@programerror.com>
 *
 */

#include "avida/core/GeneticRepresentation.h"

#include <cassert>
#include <typeinfo>


Avida::GeneticRepresentation::~GeneticRepresentation()
{
  
}

bool Avida::GeneticRepresentation::Process(GeneticRepresentationDispatchTable tbl, GeneticRepresentationPtr ptr)
{
  assert(this == GeneticRepresentationPtr::GetPointer(ptr));
  GeneticRepresentationProcessFunctor func;
  if (tbl.Get(Apto::String(typeid(GeneticRepresentation).name()), func)) {
    func(ptr);
    return true;
  }
  return false;
}

bool Avida::GeneticRepresentation::Process(ConstGeneticRepresentationDispatchTable tbl,
                                                 ConstGeneticRepresentationPtr ptr) const
{
  assert(this == ConstGeneticRepresentationPtr::GetPointer(ptr));
  ConstGeneticRepresentationProcessFunctor func;
  if (tbl.Get(Apto::String(typeid(GeneticRepresentation).name()), func)) {
    func(ptr);
    return true;
  }
  return false;
}
