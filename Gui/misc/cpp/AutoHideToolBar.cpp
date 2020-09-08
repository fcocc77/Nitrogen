/* ***** BEGIN LICENSE BLOCK *****
 * This file is part of Natron <https://natrongithub.github.io/>,
 * Copyright (C) 2013-2018 INRIA and Alexandre Gauthier-Foichat
 * Copyright (C) 2018-2020 The Natron developers
 *
 * Natron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Natron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
 * ***** END LICENSE BLOCK ***** */

// ***** BEGIN PYTHON BLOCK *****
// from <https://docs.python.org/3/c-api/intro.html#include-files>:
// "Since Python may define some pre-processor definitions which affect the standard headers on some systems, you must include Python.h before any standard headers are included."
#include <Python.h>
// ***** END PYTHON BLOCK *****

#include "AutoHideToolBar.h"

#include <stdexcept>

#include "Gui/main/hpp/Gui.h"

NATRON_NAMESPACE_ENTER

AutoHideToolBar::AutoHideToolBar(Gui* gui,
                                 QWidget* parent)
    : QToolBar(parent)
    , _gui(gui)
{
}

void
AutoHideToolBar::leaveEvent(QEvent* e)
{
    if ( _gui->isLeftToolBarDisplayedOnMouseHoverOnly() ) {
        _gui->setLeftToolBarVisible(false);
    }
    QToolBar::leaveEvent(e);
}

NATRON_NAMESPACE_EXIT
