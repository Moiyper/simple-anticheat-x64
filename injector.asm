global DllMain
extern Injection
DllMain:
	cmp rdx, 1
	jne .exit
	times 16 nop
	sub rsp, 40
	call Injection
	add rsp, 40
.exit:
	mov eax, 1
	ret