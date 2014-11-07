/* 2D-gui, A C++ gui library wrapping sfml and using our eventsystem project
   Copyright (C) 2014 firecoders

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
   DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
   OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef ENGINE_CONVERTERS_DICT_GUARD
#define ENGINE_CONVERTERS_DICT_GUARD

#include <map>
#include <stdexcept>

#include "engine/types/Dict.hpp"

namespace sf
{
    class RenderTarget;
} /* namespace sf */

namespace engine
{
    namespace types
    {
        template <>
        struct Type_description < sf::RenderTarget* >
        {
            static constexpr const char* type_string = "sf::RenderTarget*";
            static bool operator_equals ( const Dynamic_union& lhs, const Dynamic_union& rhs )
            {
                return lhs.get < sf::RenderTarget* > () == rhs.get < sf::RenderTarget* > ();
            }
            static bool operator_less ( const Dynamic_union& lhs, const Dynamic_union& rhs )
            {
                return lhs.get < sf::RenderTarget* > () < rhs.get < sf::RenderTarget* > ();
            }
        };

        template <>
        struct Type_description < unsigned int >
        {
            static constexpr const char* type_string = "unsigned int";
            static bool operator_equals ( const Dynamic_union& lhs, const Dynamic_union& rhs )
            {
                return lhs.get < unsigned int > () == rhs.get < unsigned int > ();
            }
            static bool operator_less ( const Dynamic_union& lhs, const Dynamic_union& rhs )
            {
                return lhs.get < unsigned int > () < rhs.get < unsigned int > ();
            }
        };
    } /* namespace types */
} /* namespace engine */

#endif // ENGINE_CONVERTERS_DICT_GUARD
