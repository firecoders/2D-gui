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

#ifndef ENGINE_GUI_WINDOW_GUARD
#define ENGINE_GUI_WINDOW_GUARD

#include <SFML/Graphics.hpp>

#include <memory>
#include <chrono>
#include <thread>

#include "engine/events/interfaces/Receiver.h"

#include "Draw_event.h"

namespace engine
{
    namespace gui
    {
        class Window
        {
            public:
                Window
                (
                    std::shared_ptr < sf::RenderWindow >,
                    std::shared_ptr < events::Receiver < std::shared_ptr < Draw_event > > > draw_event_converter,
                    std::shared_ptr < events::Receiver < std::shared_ptr < sf::Event > > > sfml_event_converter
                );

                void loop ( int preferred_fps );

            private:
                std::shared_ptr < sf::RenderWindow > wrapped_window;
                std::shared_ptr < events::Receiver < std::shared_ptr < Draw_event > > > draw_event_converter;
                std::shared_ptr < events::Receiver < std::shared_ptr < sf::Event > > > sfml_event_converter;
        };
    } /* namespace gui */
} /* namespace engine */

#endif // ENGINE_GUI_WINDOW_GUARD
