//
//  Option.h
//  DelegateTest
//
//  Created by Dave Meehan on 09/01/2015.
//  Copyright (c) 2015 Replicated Solutions Limited. All rights reserved.
//

#ifndef __DelegateTest__Option__
#define __DelegateTest__Option__

#include "OptionResult.h"
#include "Args.h"

#include <initializer_list>
#include <string>
#include <regex>
#include <list>

namespace Zing {

    class Option {

    public:

        Option(std::initializer_list<std::string> const &exprs, std::regex::flag_type flags = std::regex::ECMAScript);

        template <typename InputIterator>
        OptionResult<InputIterator> accepts(InputIterator begin, InputIterator const end) {

            OptionResult<InputIterator> result;

            for (auto &expr : _exprs) {

                if (begin == end) {
                    break;
                }

                std::smatch matches;

                if (std::regex_match(*begin, matches, expr)) {

                    if (!result.args) {
                        result.args = std::unique_ptr<Zing::Args>(new Zing::Args());
                    }

                    if (matches.size() > 1) {

                        std::for_each(matches.begin()+1, matches.end(), [&](std::string const &match) {

                            result.args->push_back(match);

                        });
                    }

                    ++begin;

                    result.next = begin;
                    result.accepted = true;

                } else {
                    result.accepted = false;
                    break;
                }

            }

            if (result.accepted == false) {
                result.args = {};
                result.next = end;
            }
            return result;
        }
        
        virtual void operator()(Args &args) = 0;
        
    private:
        
        std::list<std::regex> _exprs;
        
    };

}

#endif /* defined(__DelegateTest__Option__) */
