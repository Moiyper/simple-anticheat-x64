// Инъекция - Моментальное срабатываение .dll -- хук
#include "includes.h"
FRIEND_PROCESS friend_process;
//ENEMY_PROCESS enemy_process;
int main() {
	LOG_r("Press 'CTRL + F12 + X' for optimization exit.");
	while (!(GetAsyncKeyState(VK_CONTROL & VK_F12 & 'X') & 0x8000)) {
		LOG_r("Path .exe: ");
		friend_process.SetPath_exe();
		std::wstring path = friend_process.WritePath_exe(path);
		friend_process.SetPath_directory();
		std::wstring path_directory = friend_process.WritePath(path_directory);
		friend_process.StartProcess(path, path_directory);
		HANDLE f_h = friend_process.SaveHandleProcess(f_h);
		friend_process.Inject(f_h, path);
	}
}