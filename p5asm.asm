dosseg
.MODEL tiny

.CODE
public _pokeW
public _pokeb
public _putchar


_pokeW PROC
	push bp
	mov bp,sp
	
	push ds
	push ax
	push bx

	mov ds,[bp+4]
	mov bx,[bp+6]
	mov ax,[bp+8]
	mov [bx],ax
	
	pop bx
	pop ax
	pop ds
	
	pop bp
	ret
_pokeW ENDP

_pokeb PROC
	push bp
	mov bp,sp
	
	push ds
	push ax
	push bx

	mov ds,[bp+4]
	mov bx,[bp+6]
	mov ah,[bp+8]

	mov [bx],ah

	pop bx
	pop ax
	pop ds
	
	pop bp
	ret
_pokeb ENDP

_putchar PROC
	push bp
	mov bp,sp

	push dx
	push ax
	
	mov dl,[bp+4]
	mov ah,2
	int 21h
	
	pop ax
	pop dx

	pop bp
	ret
_putchar ENDP
END

