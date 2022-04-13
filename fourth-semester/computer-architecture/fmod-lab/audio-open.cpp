#include <conio.h>
#include <windows.h>
#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>

#pragma comment(lib, "fmodex64_vc.lib")

int main(int argc, TCHAR* argv[])
{
  FMOD::System* system;
  FMOD::System_Create(&system);
  system->init(16, FMOD_INIT_NORMAL, 0);
  FMOD::Sound* sound;
  FMOD::Channel* channel;
  system->createSound("audio.mp3", FMOD_SOFTWARE | FMOD_LOOP_OFF, 0, &sound);
  system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);

  _getch();
  return 0;
}
