// Инъекция - Моментальное срабатываение .dll -- хук
#include "includes.h"
FRIEND_PROCESS friend_process;
ENEMY_PROCESS enemy_process;
extern "C" void Injection() {
	LOG_r("Path .exe: ");
	friend_process.SetPath_exe();
	std::string path = friend_process.WritePath_exe(path);
	LOG_r("PID process: ");
	friend_process.GetPIDProcess();
	DWORD f_pid = friend_process.WritePID(f_pid);
	friend_process.GetHandleProcess(f_pid);
	HANDLE f_h = friend_process.WriteHandle(f_h);
	friend_process.Inject(f_h, );
}
int main() {
	LOG_r("Press 'CTRL + F12 + X' for optimization exit.");
	while (!(GetAsyncKeyState(VK_CONTROL & VK_F12 & 'X') & 0x8000)) {
		std::cout << "PID process: ";
		friend_process.GetPIDProcess();
		DWORD friend_pid = friend_process.WritePID(friend_pid);
		friend_process.GetHandleProcess(friend_pid);
	}
}