global	ft_read
extern	__errno_location

ft_read:
	mov		rax,	0						; set read syscall
	syscall									; syscall read
	test	rax,	rax						;
	js		.error							; if ret < 0 jmp to .error func
	ret										;

.error:
	mov		r8,		rax
	neg		r8								; get absolute err value and save it in r8
	call	__errno_location wrt ..plt		; call errno
	mov		[rax],	r8						; set errno value
	mov		rax,	-1						;
	ret										; return -1
