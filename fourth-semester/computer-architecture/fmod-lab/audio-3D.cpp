#include <conio.h>
#include <windows.h>
#include <fmod.hpp>
#include <fmod_errors.h>
#include <iostream>

#pragma comment(lib, "fmodex64_vc.lib")

using namespace std;

int main(int argc, TCHAR* argv[])
{
  FMOD::System* system;
  FMOD::System_Create(&system);
  system->init(16, FMOD_INIT_NORMAL, 0);
  FMOD::Sound* sound;
  FMOD::Channel* channel;
  system->createSound("audio.mp3", FMOD_SOFTWARE | FMOD_3D, 0, &sound);
  system->playSound(FMOD_CHANNEL_FREE, sound, false, &channel);

  FMOD::Reverb* reverb;
  system->createReverb(&reverb);
  FMOD_REVERB_PROPERTIES properties = FMOD_PRESET_CONCERTHALL;
  reverb->setProperties(&properties);

  FMOD_VECTOR pos = { -10.0f, 100.0f, 10.0f };
  reverb->set3DAttributes(&pos, 0.0f, 200.0f);

  //for (float i = -10.0f; i < 10.0f; i += 0.1) {
    FMOD_VECTOR listenerPos = { 0.0f, 0.0f, 0.0f };
    system->set3DListenerAttributes(0, &listenerPos, 0, new FMOD_VECTOR{ 1.0f, 0.0f, 0.0f }, new FMOD_VECTOR{ 1.0f, 0.0f, 0.0f });
    system->update();
  //  Sleep(50);
 // }

  _getch();
  return 0;
}
