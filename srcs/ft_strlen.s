global	ft_strlen

ft_strlen:
	xor	rax,				rax		; len = 0

.loop:
	cmp	byte[rdi + rax],	0		; if s[len] == '\0'
	je	.done						; 	jump to .done func
	inc	rax							; len++
	jmp	.loop						; jump to .loop func

.done:
	ret								; return len

;	size_t	ft_strlen(const char *s) {
;		size_t	len;
;	
;		len = 0;
;		while (s[len])
;			len++;
;		return (len);
;	}
