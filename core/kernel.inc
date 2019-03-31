native "drop", drop
	pop rax

native "swap", swap
	pop rax
	xchg [rsp]
	push rax

native "dup", dup
	push [rsp]

native "+", plus
	pop rax
	add [rsp], rax

native "*", mul
	pop rax
	mul [rsp]
	pop rdx
	push rax

native "/", div
	pop rcx
	pop rax
	div rcx
	push rax

native "%", div_rem
	pop rcx
	pop rax
	div rcx
	push rdx

native "-", sub
	pop rax
	sub [rsp], rax

native "=", equal
	pop rax
	pop rdx
	cmp rax, rdx
	je .equals
	push 0
.equals:
	push 1

native "<", less
	pop rax
	pop rdx
	cmp rax, rdx
	jl .less
	push 0
.less:
	push 1

native ">", greater
	pop rax
	pop rdx
	cmp rax, rdx
	jg .greater
	push 0
.greater:
	push 1


