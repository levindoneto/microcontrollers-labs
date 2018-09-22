/*
  printup.s: Assembly function converting a string to upper case.

  Copyright (c) 2016 Walter Fetter Lages <w.fetter@ieee.org>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

    You can also obtain a copy of the GNU General Public License
    at <http://www.gnu.org/licenses>.
*/

	.intel_syntax noprefix

	.text
    	.global  printup

printup:
	push	ebp
	mov	ebp,esp
	push	ebx
	push	edi
	push	esi

	mov	edi,[ebp+8]	#Endereço da string
	mov	esi,edi		#Move o endereço para ESI
	xor	ecx,ecx		#Zera ECX

	mov	ah,'A		
	xor	ah,'a		#"Descobre" qual o bit deve ser ligado
	not	ah		#Cria a máscara
	cld			#Clears the DF flag in the EFLAGS register. 
				#When the DF flag is set to 0, string operations increment the index registers (ESI and/or EDI).
L1:	lods	al,byte ptr[esi]	#Load byte at address DS:(E)SI into AL.
	and	al,ah		#Aplica a máscara no char
	jz	strend		#Se já for maiúscula, sai do loop
	stos	byte ptr[edi],al	#stosb stores a byte from the AL register into the destination operand
	inc	ecx		#Conta o número de chars modificados
	jmp	L1

strend:

	push	ecx		# message length
	push	[ebp+8]		# pointer to message to write

	call	print		#Chama a função na lib, print
	add	sp,8		#Avança na pilha

	pop	esi
	pop	edi
	pop	ebx
	pop	ebp
	ret
