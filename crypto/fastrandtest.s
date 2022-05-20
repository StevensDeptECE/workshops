	.file	"fastrandtest.cc"
	.text
	.p2align 4
	.globl	_Z14countHistBits1PKmjPj
	.type	_Z14countHistBits1PKmjPj, @function
_Z14countHistBits1PKmjPj:
.LFB7098:
	.cfi_startproc
	endbr64
	movq	%rdx, %rcx
	movq	%rdx, %rax
	leaq	256(%rdx), %rdx
	movl	%esi, %r8d
	.p2align 4,,10
	.p2align 3
.L2:
	movl	$0, (%rax)
	addq	$4, %rax
	cmpq	%rdx, %rax
	jne	.L2
	testl	%r8d, %r8d
	je	.L16
	leal	-1(%r8), %eax
	movq	%rdi, %rsi
	leaq	8(%rdi,%rax,8), %rdi
	.p2align 4,,10
	.p2align 3
.L6:
	movq	(%rsi), %rdx
	movl	$64, %eax
	.p2align 4,,10
	.p2align 3
.L5:
	testq	%rax, %rdx
	je	.L4
	addl	$1, (%rcx,%rax,4)
.L4:
	subq	$1, %rax
	jne	.L5
	addq	$8, %rsi
	cmpq	%rdi, %rsi
	jne	.L6
.L16:
	ret
	.cfi_endproc
.LFE7098:
	.size	_Z14countHistBits1PKmjPj, .-_Z14countHistBits1PKmjPj
	.p2align 4
	.globl	_Z14countHistBits2PKmjPj
	.type	_Z14countHistBits2PKmjPj, @function
_Z14countHistBits2PKmjPj:
.LFB7099:
	.cfi_startproc
	endbr64
	leal	-1(%rsi), %eax
	movq	%rdi, %r11
	movl	%esi, %r9d
	movq	%rdx, %r8
	leaq	256(%rdx), %r10
	leaq	8(%rdi,%rax,8), %rdi
	movl	$1, %esi
	.p2align 4,,10
	.p2align 3
.L22:
	testl	%r9d, %r9d
	je	.L23
	movq	%r11, %rax
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L21:
	movq	(%rax), %rcx
	andq	%rsi, %rcx
	cmpq	$1, %rcx
	sbbq	$-1, %rdx
	addq	$8, %rax
	cmpq	%rdi, %rax
	jne	.L21
	movl	%edx, (%r8)
	addq	$4, %r8
	addq	%rsi, %rsi
	cmpq	%r10, %r8
	jne	.L22
.L28:
	ret
	.p2align 4,,10
	.p2align 3
.L23:
	xorl	%edx, %edx
	addq	$4, %r8
	addq	%rsi, %rsi
	movl	%edx, -4(%r8)
	cmpq	%r10, %r8
	jne	.L22
	jmp	.L28
	.cfi_endproc
.LFE7099:
	.size	_Z14countHistBits2PKmjPj, .-_Z14countHistBits2PKmjPj
	.p2align 4
	.globl	_Z14countHistBits3PKmjPj
	.type	_Z14countHistBits3PKmjPj, @function
_Z14countHistBits3PKmjPj:
.LFB7100:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	leal	-1(%rsi), %eax
	leaq	256(%rdx), %r15
	movl	$2, %r11d
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movl	$1, %r10d
	movl	%esi, %r14d
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movq	%rdx, %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	8(%rdi,%rax,8), %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movl	$8, %ebp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	$4, %ebx
	movq	%rdi, -8(%rsp)
	.p2align 4,,10
	.p2align 3
.L36:
	testl	%r14d, %r14d
	je	.L37
	movq	-8(%rsp), %rdx
	xorl	%ecx, %ecx
	xorl	%esi, %esi
	xorl	%edi, %edi
	xorl	%r8d, %r8d
	.p2align 4,,10
	.p2align 3
.L35:
	movq	(%rdx), %rax
	movq	%rax, %r9
	andq	%r10, %r9
	cmpq	$1, %r9
	movq	%rax, %r9
	sbbq	$-1, %r8
	andq	%r11, %r9
	cmpq	$1, %r9
	movq	%rax, %r9
	sbbq	$-1, %rdi
	andq	%rbx, %r9
	cmpq	$1, %r9
	sbbq	$-1, %rsi
	andq	%rbp, %rax
	cmpq	$1, %rax
	sbbq	$-1, %rcx
	addq	$8, %rdx
	cmpq	%rdx, %r12
	jne	.L35
.L30:
	movl	%r8d, 0(%r13)
	salq	$4, %r10
	addq	$16, %r13
	salq	$4, %r11
	movl	%edi, -12(%r13)
	salq	$4, %rbx
	salq	$4, %rbp
	movl	%esi, -8(%r13)
	movl	%ecx, -4(%r13)
	cmpq	%r13, %r15
	jne	.L36
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L37:
	.cfi_restore_state
	xorl	%ecx, %ecx
	xorl	%esi, %esi
	xorl	%edi, %edi
	xorl	%r8d, %r8d
	jmp	.L30
	.cfi_endproc
.LFE7100:
	.size	_Z14countHistBits3PKmjPj, .-_Z14countHistBits3PKmjPj
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"failure to set random method"
.LC1:
	.string	"failure to randomize block"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4
	.globl	_Z8genRand3Pmj
	.type	_Z8genRand3Pmj, @function
_Z8genRand3Pmj:
.LFB7094:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	%esi, %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	RAND_get_rand_method@PLT
	movq	%rax, %rdi
	call	RAND_set_rand_method@PLT
	testl	%eax, %eax
	je	.L52
	leal	0(,%rbx,8), %esi
	movq	%rbp, %rdi
	call	RAND_bytes@PLT
	testl	%eax, %eax
	je	.L53
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.type	_Z8genRand3Pmj.cold, @function
_Z8genRand3Pmj.cold:
.LFSB7094:
.L52:
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -24
	.cfi_offset 6, -16
	movl	$8, %edi
	call	__cxa_allocate_exception@PLT
	xorl	%edx, %edx
	leaq	_ZTIPKc(%rip), %rsi
	movq	%rax, %rdi
	leaq	.LC0(%rip), %rax
	movq	%rax, (%rdi)
	call	__cxa_throw@PLT
.L53:
	movl	$8, %edi
	call	__cxa_allocate_exception@PLT
	xorl	%edx, %edx
	leaq	_ZTIPKc(%rip), %rsi
	movq	%rax, %rdi
	leaq	.LC1(%rip), %rax
	movq	%rax, (%rdi)
	call	__cxa_throw@PLT
	.cfi_endproc
.LFE7094:
	.text
	.size	_Z8genRand3Pmj, .-_Z8genRand3Pmj
	.section	.text.unlikely
	.size	_Z8genRand3Pmj.cold, .-_Z8genRand3Pmj.cold
.LCOLDE2:
	.text
.LHOTE2:
	.section	.rodata.str1.1
.LC3:
	.string	"random number generator fail "
.LC4:
	.string	"\n"
	.text
	.p2align 4
	.globl	_Z8genRand4Pmj
	.type	_Z8genRand4Pmj, @function
_Z8genRand4Pmj:
.LFB7095:
	.cfi_startproc
	endbr64
	testl	%esi, %esi
	je	.L64
	leal	-1(%rsi), %eax
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	xorl	%ebx, %ebx
	leaq	(%rdi,%rax,8), %rdx
	.p2align 4,,10
	.p2align 3
.L59:
	rdseed	%rax
	movq	%rax, (%rdi)
	movq	%rdi, %rax
	adcl	$0, %ebx
	addq	$8, %rdi
	cmpq	%rdx, %rax
	jne	.L59
	cmpl	%ebx, %esi
	je	.L62
	movl	$29, %edx
	leaq	.LC3(%rip), %rsi
	leaq	_ZSt4cerr(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	%ebx, %esi
	leaq	_ZSt4cerr(%rip), %rdi
	call	_ZNSo9_M_insertImEERSoT_@PLT
	movl	$1, %edx
	leaq	.LC4(%rip), %rsi
	popq	%rbx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	movq	%rax, %rdi
	jmp	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	.p2align 4,,10
	.p2align 3
.L62:
	.cfi_restore_state
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L64:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE7095:
	.size	_Z8genRand4Pmj, .-_Z8genRand4Pmj
	.p2align 4
	.globl	_Z8genRand2Pmj
	.type	_Z8genRand2Pmj, @function
_Z8genRand2Pmj:
.LFB7093:
	.cfi_startproc
	endbr64
	testl	%esi, %esi
	je	.L75
	leal	-1(%rsi), %eax
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$1, %edx
	xorl	%ebx, %ebx
	leaq	(%rdi,%rax,8), %rcx
	.p2align 4,,10
	.p2align 3
.L70:
	rdrand	%rax
	movq	%rax, (%rdi)
	cmovc	%edx, %eax
	addl	%eax, %ebx
	movq	%rdi, %rax
	addq	$8, %rdi
	cmpq	%rcx, %rax
	jne	.L70
	cmpl	%ebx, %esi
	je	.L73
	movl	$29, %edx
	leaq	.LC3(%rip), %rsi
	leaq	_ZSt4cerr(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	%ebx, %esi
	leaq	_ZSt4cerr(%rip), %rdi
	call	_ZNSo9_M_insertImEERSoT_@PLT
	movl	$1, %edx
	leaq	.LC4(%rip), %rsi
	popq	%rbx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	movq	%rax, %rdi
	jmp	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	.p2align 4,,10
	.p2align 3
.L73:
	.cfi_restore_state
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L75:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE7093:
	.size	_Z8genRand2Pmj, .-_Z8genRand2Pmj
	.p2align 4
	.globl	_Z8genRand1Pmj
	.type	_Z8genRand1Pmj, @function
_Z8genRand1Pmj:
.LFB7092:
	.cfi_startproc
	endbr64
	testl	%esi, %esi
	je	.L89
	leal	-1(%rsi), %eax
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$1, %edx
	xorl	%ebx, %ebx
	leaq	(%rdi,%rax,8), %rcx
	jmp	.L82
	.p2align 4,,10
	.p2align 3
.L84:
	movq	%rax, %rdi
.L82:
	rdrand	%rax
	movq	%rax, (%rdi)
	cmovc	%edx, %eax
	cmpl	$1, %eax
	leaq	8(%rdi), %rax
	sbbl	$-1, %ebx
	cmpq	%rcx, %rdi
	jne	.L84
	cmpl	%esi, %ebx
	je	.L87
	movl	$29, %edx
	leaq	.LC3(%rip), %rsi
	leaq	_ZSt4cerr(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	%ebx, %esi
	leaq	_ZSt4cerr(%rip), %rdi
	call	_ZNSo9_M_insertImEERSoT_@PLT
	movl	$1, %edx
	leaq	.LC4(%rip), %rsi
	popq	%rbx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	movq	%rax, %rdi
	jmp	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	.p2align 4,,10
	.p2align 3
.L87:
	.cfi_restore_state
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L89:
	.cfi_restore 3
	ret
	.cfi_endproc
.LFE7092:
	.size	_Z8genRand1Pmj, .-_Z8genRand1Pmj
	.section	.text._ZNK5Stats4corrEv,"axG",@progbits,_ZNK5Stats4corrEv,comdat
	.align 2
	.p2align 4
	.weak	_ZNK5Stats4corrEv
	.type	_ZNK5Stats4corrEv, @function
_ZNK5Stats4corrEv:
.LFB7091:
	.cfi_startproc
	endbr64
	vmovsd	(%rdi), %xmm4
	vmovsd	8(%rdi), %xmm3
	vxorps	%xmm1, %xmm1, %xmm1
	movl	40(%rdi), %eax
	vmulsd	%xmm3, %xmm4, %xmm0
	vcvtsi2sdq	%rax, %xmm1, %xmm1
	vmulsd	16(%rdi), %xmm1, %xmm2
	vmulsd	%xmm3, %xmm3, %xmm3
	vmulsd	%xmm4, %xmm4, %xmm4
	vsubsd	%xmm0, %xmm2, %xmm2
	vmulsd	24(%rdi), %xmm1, %xmm0
	vmulsd	32(%rdi), %xmm1, %xmm1
	vsubsd	%xmm4, %xmm0, %xmm0
	vsubsd	%xmm3, %xmm1, %xmm1
	vmulsd	%xmm1, %xmm0, %xmm0
	vxorpd	%xmm1, %xmm1, %xmm1
	vucomisd	%xmm0, %xmm1
	vsqrtsd	%xmm0, %xmm0, %xmm3
	ja	.L100
	vdivsd	%xmm3, %xmm2, %xmm0
	ret
.L100:
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	vmovsd	%xmm3, 8(%rsp)
	vmovsd	%xmm2, (%rsp)
	call	sqrt@PLT
	vmovsd	8(%rsp), %xmm3
	vmovsd	(%rsp), %xmm2
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	vdivsd	%xmm3, %xmm2, %xmm0
	ret
	.cfi_endproc
.LFE7091:
	.size	_ZNK5Stats4corrEv, .-_ZNK5Stats4corrEv
	.text
	.p2align 4
	.globl	_Z11displayHistPKjdi
	.type	_Z11displayHistPKjdi, @function
_Z11displayHistPKjdi:
.LFB7096:
	.cfi_startproc
	endbr64
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	vxorps	%xmm3, %xmm3, %xmm3
	leaq	512(%rdi), %rdx
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	vxorpd	%xmm2, %xmm2, %xmm2
	.p2align 4,,10
	.p2align 3
.L104:
	movl	(%rdi), %eax
	addq	$4, %rdi
	vcvtsi2sdq	%rax, %xmm3, %xmm1
	vsubsd	%xmm0, %xmm1, %xmm1
	vmulsd	%xmm1, %xmm1, %xmm1
	vaddsd	%xmm1, %xmm2, %xmm2
	cmpq	%rdi, %rdx
	jne	.L104
	vcvtsi2sdl	%esi, %xmm3, %xmm3
	leaq	_ZSt4cout(%rip), %rdi
	vdivsd	%xmm3, %xmm2, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	leaq	7(%rsp), %rsi
	movl	$1, %edx
	movb	$10, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L109
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L109:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE7096:
	.size	_Z11displayHistPKjdi, .-_Z11displayHistPKjdi
	.section	.rodata.str1.1
.LC6:
	.string	"variance of bit values: "
	.text
	.p2align 4
	.globl	_Z11varHistBitsPjj
	.type	_Z11varHistBitsPjj, @function
_Z11varHistBitsPjj:
.LFB7097:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	shrl	%esi
	leaq	256(%rdi), %rdx
	xorl	%ebp, %ebp
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L111:
	movl	(%rdi), %eax
	addq	$4, %rdi
	subl	%esi, %eax
	imull	%eax, %eax
	addq	%rax, %rbp
	cmpq	%rdi, %rdx
	jne	.L111
	movl	$24, %edx
	leaq	.LC6(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rbp, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertImEERSoT_@PLT
	leaq	7(%rsp), %rsi
	movl	$1, %edx
	movb	$10, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L116
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L116:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE7097:
	.size	_Z11varHistBitsPjj, .-_Z11varHistBitsPjj
	.p2align 4
	.globl	_Z14countHistBits4PKmjPj
	.type	_Z14countHistBits4PKmjPj, @function
_Z14countHistBits4PKmjPj:
.LFB7101:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	andq	$-32, %rsp
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, 56(%rsp)
	xorl	%eax, %eax
	movabsq	$2251816993685505, %rax
	movq	%rax, 16(%rsp)
	movabsq	$36029071898968080, %rax
	movq	%rax, 24(%rsp)
	vmovdqa	16(%rsp), %xmm6
	movabsq	$576465150383489280, %rax
	movq	%rax, 32(%rsp)
	movabsq	$-9223301667573723136, %rax
	movq	%rax, 40(%rsp)
	vinserti128	$0x1, 32(%rsp), %ymm6, %ymm1
	testl	%esi, %esi
	je	.L121
	vpxor	%xmm2, %xmm2, %xmm2
	leal	-1(%rsi), %eax
	leaq	8(%rdi,%rax,8), %r9
	vmovdqa	%ymm2, %ymm3
	vmovdqa	%ymm2, %ymm4
	vmovdqa	%ymm2, %ymm5
	.p2align 4,,10
	.p2align 3
.L119:
	movq	(%rdi), %rax
	addq	$8, %rdi
	vmovd	%eax, %xmm0
	movq	%rax, %r8
	movq	%rax, %rsi
	movq	%rax, %rcx
	shrq	$16, %r8
	vpbroadcastw	%xmm0, %ymm0
	shrq	$32, %rsi
	vpand	%ymm0, %ymm1, %ymm0
	shrq	$48, %rcx
	vpaddsw	%ymm0, %ymm5, %ymm5
	vmovd	%r8d, %xmm0
	vpbroadcastw	%xmm0, %ymm0
	vpand	%ymm0, %ymm1, %ymm0
	vpaddsw	%ymm0, %ymm4, %ymm4
	vmovd	%esi, %xmm0
	vpbroadcastw	%xmm0, %ymm0
	vpand	%ymm0, %ymm1, %ymm0
	vpaddsw	%ymm0, %ymm3, %ymm3
	vmovd	%ecx, %xmm0
	vpbroadcastw	%xmm0, %ymm0
	vpand	%ymm0, %ymm1, %ymm0
	vpaddsw	%ymm0, %ymm2, %ymm2
	cmpq	%rdi, %r9
	jne	.L119
.L118:
	vmovdqa	%ymm5, (%rdx)
	vmovdqa	%ymm4, 16(%rdx)
	vmovdqa	%ymm3, 32(%rdx)
	vmovdqa	%ymm2, 48(%rdx)
	movq	56(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L125
	vzeroupper
	leave
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L121:
	.cfi_restore_state
	vpxor	%xmm2, %xmm2, %xmm2
	vmovdqa	%ymm2, %ymm3
	vmovdqa	%ymm2, %ymm4
	vmovdqa	%ymm2, %ymm5
	jmp	.L118
.L125:
	vzeroupper
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE7101:
	.size	_Z14countHistBits4PKmjPj, .-_Z14countHistBits4PKmjPj
	.section	.rodata.str1.1
.LC7:
	.string	": "
	.text
	.p2align 4
	.globl	_Z5benchPKcPFvPmjES1_j
	.type	_Z5benchPKcPFvPmjES1_j, @function
_Z5benchPKcPFvPmjES1_j:
.LFB7102:
	.cfi_startproc
	endbr64
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	movl	%ecx, %r14d
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	movq	%rdx, %r13
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	%rsi, %rbx
	subq	$16, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	clock@PLT
	movl	%r14d, %esi
	movq	%r13, %rdi
	movq	%rax, %r12
	call	*%rbx
	call	clock@PLT
	movq	%rax, %rbx
	testq	%rbp, %rbp
	je	.L132
	movq	%rbp, %rdi
	call	strlen@PLT
	movq	%rbp, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.L128:
	movl	$2, %edx
	leaq	.LC7(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	subq	%r12, %rbx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	vxorps	%xmm0, %xmm0, %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	vcvtsi2sdq	%rbx, %xmm0, %xmm0
	vmulsd	.LC8(%rip), %xmm0, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	leaq	7(%rsp), %rsi
	movl	$1, %edx
	movb	$10, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L133
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L132:
	.cfi_restore_state
	movq	_ZSt4cout(%rip), %rax
	leaq	_ZSt4cout(%rip), %rdi
	addq	-24(%rax), %rdi
	movl	32(%rdi), %esi
	orl	$1, %esi
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
	jmp	.L128
.L133:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE7102:
	.size	_Z5benchPKcPFvPmjES1_j, .-_Z5benchPKcPFvPmjES1_j
	.p2align 4
	.globl	_Z5benchPKcPFvPKmjPjEPmjS3_
	.type	_Z5benchPKcPFvPKmjPjEPmjS3_, @function
_Z5benchPKcPFvPKmjPjEPmjS3_:
.LFB7103:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movq	%r8, %r15
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movl	%ecx, %r14d
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movq	%rdx, %r13
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rsi, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	clock@PLT
	movq	%r15, %rdx
	movl	%r14d, %esi
	movq	%r13, %rdi
	movq	%rax, %r12
	call	*%rbx
	call	clock@PLT
	movq	%rax, %rbx
	testq	%rbp, %rbp
	je	.L140
	movq	%rbp, %rdi
	call	strlen@PLT
	movq	%rbp, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
.L136:
	movl	$2, %edx
	leaq	.LC7(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	subq	%r12, %rbx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	vxorps	%xmm0, %xmm0, %xmm0
	leaq	_ZSt4cout(%rip), %rdi
	vcvtsi2sdq	%rbx, %xmm0, %xmm0
	vmulsd	.LC8(%rip), %xmm0, %xmm0
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	leaq	7(%rsp), %rsi
	movl	$1, %edx
	movb	$10, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L141
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L140:
	.cfi_restore_state
	movq	_ZSt4cout(%rip), %rax
	leaq	_ZSt4cout(%rip), %rdi
	addq	-24(%rax), %rdi
	movl	32(%rdi), %esi
	orl	$1, %esi
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT
	jmp	.L136
.L141:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE7103:
	.size	_Z5benchPKcPFvPKmjPjEPmjS3_, .-_Z5benchPKcPFvPKmjPjEPmjS3_
	.section	.rodata.str1.1
.LC9:
	.string	"genRand1: "
.LC10:
	.string	"countHistBits1: "
.LC11:
	.string	"countHistBits2: "
.LC12:
	.string	"countHistBits3: "
.LC13:
	.string	"countHistBits4: "
.LC14:
	.string	"genRand2: "
.LC15:
	.string	"genRand3: "
.LC16:
	.string	"genRand4: "
.LC18:
	.string	"64 bit correlation: "
.LC19:
	.string	"32 bit correlation: "
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB7104:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movl	$80000000, %edi
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$3432, %rsp
	.cfi_def_cfa_offset 3488
	movq	%fs:40, %rax
	movq	%rax, 3416(%rsp)
	xorl	%eax, %eax
	leaq	80(%rsp), %r12
	leaq	1872(%rsp), %r15
	call	_Znam@PLT
	movl	$10000000, %ecx
	leaq	_Z8genRand1Pmj(%rip), %rsi
	leaq	.LC9(%rip), %rdi
	movq	%rax, %rbp
	movq	%rax, %rdx
	leaq	2384(%rsp), %r14
	call	_Z5benchPKcPFvPmjES1_j
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits1PKmjPj(%rip), %rsi
	leaq	.LC10(%rip), %rdi
	movq	%rbp, %rbx
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movq	%r12, %rdi
	movl	$10000000, %esi
	leaq	2896(%rsp), %r13
	call	_Z11varHistBitsPjj
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits2PKmjPj(%rip), %rsi
	leaq	.LC11(%rip), %rdi
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movq	%r12, %rdi
	movl	$10000000, %esi
	call	_Z11varHistBitsPjj
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits1PKmjPj(%rip), %rsi
	leaq	.LC10(%rip), %rdi
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movq	%r12, %rdi
	movl	$10000000, %esi
	call	_Z11varHistBitsPjj
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits3PKmjPj(%rip), %rsi
	leaq	.LC12(%rip), %rdi
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits3PKmjPj(%rip), %rsi
	leaq	.LC13(%rip), %rdi
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z8genRand2Pmj(%rip), %rsi
	leaq	.LC14(%rip), %rdi
	call	_Z5benchPKcPFvPmjES1_j
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits2PKmjPj(%rip), %rsi
	leaq	.LC11(%rip), %rdi
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movq	%r12, %rdi
	movl	$10000000, %esi
	call	_Z11varHistBitsPjj
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits1PKmjPj(%rip), %rsi
	leaq	.LC10(%rip), %rdi
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movq	%r12, %rdi
	movl	$10000000, %esi
	call	_Z11varHistBitsPjj
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits2PKmjPj(%rip), %rsi
	leaq	.LC11(%rip), %rdi
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movq	%r12, %rdi
	movl	$10000000, %esi
	call	_Z11varHistBitsPjj
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z8genRand3Pmj(%rip), %rsi
	leaq	.LC15(%rip), %rdi
	call	_Z5benchPKcPFvPmjES1_j
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits2PKmjPj(%rip), %rsi
	leaq	.LC11(%rip), %rdi
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z8genRand4Pmj(%rip), %rsi
	leaq	.LC16(%rip), %rdi
	call	_Z5benchPKcPFvPmjES1_j
	movq	%r12, %r8
	movl	$10000000, %ecx
	movq	%rbp, %rdx
	leaq	_Z14countHistBits2PKmjPj(%rip), %rsi
	leaq	.LC11(%rip), %rdi
	call	_Z5benchPKcPFvPKmjPjEPmjS3_
	movq	%r12, %rdi
	movl	$10000000, %esi
	leaq	80000000(%rbp), %r12
	call	_Z11varHistBitsPjj
	leaq	336(%rsp), %r10
	xorl	%eax, %eax
	movl	$64, %ecx
	movq	%r10, %rdi
	leaq	848(%rsp), %r9
	leaq	1360(%rsp), %r8
	rep stosq
	movl	$64, %ecx
	movq	%r9, %rdi
	rep stosq
	movl	$64, %ecx
	movq	%r8, %rdi
	rep stosq
	movl	$64, %ecx
	movq	%r15, %rdi
	rep stosq
	movl	$64, %ecx
	movq	%r14, %rdi
	rep stosq
	movl	$64, %ecx
	movq	%r13, %rdi
	rep stosq
	movq	%rbp, %rcx
	.p2align 4,,10
	.p2align 3
.L143:
	movq	(%rcx), %rax
	addq	$8, %rcx
	movq	%rax, %rdx
	shrq	$57, %rdx
	addl	$1, 336(%rsp,%rdx,4)
	movq	%rax, %rdx
	shrq	$50, %rdx
	andl	$127, %edx
	addl	$1, 848(%rsp,%rdx,4)
	movq	%rax, %rdx
	shrq	$43, %rdx
	andl	$127, %edx
	addl	$1, 1360(%rsp,%rdx,4)
	movq	%rax, %rdx
	shrq	$36, %rdx
	andl	$127, %edx
	addl	$1, 1872(%rsp,%rdx,4)
	movq	%rax, %rdx
	shrq	$22, %rax
	shrq	$29, %rdx
	andl	$127, %eax
	andl	$127, %edx
	addl	$1, 2896(%rsp,%rax,4)
	addl	$1, 2384(%rsp,%rdx,4)
	cmpq	%rcx, %r12
	jne	.L143
	movq	.LC17(%rip), %rax
	movq	%r10, %rdi
	movl	$10000000, %esi
	movq	%r8, 8(%rsp)
	movq	%r9, (%rsp)
	vmovq	%rax, %xmm0
	call	_Z11displayHistPKjdi
	movq	(%rsp), %r9
	movl	$10000000, %esi
	movq	.LC17(%rip), %rax
	movq	%r9, %rdi
	vmovq	%rax, %xmm0
	call	_Z11displayHistPKjdi
	movq	8(%rsp), %r8
	movl	$10000000, %esi
	movq	.LC17(%rip), %rax
	movq	%r8, %rdi
	vmovq	%rax, %xmm0
	call	_Z11displayHistPKjdi
	movq	.LC17(%rip), %rax
	movl	$10000000, %esi
	movq	%r15, %rdi
	vmovq	%rax, %xmm0
	call	_Z11displayHistPKjdi
	movq	.LC17(%rip), %rax
	movl	$10000000, %esi
	movq	%r14, %rdi
	vmovq	%rax, %xmm0
	call	_Z11displayHistPKjdi
	movq	.LC17(%rip), %rax
	movl	$10000000, %esi
	movq	%r13, %rdi
	vmovq	%rax, %xmm0
	call	_Z11displayHistPKjdi
	vxorpd	%xmm3, %xmm3, %xmm3
	movq	%rbp, %rdx
	vxorps	%xmm2, %xmm2, %xmm2
	vmovapd	%xmm3, %xmm4
	vmovapd	%xmm3, %xmm5
	vmovapd	%xmm3, %xmm6
	vmovapd	%xmm3, %xmm7
	vmovapd	%xmm3, %xmm8
	jmp	.L148
	.p2align 4,,10
	.p2align 3
.L160:
	vcvtsi2sdq	%rax, %xmm2, %xmm1
	movq	(%rdx), %rax
	testq	%rax, %rax
	js	.L146
.L161:
	vcvtsi2sdq	%rax, %xmm2, %xmm0
.L147:
	vmulsd	%xmm0, %xmm1, %xmm9
	vaddsd	%xmm0, %xmm8, %xmm8
	vaddsd	%xmm1, %xmm7, %xmm7
	addq	$16, %rdx
	vmulsd	%xmm0, %xmm0, %xmm0
	vmulsd	%xmm1, %xmm1, %xmm1
	vaddsd	%xmm9, %xmm6, %xmm6
	vaddsd	%xmm0, %xmm5, %xmm5
	vaddsd	%xmm1, %xmm4, %xmm4
	cmpq	%rdx, %r12
	je	.L159
.L148:
	movq	8(%rdx), %rax
	testq	%rax, %rax
	jns	.L160
	movq	%rax, %rcx
	andl	$1, %eax
	shrq	%rcx
	orq	%rax, %rcx
	movq	(%rdx), %rax
	vcvtsi2sdq	%rcx, %xmm2, %xmm1
	vaddsd	%xmm1, %xmm1, %xmm1
	testq	%rax, %rax
	jns	.L161
.L146:
	movq	%rax, %rcx
	andl	$1, %eax
	shrq	%rcx
	orq	%rax, %rcx
	vcvtsi2sdq	%rcx, %xmm2, %xmm0
	vaddsd	%xmm0, %xmm0, %xmm0
	jmp	.L147
.L159:
	movl	$20, %edx
	leaq	32(%rsp), %r14
	leaq	31(%rsp), %r13
	vmovsd	%xmm7, 40(%rsp)
	leaq	.LC18(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	vmovsd	%xmm6, 48(%rsp)
	vmovsd	%xmm5, 56(%rsp)
	vmovsd	%xmm4, 64(%rsp)
	vmovsd	%xmm8, 32(%rsp)
	movl	$5000000, 72(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r14, %rdi
	call	_ZNK5Stats4corrEv
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$1, %edx
	movq	%r13, %rsi
	movb	$10, 31(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	vxorpd	%xmm3, %xmm3, %xmm3
	vxorps	%xmm2, %xmm2, %xmm2
	vmovapd	%xmm3, %xmm4
	vmovapd	%xmm3, %xmm5
	vmovapd	%xmm3, %xmm6
	vmovapd	%xmm3, %xmm7
	.p2align 4,,10
	.p2align 3
.L153:
	movl	4(%rbx), %eax
	addq	$8, %rbx
	vcvtsi2sdq	%rax, %xmm2, %xmm0
	movl	-8(%rbx), %eax
	vcvtsi2sdq	%rax, %xmm2, %xmm1
	vaddsd	%xmm0, %xmm6, %xmm6
	vmulsd	%xmm1, %xmm0, %xmm8
	vaddsd	%xmm1, %xmm7, %xmm7
	vmulsd	%xmm0, %xmm0, %xmm0
	vmulsd	%xmm1, %xmm1, %xmm1
	vaddsd	%xmm8, %xmm5, %xmm5
	vaddsd	%xmm0, %xmm3, %xmm3
	vaddsd	%xmm1, %xmm4, %xmm4
	cmpq	%rbx, %r12
	jne	.L153
	movl	$20, %edx
	leaq	.LC19(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	vmovsd	%xmm7, 32(%rsp)
	vmovsd	%xmm6, 40(%rsp)
	vmovsd	%xmm5, 48(%rsp)
	vmovsd	%xmm4, 56(%rsp)
	vmovsd	%xmm3, 64(%rsp)
	movl	$10000000, 72(%rsp)
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%r14, %rdi
	call	_ZNK5Stats4corrEv
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIdEERSoT_@PLT
	movl	$1, %edx
	movq	%r13, %rsi
	movb	$10, 31(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	%rbp, %rdi
	call	_ZdaPv@PLT
	movq	3416(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L162
	addq	$3432, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L162:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE7104:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__Z8genRand1Pmj, @function
_GLOBAL__sub_I__Z8genRand1Pmj:
.LFB7592:
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
.LFE7592:
	.size	_GLOBAL__sub_I__Z8genRand1Pmj, .-_GLOBAL__sub_I__Z8genRand1Pmj
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z8genRand1Pmj
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC8:
	.long	2696277389
	.long	1051772663
	.align 8
.LC17:
	.long	0
	.long	1089671888
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
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
