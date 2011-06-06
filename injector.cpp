// Fake X11 injection
// Author: Max Schwarz <Max@x-quadraht.de>

#include "injector.h"

#include <X11/extensions/XTest.h>

#include <stdio.h>
#include "utils.h"

Injector::Injector(Display* display)
 : m_display(display)
{
	// We need the XTest extension
	int opcode, event, error;
	if(!XQueryExtension(display, XTestExtensionName, &opcode, &event, &error))
		fatal("X server does not have XTest extension, aborting");
}

void Injector::injectMotionAbsolute(int x, int y)
{
	XWarpPointer(m_display, None, DefaultRootWindow(m_display), 0, 0, 0, 0, x, y);
}

void Injector::injectMotionRelative(int dx, int dy)
{
	XTestFakeRelativeMotionEvent(m_display, dx, dy, 0);
}

void Injector::injectButtonEvent(int button, bool press)
{
	XTestFakeButtonEvent(m_display, button, press ? True : False, 0);
}

void Injector::injectKeyEvent(int keysym, bool press)
{
	int keycode = XKeysymToKeycode(m_display, keysym);
	if(keycode != None)
		XTestFakeKeyEvent(m_display, keycode, press ? True : False, 0);
}
