global	ft_strcmp

ft_strcmp:
	xor		rcx,			rcx				; int	i = 0
	xor		rax,			rax				; rax = 0
	xor		r8,				r8				; r8 = 0
	jmp		.loop							; jump to loop func

.inc:
	inc		rcx								; i++
.loop:
	mov		r8b,			byte[rsi+rcx]	;
	cmp		byte[rdi+rcx],	r8b				; if (s1[i] != s2[i])
	jne		.done							; jump to .done func
	test	r8b,			r8b				; if != EOL
	jnz		.inc							; jump next loop

.done:
	mov		al,				byte[rdi+rcx]
	sub		rax,			r8				; set return value
	ret										; return s1[i] - s2[i]
	

;	int		ft_strcmp(const char *s1, const char *s2) {
;		int	i = 0;
;
;		while (s1[i] == s2[i])
;			i++;
;		return (s1[i] - s2[i]);
;	}
