; Stack commands
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

;Arithmetic operators
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

;Logic operators
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

;Return stack commands
native ">r", push_to_r
	pop rax
	rpush rax
	jmp next

native "r>", pop_from_r
	rpop rax
	push rax
	jmp next

native "r@", fetch_r
	push qword[rstack]
	jmp next

;Memory commands
native "@", fetch
	pop rax
	push qword[rax]
	jmp next

;(val adr - )
native "!", store
	pop rax	
	pop rdx
	mov [rax], rdx
	jmp next

native "c!", store_char
	pop rdx
	pop rax
	mov [rdx], al
	jmp next

native "c@", fetch_char
	pop rax
	movzx rax,  byte[rax]
	push rax
	jmp next
	
native "execute", execute
	pop rax
	mov w, rax
	jmp [rax]

native "forth-dp", forth_dp
	push dp
	jmp next

;Execution management commands
native "docol", docol
	rpush pc
	add w, 8
	mov pc, w
	jmp next

native "branch", branch
	mov pc, [pc]
	jmp next

native "0branch", branch0
	pop rax
	test rax,rax
	jnz .skip
	mov pc, [pc]
	jmp next
.skip:
	add pc, 8
	jmp next

native "exit", exit
	rpop pc
	jmp next

;Service commands
native "lit", lit
	push qword[pc]
	add pc, 8
	jmp next

native "forth-sp", forth_sp
	push rsp
	jmp next

native "forth-stack-base", forth_stack_base
	push stack_start
	jmp next

;( call_num a1 a2 a3 a4 a5 a6 -- new_rax new_rdx )
;rdi, rsi, rdx, r10, r8, r9
native "syscall", syscall
	pop r9
	pop r8
	pop r10
	pop rdx
	pop rsi
	pop rdi
	pop rax
	syscall
	push rax
	push rdx
	jmp next

native "..", show_stack
	mov rcx, rsp
.loop:
	 cmp rcx, [stack_start] 
     jae next
     mov rdi, [rcx]
     push rcx
     call print_int
     call print_newline
     pop rcx
     add rcx, 8
     jmp .loop

native "forth-stack-restore", forth_stack_restore
  mov rsp, [stack_start]
  jmp next

