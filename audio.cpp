#include "audio.h"

Audio::~Audio() {
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
}

void Audio::load(const char* filename) {
    SDL_CloseAudioDevice(deviceId);
    SDL_LoadWAV(filename, &wavSpec, &wavBuffer, &wavLength);
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

void Audio::play() {
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
}

void Audio::pause() {
    SDL_PauseAudioDevice(deviceId, 1);
}

void Audio::resume() {
    SDL_PauseAudioDevice(deviceId, 0);
}


void Audio::clearAndPlay() {
    SDL_ClearQueuedAudio(deviceId);
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    SDL_PauseAudioDevice(deviceId, 0);
}
void Audio::clearAndLoop() {
    SDL_ClearQueuedAudio(deviceId);
    SDL_QueueAudio(deviceId, wavBuffer, wavLength);
    if (audioPlaying)
    {
        SDL_PauseAudioDevice(deviceId, 0);
    }
    else 
    {
        SDL_PauseAudioDevice(deviceId, 1);
    }
}

