/*
 * Copyright (c) 2017 Spotify AB
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#pragma once

#include <cstdint>
#include <type_traits>

#include <spotify/json/detail/macros.hpp>
#include <spotify/json/type.hpp>
#include <spotify/json/value_exception.hpp>
#include <spotify/json/value/value.hpp>

namespace spotify {
namespace json {

struct boolean : public value {
 public:
  boolean();
  boolean(bool b);

  explicit operator bool() const;
};

inline boolean::boolean() : boolean(false) {}

inline boolean::boolean(bool b) : value(b ?
    detail::value_union::value_true :
    detail::value_union::value_false) {}

boolean::operator bool() const {
  return _.as_value.type == detail::value_union::value_true;
}

}  // namespace json
}  // namespace spotify
