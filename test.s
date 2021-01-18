	.file	"test.c"
	.text
	.globl	manual
	.type	manual, @function
manual:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, %edi
	call	new_list@PLT
	movq	%rax, -8(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L2
.L5:
	movl	$0, -12(%rbp)
	jmp	.L3
.L4:
	call	rand@PLT
	movslq	%eax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	insert@PLT
	addl	$1, -12(%rbp)
.L3:
	cmpl	$99, -12(%rbp)
	jle	.L4
	addl	$1, -16(%rbp)
.L2:
	cmpl	$999, -16(%rbp)
	jle	.L5
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free_list@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	manual, .-manual
	.globl	test
	.type	test, @function
test:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	call	rand@PLT
	cltq
	movq	%rax, %rdi
	call	new_list@PLT
	movq	%rax, -16(%rbp)
	movq	$10000000, -8(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L8
.L9:
	call	rand@PLT
	movslq	%eax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	insert@PLT
	addl	$1, -24(%rbp)
.L8:
	movl	-24(%rbp), %eax
	cltq
	cmpq	%rax, -8(%rbp)
	jg	.L9
	movl	$0, -20(%rbp)
	jmp	.L10
.L11:
	movl	-20(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	get@PLT
	addl	$1, -20(%rbp)
.L10:
	movl	-20(%rbp), %eax
	cltq
	cmpq	%rax, -8(%rbp)
	jg	.L11
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	free_list@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	test, .-test
	.section	.rodata
.LC0:
	.string	"list iter time: %f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	manual(%rip), %rdi
	call	test_time@PLT
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %xmm0
	leaq	.LC0(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.ident	"GCC: (GNU) 10.2.0"
	.section	.note.GNU-stack,"",@progbits
