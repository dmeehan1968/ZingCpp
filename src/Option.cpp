//
//  Option.cpp
//  DelegateTest
//
//  Created by Dave Meehan on 09/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#include "Option.h"

#include "Args.h"

namespace Zing {

    Option::Option(std::initializer_list<std::string> const &exprs, std::regex::flag_type flags)
    {
        for (auto &expr : exprs) {

            _exprs.push_back(std::regex(expr, flags));

        }

    }

}