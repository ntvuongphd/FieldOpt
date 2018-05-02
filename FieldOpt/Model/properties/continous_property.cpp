/***********************************************************
 Copyright (C) 2015-2017
 Einar J.M. Baumann <einar.baumann@gmail.com>

 Created: 23.09.2015 2015 by einar

 This file is part of the FieldOpt project.

 FieldOpt is free software: you can redistribute it
 and/or modify it under the terms of the GNU General
 Public License as published by the Free Software
 Foundation, either version 3 of the License, or (at
 your option) any later version.

 FieldOpt is distributed in the hope that it will be
 useful, but WITHOUT ANY WARRANTY; without even the
 implied warranty of MERCHANTABILITY or FITNESS FOR
 A PARTICULAR PURPOSE.  See the GNU General Public
 License for more details.

 You should have received a copy of the GNU
 General Public License along with FieldOpt.
 If not, see <http://www.gnu.org/licenses/>.
***********************************************************/

// ---------------------------------------------------------
#include "continous_property.h"
#include <cmath>

// ---------------------------------------------------------
namespace Model {
namespace Properties {

// =========================================================
ContinousProperty::ContinousProperty(double value)
    : Property(Continous) {
    value_ = value;
}

// =========================================================
void ContinousProperty::setValue(double value) {
    if (IsLocked()) throw PropertyLockedException(
          "Cant change locked real variable.");
    else value_ = value;
}

// =========================================================
void ContinousProperty::Add(double d) {
    if (IsLocked()) throw PropertyLockedException(
          "Cant add to locked real variable");
    else value_ += d;
}

// =========================================================
bool ContinousProperty::
Equals(const ContinousProperty *other, double epsilon) const {
    return std::abs(this->value() - other->value()) <= epsilon;
}

// =========================================================
QString ContinousProperty::ToString() const {
    return QString(
        "Type:\tContinous\nUUID:\t%1\nName:\t%2\nValue:\t%3\n")
        .arg(id().toString()).arg(name()).arg(value());
}



}
}
