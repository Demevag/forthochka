native "drop", drop
	pop

native "swap", swap
	pop rax
	xchg [rsp]
	push rax

native "dup", dup
	push [rsp]


