extern	ft_strlen
extern	ft_strcpy
extern	malloc
extern	__errno_location
global	ft_strdup

ft_strdup:
	push	rdi								; save str on stack
	call	ft_strlen						; ft_strlen(str)
	inc		rax								; len++ for '\0'
	mov		rdi,			rax				; set malloc arg with len
	call	malloc wrt ..plt				; malloc(len)
	test	rax,			rax				; if malloc failed
	jz		.error							; jmp to .error
	pop		rsi								; get str in rsi
	mov		rdi,			rax				; set strcpy first arg with malloc return
	call	ft_strcpy						; ft_strcpy(ret, str)
	jmp		.done							; jmp to .done

.error:
	mov		r8,				rax
	neg		r8								; get absolute error value
	mov		rdi,			rax				;
	call	__errno_location wrt ..plt		;
	mov		[rax],			r8				; set errno value
	xor		rax,			rax				; set return value to NULL

.done:
	ret										; return rax

;	char	*ft_strdup(const char *str) {
;		char	*res;
;		size_t	len = ft_strlen(str);
;		size_t	i = 0;
;	
;		if (!(res = malloc(len)))
;			return (NULL);
;		while (str[i]) {
;			res[i] = str[i];
;			i++;
;		}
;		res[i] = '\0';
;		return (res);
;	}
