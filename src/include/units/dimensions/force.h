// The MIT License (MIT)
//
// Copyright (c) 2018 Mateusz Pusz
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <units/dimensions/si_base_dimensions.h>
#include <units/dimensions/mass.h>
#include <units/dimensions/acceleration.h>

namespace units {

  struct force : derived_dimension<force, exp<base_dim_mass, 1>, exp<acceleration, 1>> {};

  template<typename T>
  concept Force =  QuantityOf<T, force>;

  struct newton : coherent_derived_unit<newton, "N", force, si_prefix> {};

  inline namespace literals {

    // N
    constexpr auto operator""N(unsigned long long l) { return quantity<newton, std::int64_t>(l); }
    constexpr auto operator""N(long double l) { return quantity<newton, long double>(l); }

  }  // namespace literals


  namespace details {
    template<>
    inline icu::MeasureUnit* create_icu_unit<newton>(UErrorCode& uc)
    {
      return icu::MeasureUnit::createNewton(uc);
    }
  }  // namespace details

}  // namespace units
