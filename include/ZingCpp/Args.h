//
//  Args.h
//  DelegateTest
//
//  Created by Dave Meehan on 09/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef __DelegateTest__Args__
#define __DelegateTest__Args__

#include <string>
#include <list>

namespace Zing { namespace App {

    class Args {

    public:

        std::string const &front();

        void pop_front();

        void push_back(std::string const &string);

        bool empty() const;

        friend Args &operator >> (Args &args, std::string &string) {

            string = args.front();
            args.pop_front();
            return args;
            
        }
        

    private:

        std::list<std::string> _args;
        
    };

} }
#endif /* defined(__DelegateTest__Args__) */
