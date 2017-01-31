# Chip8
## Version 0.1.2

![](https://travis-ci.org/stykr/chip8.svg)

## Introduction

Chip8 is a simple CHIP-8 emulator written in C.

This is currently a WIP. Please check back later for updates.

## Installation & Requirements

Requires SDL.

To build on linux run `make`.

## Usage

chip8 [-hv] [file]

## Controls

The keyboard on a CHIP-8 looks resembles the following table:

	+---+---+---+---+
	| 1 | 2 | 3 | c |
	+---+---+---+---+
	| 4 | 5 | 6 | d |
	+---+---+---+---+
	| 7 | 8 | 9 | e |
	+---+---+---+---+
	| a | 0 | b | f |
	+---+---+---+---+

In this emulator the controls match up as seen below:

	+---+---+---+---+
	| 1 | 2 | 3 | 4 |
	+---+---+---+---+
	| q | w | e | r |
	+---+---+---+---+
	| a | s | d | f |
	+---+---+---+---+
	| z | x | c | v |
	+---+---+---+---+

## What is a "CHIP-8"?

Check out this wikipedia [article](http://en.wikipedia.org/wiki/CHIP-8) for more
information. Here is the introduction on wikipedia:

> CHIP-8 is an interpreted programming language, developed by Joseph Weisbecker.
> It was initially used on the COSMAC VIP and Telmac 1800 8-bit microcomputers in
> the mid-1970s. CHIP-8 programs are run on a CHIP-8 virtual machine. It was made
> to allow video games to be more easily programmed for said computers.

## Games

David Winter has written several games for the CHIP-8 which can be found
[here](http://www.pong-story.com/chip8/).

## More Info

See the Changelog and TODO list for more information.

## Copyright & License

The MIT License (MIT)

Copyright (c) 2013 Rohan Rao

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
