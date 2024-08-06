global	ft_strcpy

ft_strcpy:
	xor	rcx,			rcx				; size_t	i = 0

.loop:
	cmp	byte[rsi+rcx],	0				; if (src[i] == '\0')
	je	.done							; jump to .done func
	mov	r8b,			byte[rsi+rcx]	;
	mov	byte[rdi+rcx],	r8b				; dst[i] = src[i]
	inc	rcx								; i++
	jmp	.loop							; jump to .loop func

.done:	
	mov	byte[rdi+rcx],	0				; dst[i] = '\0'
	mov	rax,			rdi				; set return value
	ret									; return dst

;	char	*strcpy(char *dest, const char *src) {
;		size_t	i = 0;
;
;		while (src[i]) {
;			dst[i] = src[i];
;			i++;
;		}
;		dst[i] = '\0';
;		return (dst);
;	}
