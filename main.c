#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

static const char *MUSIC_PATH = "test.flac";

int main(int argc, char **argv) {
    int initted = 0;
    int flags = MIX_INIT_MP3|MIX_INIT_FLAC;

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Failed to init SDL\n");
        exit(1);
    }

	initted=Mix_Init(flags);
    if (flags != (initted & flags)) {
        printf("Could not initialize mixer (initted: %d).\n", initted);
        printf("Mix_Init: %s\n", Mix_GetError());
        exit(1);
    }

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_S16SYS, MIX_DEFAULT_CHANNELS, 640) < 0){
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
		exit(2);
    }
    Mix_Music *music = Mix_LoadMUS(MUSIC_PATH);
    if(!music){
      printf("Not found music\n");
      exit(3);
    }

    Mix_PlayMusic(music, 1);

    while (!SDL_QuitRequested()) {
        SDL_Delay(250);
    }

    Mix_FreeMusic(music);
    music = NULL;
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}
