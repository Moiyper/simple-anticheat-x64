#pragma once
#include "includes.h"
class FRIEND_PROCESS {
private:
	HANDLE hprocess;
public:
	void GetHandleProcess(DWORD& PID) {
		HANDLE new_hprocess = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_ALL_ACCESS, false, PID);
		if (new_hprocess) hprocess = new_hprocess;
	}
	void InstallHook() {

	}
};

struct ENEMY_PROCESS {
	void operator()(DWORD PID, std::string& name) const {
		
	}
	std::string name;
	HANDLE hprocess;
};