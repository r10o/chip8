# Chip-8 Emu
## A chip-8 Emulator written in C
### Version 0.1.1

## Introduction
This is my attempt at making a simple chip-8 emulator. This project is purely educational, and is freely available under the MIT License.

## Status
This is currently a work in progress. It does not work at the moment; all you will see is a black screen. Stay tuned for updates.

## How to build
To build on linux, just run `make` when you are in the src directory.
Requires SDL.

## Usage
chip8 [file]
Simple. I might implement some sort of debugger later which could complicate this later.

## Controls
Controls are simple. On an actual Chip-8 device a key board would look like this:

	| 1 | 2 | 3 | c |
	| 4 | 5 | 6 | d |
	| 7 | 8 | 9 | e |
	| a | 0 | b | f |

In this emulator they are:

	| 1 | 2 | 3 | 4 |
	| q | w | e | r |
	| a | s | d | f |
	| z | x | c | v |

## What is a "Chip-8"?
Check out this wikipedia [article](http://en.wikipedia.org/wiki/CHIP-8) for more information. Here is the introduction on wikipedia:
> CHIP-8 is an interpreted programming language, developed by Joseph Weisbecker.
> It was initially used on the COSMAC VIP and Telmac 1800 8-bit microcomputers in
> the mid-1970s. CHIP-8 programs are run on a CHIP-8 virtual machine. It was made
> to allow video games to be more easily programmed for said computers.

## Games
All the games are written by David Winter and can be found [here](http://www.pong-story.com/chip8/).

## More Info
See the changelog and todo list for more information.
