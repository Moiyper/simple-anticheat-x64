#pragma once
#include "includes.h"
class FRIEND_PROCESS {
private:
	DWORD pid;
	HANDLE hprocess;
public:
	void GetPIDProcess() {
		DWORD new_pid;
		std::cin >> new_pid;
		pid = new_pid;
	}
	DWORD WritePID(DWORD& saved_pid) {
		return saved_pid = pid;
	}
	void GetHandleProcess(DWORD& PID) {
		HANDLE new_hprocess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION |PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_ALL_ACCESS, false, PID);
		if (new_hprocess) hprocess = new_hprocess;
	}
	HANDLE WriteHandle(HANDLE& saved_h) {
		return saved_h = hprocess;
	}
	void Inject(HANDLE& h, DWORD& pid) {
		try {
			if (!h) throw std::runtime_error("INVALID HANDLE PROCESS!");

		}
		catch (std::exception& e) {
			std::cout << e.what() << "\nLast error: " << GetLastError() << std::endl;
		}
	}
	void InstallHook() {

	}
};

struct ENEMY_PROCESS {
	void operator()(DWORD PID, std::string& name) const {
		
	}
	std::string name;
	DWORD pid;
	HANDLE hprocess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
};