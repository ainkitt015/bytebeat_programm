//The bytebeat code by ainkitt015
//This bit by sub, bit name: Oh the headaches | in 2011/09/28

//If this is produced in an online bytebeat composer, then the sound will be clear, because it is based in html
//On Windows it is more deaf

//include and pragme comment
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib") //vinmm

int main()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0 };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 64]; //8000 = Hz, 64 = time

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(t >> 5 | (t << 3) + 12 * t * (t >> 13 | (t >> 1 | t >> 10 | t >> 2) & t >> 8)); //bytebeat

	WAVEHDR hdr = { buffer,sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
	Sleep(-1);
}
//the end coding