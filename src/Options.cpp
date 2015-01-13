//
//  Options.cpp
//  DelegateTest
//
//  Created by Dave Meehan on 09/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#include "Options.h"

namespace Zing { namespace App {

    void Options::add(std::shared_ptr<Option> const &option) {
        _options.push_back(option);
    }

} }