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

#include "catch.hpp"
#include "helpers.hpp"

#include <bsoncxx/builder.hpp>
#include <mongocxx/result/replace_one.hpp>



TEST_CASE("replace_one", "[replace_one][result]") {
    bsoncxx::builder::document build;
    build << "_id" << bsoncxx::oid{bsoncxx::oid::init_tag} << "nMatched" << bsoncxx::types::b_int64{2}
          << "nModified" << bsoncxx::types::b_int64{1};

    mongocxx::result::bulk_write b(bsoncxx::document::value(build.view()));

    mongocxx::result::replace_one replace_one(std::move(b));

    SECTION("returns correct matched and modified count") {
        REQUIRE(replace_one.matched_count() == 2);
        REQUIRE(replace_one.modified_count() == 1);
    }
}