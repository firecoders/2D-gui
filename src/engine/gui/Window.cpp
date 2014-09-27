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

#include "engine/gui/Window.h"

using namespace engine::gui;

Window::Window
(
    std::shared_ptr < sf::RenderWindow > render_window,
    std::shared_ptr < events::Receiver < std::shared_ptr< Draw_event > > > draw_event_converter,
    std::shared_ptr < events::Receiver < std::shared_ptr< sf::Event > > > sfml_event_converter
) :
    wrapped_window ( render_window ),
    draw_event_converter( draw_event_converter ),
    sfml_event_converter( sfml_event_converter )
{
}

void Window::loop (int preferred_fps)
{
    std::chrono::steady_clock::time_point begin_of_frame;
    std::chrono::steady_clock::duration high_res_second = std::chrono::seconds ( 1 );
    std::chrono::steady_clock::duration time_each_frame = high_res_second / preferred_fps;
    while ( wrapped_window->isOpen () )
    {
        begin_of_frame = std::chrono::steady_clock::now ();

        std::shared_ptr< sf::Event > event = std::make_shared < sf::Event > ();
        while ( wrapped_window->pollEvent ( *event ) )
        {
            if ( event->type == sf::Event::Closed )
            {
                wrapped_window->close ();
            }
            else
            {
                sfml_event_converter->receive ( event );
            }
        }

        wrapped_window->clear ( sf::Color::Black );
        std::shared_ptr< Draw_event > draw_event = std::make_shared< Draw_event > ( wrapped_window.get() );
        draw_event_converter->receive ( draw_event );
        wrapped_window->display ();

        std::this_thread::sleep_until ( begin_of_frame + time_each_frame );
    }
}
