#pragma once
// Запуск со своими правами - поиск айди - создание хендла - инджект
#include "includes.h"
class FRIEND_PROCESS {
private:
	std::wstring path;
	std::wstring path_directory;
	PROCESS_INFORMATION pi;
public:
	HANDLE SaveHandleProcess(HANDLE& h) {
		return h = pi.hProcess;
	}
	void StartProcess(std::wstring path_exe, std::wstring path_directory) {
		if (!CreateProcessW(path_exe.c_str(), NULL, NULL, NULL, true, HIGH_PRIORITY_CLASS, NULL, path_directory.c_str(), NULL, &pi)) LOG_ERROR_r("Error create process");
	}
	void SetPath_exe() {
		std::wstring path_exe;
		std::wcin >> path_exe;
		path = path_exe;
	}
	std::wstring WritePath_exe(std::wstring& saved_path) {
		return saved_path = path;
	}
	void SetPath_directory() {
		std::wstring path_d;
		std::wcin >> path_d;
		path_directory = path_d;
	}
	std::wstring WritePath(std::wstring& saved_path) {
		return saved_path = path;
	}
	DWORD WritePID(DWORD& saved_pid) {
		return saved_pid = pi.dwProcessId;
	}
	void Inject(HANDLE& h, std::wstring path) {
		try {
			LOG_r("0");
			if (!h) throw std::runtime_error("INVALID HANDLE PROCESS!");
			LOG_r("25%");
			SIZE_T path_size = (path_dll.length()) * sizeof(char);
			LPVOID remoteMemory = VirtualAllocEx(h, NULL, path_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
			LOG_r("35%");
			if (!remoteMemory) {
				VirtualFreeEx(h, remoteMemory, path_size, MEM_RELEASE);
				throw std::runtime_error("ERROR REMOTE MEMORY");
			}
			LOG_r("50%");
			if (!WriteProcessMemory(h, remoteMemory, path_dll.c_str(), path_size, NULL)) {
				throw std::runtime_error("ERROR WRITE PROCESS MEM");
				VirtualFreeEx(h, remoteMemory, path_size, MEM_RELEASE);
				CloseHandle(h);
			}
			LOG_r("75%");
			LPTHREAD_START_ROUTINE lib_add = (LPTHREAD_START_ROUTINE(GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA")));
			if (!CreateRemoteThread(h, NULL, 0, lib_add, remoteMemory, 0, NULL)) {
				throw std::runtime_error("ERROR CREATE REMOTE THREAD");
				VirtualFreeEx(h, remoteMemory, path_size, MEM_RELEASE);
				CloseHandle(h);
			}
			LOG_r("100%");
			LOG_r("=== Injection complete! ===");
			VirtualFreeEx(h, remoteMemory, 0, MEM_RELEASE);
			CloseHandle(h);
		}
		catch (std::exception& e) {
			std::cout << e.what() << "\nLast error: " << GetLastError() << std::endl;
		}
	}
};

/*struct ENEMY_PROCESS {
	void operator()(DWORD PID, std::string& name) const {
		TerminateProcess(hprocess, 0);
		CloseHandle(enemy_process);
	}
	std::string name;
	DWORD pid;
	HANDLE hprocess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
};
*/