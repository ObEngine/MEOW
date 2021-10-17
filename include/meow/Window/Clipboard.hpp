////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2021 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the
// use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_CLIPBOARD_HPP
#define SFML_CLIPBOARD_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <meow/System/String.hpp>
#include <meow/Window/Export.hpp>

namespace meow {
////////////////////////////////////////////////////////////
/// \brief Give access to the system clipboard
///
////////////////////////////////////////////////////////////
class Clipboard {
public:
  ////////////////////////////////////////////////////////////
  /// \brief Get the content of the clipboard as string data
  ///
  /// This function returns the content of the clipboard
  /// as a string. If the clipboard does not contain string
  /// it returns an empty meow::String object.
  ///
  /// \return Clipboard contents as meow::String object
  ///
  ////////////////////////////////////////////////////////////
  static String getString();

  ////////////////////////////////////////////////////////////
  /// \brief Set the content of the clipboard as string data
  ///
  /// This function sets the content of the clipboard as a
  /// string.
  ///
  /// \warning Due to limitations on some operating systems,
  ///          setting the clipboard contents is only
  ///          guaranteed to work if there is currently an
  ///          open window for which events are being handled.
  ///
  /// \param text meow::String containing the data to be sent
  /// to the clipboard
  ///
  ////////////////////////////////////////////////////////////
  static void setString(const String &text);
};

} // namespace meow

#endif // SFML_CLIPBOARD_HPP

////////////////////////////////////////////////////////////
/// \class meow::Clipboard
/// \ingroup window
///
/// meow::Clipboard provides an interface for getting and
/// setting the contents of the system clipboard.
///
/// It is important to note that due to limitations on some
/// operating systems, setting the clipboard contents is
/// only guaranteed to work if there is currently an open
/// window for which events are being handled.
///
/// Usage example:
/// \code
/// // get the clipboard content as a string
/// meow::String string = meow::Clipboard::getString();
///
/// // or use it in the event loop
/// meow::Event event;
/// while(window.pollEvent(event))
/// {
///     if(event.type == meow::Event::Closed)
///         window.close();
///     if(event.type == meow::Event::KeyPressed)
///     {
///         // Using Ctrl + V to paste a string into SFML
///         if(event.key.control && event.key.code == meow::Keyboard::V)
///             string = meow::Clipboard::getString();
///
///         // Using Ctrl + C to copy a string out of SFML
///         if(event.key.control && event.key.code == meow::Keyboard::C)
///             meow::Clipboard::setString("Hello World!");
///     }
/// }
/// \endcode
///
/// \see meow::String, meow::Event
///
////////////////////////////////////////////////////////////
