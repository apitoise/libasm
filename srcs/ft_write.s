global	ft_write
extern	__errno_location

ft_write:
	mov		rax,	1						; set write syscall
	syscall									; syscall write
	test	rax,	rax						;
	js		.error							; if ret < 0 jump to .error func
	ret										; else return ret

.error:
	mov		r8,		rax
	neg		r8								; get absolute err value and save it in r8
	call	__errno_location wrt ..plt		; call errno
	mov		[rax],	r8						; set errno value
	mov		rax,	-1						;
	ret										; return -1
