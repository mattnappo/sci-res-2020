	.file	"testlib.c"
	.text
	.section	.rodata
.LC0:
	.string	"testlib.c"
.LC1:
	.string	"(*func)() == 0"
	.text
	.globl	test_time
	.type	test_time, @function
test_time:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	call	clock@PLT
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	call	*%rax
	testl	%eax, %eax
	je	.L2
	leaq	__PRETTY_FUNCTION__.0(%rip), %rcx
	movl	$7, %edx
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	__assert_fail@PLT
.L2:
	call	clock@PLT
	subq	-8(%rbp), %rax
	movq	%rax, -8(%rbp)
	pxor	%xmm0, %xmm0
	cvtsi2sdq	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	test_time, .-test_time
	.section	.rodata
	.align 8
	.type	__PRETTY_FUNCTION__.0, @object
	.size	__PRETTY_FUNCTION__.0, 10
__PRETTY_FUNCTION__.0:
	.string	"test_time"
	.ident	"GCC: (GNU) 10.2.0"
	.section	.note.GNU-stack,"",@progbits
