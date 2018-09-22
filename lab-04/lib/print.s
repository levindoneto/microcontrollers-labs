/*
  print.s: Prints a string on standar output.

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
    	.global print


print:
# parameters:
#	pointer to message to write
#	message length

	push	ebp
	mov	ebp,esp
	push	ebx

	mov	ecx,[ebp+8]	# pointer to message to write
	mov	edx,[ebp+12]	# message length

	mov	ebx,1		# file handle (stdout)
	mov	eax,4		# system call number (sys_write)
	int	0x80		# call kernel

	pop	ebx
	pop	ebp
	ret
