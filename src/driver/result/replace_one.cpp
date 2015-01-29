// Copyright 2014 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "driver/result/replace_one.hpp"

namespace mongo {
namespace driver {
namespace result {

replace_one::replace_one(result::bulk_write result) : _result(std::move(result)) {
}

const result::bulk_write& replace_one::result() const {
    return _result;
}

std::int64_t replace_one::matched_count() const {
    return _result.matched_count();
}

std::int64_t replace_one::modified_count() const {
    return _result.modified_count();
}

optional<bson::document::element> replace_one::upserted_id() const {
    return _result.upserted_ids();
}

}  // namespace result
}  // namespace driver
}  // namespace mongo

#include "driver/config/postlude.hpp"