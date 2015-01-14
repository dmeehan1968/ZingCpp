//
//  Options.h
//  DelegateTest
//
//  Created by Dave Meehan on 09/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef __DelegateTest__Options__
#define __DelegateTest__Options__

#include "Option.h"

#include <memory>
#include <vector>

namespace Zing {

    class Options {

    public:

        void add(std::shared_ptr<Option> const &option);

        template <typename InputIterator>
        void parse(InputIterator begin, InputIterator end) {

            while (begin != end) {

                auto found = std::find_if(_options.begin(), _options.end(), [&](std::shared_ptr<Option> const &option) {

                    auto result = option->accepts(begin, end);

                    if (result.accepted) {

                        (*option)(*result.args);

                        begin = result.next;

                        return true;

                    }

                    return false;

                });

                if (found == _options.end()) {

                    throw std::runtime_error("unrecognised option: " + *begin);
                    
                }
                
            }
            
        }
        
    private:
        
        std::vector<std::shared_ptr<Option>> _options;
        
    };

}

#endif /* defined(__DelegateTest__Options__) */
