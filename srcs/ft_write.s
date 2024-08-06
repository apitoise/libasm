global	ft_write
extern	__errno_location

ft_write:
	mov		rax,	1			; set write syscall
	syscall						; syscall write
	test	rax,	rax			;
	js		.error				; if ret < 0 jump to .error func
	ret							; else return ret

.error:
	call	__errno_location	; call errno_location
	mov		rbx,	rax			; put errno_location addr in rbx
	mov		[rbx],	rax			; put err_code in rbx to set errno var glob
	mov		rax,	-1			;
	ret							; return -1
