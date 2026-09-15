// Инъекция - Моментальное срабатываение .dll -- хук
#include "includes.h"
FRIEND_PROCESS friend_process;
ENEMY_PROCESS enemy_process;
extern "C" void Injection() {
	std::cout << "PID process: ";
	friend_process.GetPIDProcess();
	DWORD f_pid = friend_process.WritePID(f_pid);
	friend_process.GetHandleProcess(f_pid);
	HANDLE f_h = friend_process.WriteHandle(f_h);
	friend_process.Inject(f_h, f_pid);
}
int main() {
	LOG_r("Press 'CTRL + ALT_LEFT + X' for optimization exit.");
	std::cout << "PID process: ";
	friend_process.GetPIDProcess();
	DWORD friend_pid = friend_process.WritePID(friend_pid);
	friend_process.GetHandleProcess(friend_pid);
}