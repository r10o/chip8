#include <stdlib.h>

#include <SDL.h>
#include <SDL_mixer.h>

#include "sound.h"

Mix_Chunk *beep;

void init_audio()
{
	if (SDL_Init(SDL_INIT_AUDIO) == -1) {
		fprintf(stderr, "error: Could not initialize audio: %s.\n", SDL_GetError());
		exit(1);
	}
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 1, 4096) == -1) {
		fprintf(stderr, "error: Could not open audio device: %s.\n", SDL_GetError());
		exit(1);
	}

	beep = Mix_LoadWAV("ogg/beep.ogg");

	if (beep == NULL) {
		fprintf(stderr, "error: Could not load audio file: %s.\n", SDL_GetError());
		exit(1);
	}
}

void play()
{
	if (Mix_PlayChannel(-1, beep, 0) == -1) {
		fprintf(stderr, "error: Could not play audio file: %s.\n", SDL_GetError());
		Mix_HaltChannel(-1);
	}
}

void close_audio()
{
	Mix_FreeChunk(beep);
	Mix_CloseAudio();
}

