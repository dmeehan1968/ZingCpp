//
//  Args.cpp
//  DelegateTest
//
//  Created by Dave Meehan on 09/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#include "Args.h"

namespace Zing { namespace App {

    std::string const &Args::front() {

        return _args.front();

    }

    void Args::pop_front() {

        _args.pop_front();

    }

    void Args::push_back(std::string const &string) {

        _args.push_back(string);

    }

    bool Args::empty() const {

        return _args.empty();

    }

} }
