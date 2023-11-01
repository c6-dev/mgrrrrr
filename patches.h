#pragma once
#include "D3D9Types.h"
UInt32 base = NULL;
UInt32 retnAddr = NULL;
UInt32 pD3DAddr = NULL;

__declspec(naked) void forceRefreshRate() {
	__asm {
		mov dword ptr[eax+0x30], 0x3C
		mov edx, pD3DAddr
		mov edx, dword ptr[edx]
		mov esi, dword ptr[edx]
		jmp retnAddr
	}
}


void writePatches() {
	base = (UInt32)GetModuleHandle(NULL);
	UInt32 addr = 0xB9BA44 + base;
	retnAddr = 0xB9BA4C + base;
	pD3DAddr = 0x1B206D8 + base;
	WriteRelJump(addr, (UInt32)forceRefreshRate);

}