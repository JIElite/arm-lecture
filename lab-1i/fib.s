	.syntax unified
	.arch armv7-a
	.text
	.align 2
	.thumb
	.thumb_func

	.global fibonacci
	.type fibonacci, function

fibonacci:
	@ ADD/MODIFY CODE BELOW
	@ PROLOG
	push {r3, r4, r5, r6, lr}
		
	@ R4 = R0 - 0 (update flags)
	@ if(R0 <= 0) goto .L3 (which returns 0)
	subs r4, r0, #0
	ble .L3

	@ Compare R4 wtih 1
	@ If R4 == 1 goto .L4 (which returns 1)
	cmp r4, #1
	beq .L4	

	@ If input number is bigger than 1
	@ R4 is used to be counter 

	mov r3, #0
	mov r5, #1

.L5:
	mov r6, r5
	add r5, r3, r5 
	mov r3, r6
	
	sub r4, r4, #1
	cmp r4, #1
	bne .L5

	mov r0, r5
		
	pop {r3, r4, r5, r6, pc}		@EPILOG

	@ END CODE MODIFICATION

.L3:
	@ return value is r0
	mov r0, #0			@ R0 = 0
	pop {r3, r4, r5, r6, pc}		@ EPILOG

.L4:
	@ return value is r0
	mov r0, #1			@ R0 = 1
	pop {r3, r4, r5, r6, pc}		@ EPILOG

	.size fibonacci, .-fibonacci
	.end
