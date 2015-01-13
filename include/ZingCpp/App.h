//
//  App.h
//  DelegateTest
//
//  Created by Dave Meehan on 09/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef __DelegateTest__App__
#define __DelegateTest__App__

#include "Runnable.h"
#include "Options.h"

namespace Zing { namespace App {


    class App {

    public:

        App(std::shared_ptr<Runnable> const &runnable,
            std::shared_ptr<Options> const &options);

        template <typename InputIterator>
        int run(InputIterator begin, InputIterator end) {

            _options->parse(begin, end);

            _runnable->run();

            return 0;

        }

    private:

        std::shared_ptr<Runnable> _runnable;
        std::shared_ptr<Options> _options;
        
    };

} }

#endif /* defined(__DelegateTest__App__) */
