native "drop", drop
	pop rax
	jmp next

native "swap", swap
	pop rax
	xchg [rsp], rax
	push rax
	jmp next

native "dup", dup
	push qword[rsp]
	jmp next

native "+", plus
	pop rax
	add [rsp], rax
	jmp next

native "*", mul
	pop rax
	mul qword[rsp]
	pop rdx
	push rax
	jmp next

native "/", div
	pop rcx
	pop rax
	div rcx
	push rax
	jmp next

native "%", div_rem
	pop rcx
	pop rax
	div rcx
	push rdx
	jmp next

native "-", sub
	pop rax
	sub [rsp], rax
	jmp next

native "=", equal
	pop rax
	pop rdx
	cmp rax, rdx
	je .equals
	push 0
	jmp next
.equals:
	push 1
	jmp next

native "<", less
	pop rax
	pop rdx
	cmp rax, rdx
	jl .less
	push 0
	jmp next
.less:
	push 1
	jmp next

native ">", greater
	pop rax
	pop rdx
	cmp rax, rdx
	jg .greater
	push 0
	jmp next
.greater:
	push 1
	jmp next

native "not", bit_not
	pop rax
	not rax
	push rax
	jmp next

native "and", bit_and
	pop rax
	pop rdx
	and rdx, rax
	push rax
	jmp next

native "or", bit_or
	pop rax
	pop rdx
	or rdx, rax
	push rax
	jmp next

native "lor", lor
	pop rax
	pop rdx
	cmp rax, rax
	jnz .true
	cmp rdx, rdx
	jnz .true
	push 0
	jmp next
.true:
	push 1
	jmp next

native "land", land
	pop rax
	pop rdx
	cmp rax, rax
	jz .false
	cmp rdx, rdx
	jz .false
	push 1
	jmp next
.false:
	push 0
	jmp next

