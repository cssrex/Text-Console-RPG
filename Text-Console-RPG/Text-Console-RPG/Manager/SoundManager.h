#pragma once
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")


class SoundManager
{
private:
	SoundManager() = default;
	~SoundManager() = default;
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;

public:
	static SoundManager& GetInstance();
	
public:
	
};

