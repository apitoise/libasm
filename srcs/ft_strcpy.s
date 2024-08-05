global	ft_strcpy

ft_strcpy:
	xor	rsi,			rsi				; size_t	i = 0

.loop:
	cmp	byte[rdi+rsi],	0				; if (src[i] == '\0')
	je	.done							; jump to .done func
	mov	byte[rax+rsi], byte[rdi+rsi]	; dst[i] = src[i]
	inc	rsi								; i++
	jmp	.loop							; jump to .loop func

.done:
	mov	byte[rax+rsi], 0				; dst[i] = '\0'
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
