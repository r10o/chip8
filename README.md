# Chip8

[![Build Status](https://travis-ci.org/ror0/chip8.svg?branch=master)](https://travis-ci.org/ror0/chip8)

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
