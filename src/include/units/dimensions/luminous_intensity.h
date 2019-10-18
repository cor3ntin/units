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
#include <units/quantity.h>

namespace units {

  struct luminous_intensity : derived_dimension<luminous_intensity, exp<base_dim_luminous_intensity, 1>> {};

  template<typename T>
  concept LuminousIntensity = QuantityOf<T, luminous_intensity>;

  struct candela : coherent_derived_unit<candela, "cd", luminous_intensity, si_prefix> {};

  inline namespace literals {

    // cd
    constexpr auto operator""cd(unsigned long long l) { return quantity<candela, std::int64_t>(l); }
    constexpr auto operator""cd(long double l) { return quantity<candela, long double>(l); }

  }  // namespace literals

}  // namespace units
