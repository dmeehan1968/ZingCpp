//
//  OptionResult.h
//  DelegateTest
//
//  Created by Dave Meehan on 09/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef __DelegateTest__OptionResult__
#define __DelegateTest__OptionResult__

#include <memory>

namespace Zing { namespace App {

    class Args;

    template <typename InputIterator>
    class OptionResult {

    public:

        OptionResult() : accepted(false), next{} {}

        bool                    accepted;
        std::unique_ptr<Args>   args;
        InputIterator           next;
        
    };

} }

#endif /* defined(__DelegateTest__OptionResult__) */
