unity
=====

Unity works similar to [synergy](http://www.synergy-foss.org):
It lets you share input devices across multiple computers
connected via network. The difference is, that it works
in both ways: The connected computer share *one* 
pointer & keyboard focus, you can use whatever input device
you want to move it around and type.

Status
------

Much to be done:

- main.cpp is a mess
- The protocol uses the X11 keycodes, I do not know if they
  are portable
- User-configurable filters that decide which key presses to
  forward and which ones to give to the own host
- Configuration file
- More documentation
