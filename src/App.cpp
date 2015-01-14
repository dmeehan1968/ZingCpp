//
//  App.cpp
//  DelegateTest
//
//  Created by Dave Meehan on 09/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#include "App.h"

#include <memory>

namespace Zing {

    App::App(std::shared_ptr<Runnable> const &runnable,
             std::shared_ptr<Options> const &options)
    :
        _runnable(runnable),
        _options(options)
    {}

}