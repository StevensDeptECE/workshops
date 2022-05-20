	.file	"looppractice1.cc"
	.text
	.p2align 4
	.globl	_Z4sum2mm
	.type	_Z4sum2mm, @function
_Z4sum2mm:
.LFB1641:
	.cfi_startproc
	endbr64
	leaq	(%rdi,%rsi), %rax
	ret
	.cfi_endproc
.LFE1641:
	.size	_Z4sum2mm, .-_Z4sum2mm
	.p2align 4
	.globl	_Z3summm
	.type	_Z3summm, @function
_Z3summm:
.LFB1642:
	.cfi_startproc
	endbr64
	movslq	%edi, %rdi
	cmpq	%rdi, %rsi
	jb	.L4
	.p2align 4,,10
	.p2align 3
.L5:
	addq	%rdi, %rax
	addq	$1, %rdi
	cmpq	%rdi, %rsi
	jnb	.L5
.L4:
	ret
	.cfi_endproc
.LFE1642:
	.size	_Z3summm, .-_Z3summm
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1643:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$15, %esi
	leaq	_ZSt4cout(%rip), %rdi
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	leaq	7(%rsp), %rbp
	call	_ZNSo9_M_insertImEERSoT_@PLT
	movl	$1, %edx
	movq	%rbp, %rsi
	movb	$10, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	leaq	_ZSt4cout(%rip), %rdi
	movabsq	$500000500000, %rsi
	call	_ZNSo9_M_insertImEERSoT_@PLT
	movl	$1, %edx
	movq	%rbp, %rsi
	movb	$10, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	8(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L10
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L10:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1643:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__Z4sum2mm, @function
_GLOBAL__sub_I__Z4sum2mm:
.LFB2138:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2138:
	.size	_GLOBAL__sub_I__Z4sum2mm, .-_GLOBAL__sub_I__Z4sum2mm
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z4sum2mm
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 10.3.0-1ubuntu1~20.04) 10.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
