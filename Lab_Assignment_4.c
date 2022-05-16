#include <stdio.h>
#include <string.h>
#include <stdint.h>
void readelf(FILE *f, char v[])
{
    if(strchr(v,'h') || strchr(v,'a'))
  {
    char magic[4];
    fread(&magic,4,1,f);
    if((magic[0]==0x7F) && (magic[1]==0x45) && (magic[2]==0x4c) && (magic[3]=0x46))
    {
	printf("Valid ELF64 file\n");
    }
    else
    {
	printf("Invalid ELF64 file\n");
    }
    char class[2];
    fread(&class,1,1,f);
    int bit_verif=0;
    if(class[0]==1)
    {
	printf("This is a 32-bit file\n");
    }
    if(class[0]==2)
    {
	printf("This is a 64-bit file\n");
	bit_verif=1;
    }
    if(class[1]==1)
    {
	printf("This is a little endianness file\n");
    }
    if(class[1]==2)
    {
	printf("This a big endianness file\n");
    }
    char org[1];
    fread(&org,1,1,f);
    if(org[0]==1)
    {
	printf("This is the original and current version of ELF\n");
    }
    else
    {
	printf("This is not the original and current version of ELF\n");
    }
    char OSABI;
    fread(&OSABI,1,1,f);
    switch(OSABI)
    {
    case 0:
	printf("System V\n");
	break;
    case 1:
	printf("HP-UX\n");
	break;
    case 2:
	printf("NetBSD\n");
	break;
    case 3:
	printf("Linux\n");
	break;
    case 4:
	printf("GNU Hurd\n");
	break;
    case 6:
	printf("Solaris\n");
	break;
    case 7:
	printf("AIX\n");
	break;
    case 8:
	printf("IRIX\n");
	break;
    case 9:
	printf("FreeBSD\n");
	break;
    case 'A':
	printf("Tru64\n");
	break;
    case'B':
	printf("Novell Modesto\n");
	break;
    case 'C':
	printf("OpenBSD\n");
	break;
    case 'D':
	printf("OpenVMS\n");
	break;
    case 'E':
	printf("NonStop Kernel\n");
	break;
    case 'F':
	printf("AROS\n");
	break;
    case 10:
	printf("Fenix OS\n");
	break;
    case 11:
	printf("CloudABI\n");
	break;
    case 12:
	printf("Stratus Technologies OpenVOS\n");
	break;
     }
    char ignore[8];
    fread(&ignore,8,1,f);
    char type[2];
    fread(&type,2,1,f);
    if(strcmp(type,"0x00"))
	{
	    printf("Unknown\n");
	}
    if(strcmp(type,"0x01"))
	{
	    printf("Relocatable file\n");
	}
    if(strcmp(type,"0x02"))
	{
	    printf("Executable file\n");
	}
    if(strcmp(type,"0x03"))
	{
	    printf("Shared object\n");
	}
    if(strcmp(type,"0x04"))
	{
	    printf("Core file\n");
	}
    if(strcmp(type,"0xFE00")|| strcmp(type,"0xFEFF"))
	{
	    printf("Reserved inclusive range.Operating system specific.\n");
	}
    if(strcmp(type,"0xFF00") || strcmp(type,"0xFFFF"))
	{
	    printf("Reserved inclusive range.Processor specific.\n");
	}
    char ins_set[2];
    fread(&ins_set,2,1,f);
    if(strcmp(ins_set,"0x00"))
    {
	printf("No specific instruction set\n");
    }
    if(strcmp(ins_set,"0x01"))
    {
	printf("AT&T WE 32100\n");
    }
    if(strcmp(ins_set,"0x02"))
    {
	printf("SPARC\n");
    }
    if(strcmp(ins_set,"0x03"))
    {
	printf("x86\n");
    }
    if(strcmp(ins_set,"0x04"))
    {
	printf("Motorola 68000(M68k)\n");
    }
    if(strcmp(ins_set,"0x05"))
    {
	printf("Motorola 88000(M88k)\n");
    }
    if(strcmp(ins_set,"0x06"))
    {
	printf("Intel MCU\n");
    }
    if(strcmp(ins_set,"0x07"))
    {
	printf("Intel 80860\n");
    }
    if(strcmp(ins_set,"0x08"))
    {
	printf("MIPS\n");
    }
    if(strcmp(ins_set,"0x09"))
    {
	printf("IBM System/370\n");
    }
    if(strcmp(ins_set,"0x0A"))
    {
	printf("MIPS RS3000 Little-endian\n");
    }
    if(strcmp(ins_set,"0x0E"))
    {
	printf("Hewlett-Packard PA-RISC\n");
    }
    if(strcmp(ins_set,"0x13"))
    {
	printf("Intel 80960\n");
    }
    if(strcmp(ins_set,"0x14"))
    {
	printf("PowerPC\n");
    }
    if(strcmp(ins_set,"0x15"))
    {
	printf("PowerPc(64-bit)\n");
    }
    if(strcmp(ins_set,"0x16"))
    {
	printf("S390,including S390x\n");
    }
    if(strcmp(ins_set,"0x17"))
    {
	printf("IBM SPU/SPC\n");
    }
    if(strcmp(ins_set,"0x24"))
    {
	printf("NEC V800\n");
    }
    if(strcmp(ins_set,"0x25"))
    {
	printf("Fujitsu FR20\n");
    }
    if(strcmp(ins_set,"0x26"))
    {
	printf("TRW RH-32\n");
    }
    if(strcmp(ins_set,"0x27"))
    {
	printf("Motorola RCE\n");
    }
    if(strcmp(ins_set,"0x28"))
    {
	printf("ARM(up to ARMv7/Aarch32)");
    }
    if(strcmp(ins_set,"0x29"))
    {
	printf("Digital Alpha\n");
    }
    if(strcmp(ins_set,"0x2A"))
    {
	printf("SuperH\n");
    }
    if(strcmp(ins_set,"0x2B"))
    {
	printf("Sparc Version 9\n");
    }
    if(strcmp(ins_set,"0x2C"))
    {
	printf("Siemens TriCore embedded processor\n");
    }
    if(strcmp(ins_set,"0x2D"))
    {
	printf("Argonaut RISC Core\n");
    }
    if(strcmp(ins_set,"0x2E"))
    {
	printf("Hitach H8/300\n");
    }  
      if(strcmp(ins_set,"0x2F"))
    {
	printf("Hitachi H8/300H\n");
    }   
     if(strcmp(ins_set,"0x30"))
    {
	printf("Hitach H8S\n");
    }   
     if(strcmp(ins_set,"0x31"))
    {
	printf("Hitach H8/500\n");
    }    
    if(strcmp(ins_set,"0x32"))
    {
	printf("IA-64\n");
    }   
     if(strcmp(ins_set,"0x33"))
    {
	printf("Stanford MIPS-X\n");
    }
    if(strcmp(ins_set,"0x34"))
    {
	printf("Motorola ColdFire\n");
    }   
     if(strcmp(ins_set,"0x35"))
    {
	printf("Motorola M68HC12\n");
    }    
    if(strcmp(ins_set,"0x36"))
    {
	printf("Fujitsu MMA Multimedia Accelerator\n");
    }    
    if(strcmp(ins_set,"0x37"))
    {
	printf("Siemens PCP\n");
    }    
    if(strcmp(ins_set,"0x38"))
    {
	printf("Sony nCPU embedded RISC processor\n");
    }    
    if(strcmp(ins_set,"0x39"))
    {
	printf("Denso NDR1 microprocessor\n");
    }    
    if(strcmp(ins_set,"0x3A"))
    {
	printf("Motorla Star*Core processor\n");
    }    
    if(strcmp(ins_set,"0x3B"))
    {
	printf("Toyota ME16processor\n");
    }
    if(strcmp(ins_set,"0x3C"))
    {
	printf("STMicroelectronics ST100 processor\n");
    }    
    if(strcmp(ins_set,"0x3D"))
    {
	printf("Advanced Logic Corp.TinyJ embedded processor family\n");
    }    
    if(strcmp(ins_set,"0x3E"))
    {
	printf("AMD x86-64\n");
    }    
    if(strcmp(ins_set,"0x8C"))
    {
	printf("TMS320C6000 Family\n");
    }    
    if(strcmp(ins_set,"0xAF"))
    {
	printf("MCST Elbrus e2k\n");
    }    
    if(strcmp(ins_set,"0xB7"))
    {
	printf("ARM 64-bits(ARMv8/Aarch64)\n");
    }    
    if(strcmp(ins_set,"0xF3"))
    {
	printf("RISC-V\n");
    }    
    if(strcmp(ins_set,"0xF7"))
    {
	printf("Berkeley Packet Filter\n");
    }    
    if(strcmp(ins_set,"0x101"))
    {
	printf("WDC 65C816\n");
    }   
    char no_use[4];
    fread(&no_use,4,1,f);
    int entry=0;
    if(bit_verif)
    {
	entry=8;
    }
    else
    {
	entry=4;
    }
    uint16_t memory_address;
    fread(&memory_address,entry,1,f);
    printf("Entry point adress:0x%u\n",memory_address);
    uint16_t phoff;
    fread(&phoff,entry,1,f);
    printf("The start of the program header:%d\n",phoff);
    uint32_t shoff;
    fread(&shoff,entry,1,f);
    printf("The start of the section header table:%d\n",shoff);
    uint32_t flags;
    fread(&flags,4,1,f);
    printf("Flag:0x%x\n",flags);
    uint8_t size;
    fread(&size,2,1,f);
    printf("Size of header:%d\n",size);
    uint8_t phentsize;
    fread(&phentsize,2,1,f);
    printf("Size of of program header:%d\n",phentsize);
    uint8_t phnum;
    fread(&phnum,2,1,f);
    printf("Number of entries:%d\n",phnum);
    uint8_t shentsize;
    fread(&shentsize,2,1,f);
    printf("Size of section header:%d\n",shentsize);
    uint8_t shnum;
    fread(&shnum,2,1,f);
    printf("Number of entries in section header:%d\n",shnum);
    uint8_t shstrndx;
    fread(&shstrndx,2,1,f);
    printf("Index of the section header:%d\n",shstrndx);    
  }
    if(strchr(v,'l'))
    {
	char p_type[4];
	fread(&p_type,4,1,f);
	if(strcmp(p_type,"0x00000000"))
	{
	    printf("Program header table entry unused\n");
	}
	if(strcmp(p_type,"0x00000001"))
	{
	    printf("Loadabale segment\n");
	}
	if(strcmp(p_type,"0x00000002"))
	{
	    printf("Dynamic linking information\n");
	}
	if(strcmp(p_type,"0x00000003"))
	{
	    printf("Interpreter information\n");
	}
	if(strcmp(p_type,"0x00000004"))
	{
	    printf("Auxiliary information\n");
	}
	if(strcmp(p_type,"0x00000005"))
	{
	    printf("Reserved\n");
	}
	if(strcmp(p_type,"0x00000006"))
	{
	    printf("Segment containing program header table itself\n");
	}
	if(strcmp(p_type,"0x00000007"))
	{
	    printf("Thread-Local Storage template\n");
	}
	if(strcmp(p_type,"0x60000000") || strcmp(p_type,"0x6FFFFFFF"))
	{
	    printf("Reserved inclusive range.Operating system specific.\n");
	}
	if(strcmp(p_type,"0x70000000") || strcmp(p_type,"0x7FFFFFFF"))
	{
	    printf("Reserved inclusive range.Processor specific.\n");
	}
	uint16_t p_flags;
	fread(&p_flags,4,1,f);
	printf("Segmend-dependent flags:%d\n",p_flags);
	uint32_t p_offset;
	fread(&p_offset,8,1,f);
	printf("Offset of the segment in the file image:%d\n",p_offset);
	uint32_t p_paddr;
	fread(&p_paddr,8,1,f);
	uint32_t p_filesz;
	fread(&p_filesz,8,1,f);
	printf("Size of the segment in the file image:0x%u\n",p_filesz);
	uint32_t p_memsz;
	fread(&p_memsz,8,1,f);
	printf("Size of the segment in memory:0x%u\n",p_memsz);
    }
}
unsigned int filesize(FILE *f)
{
	long buff;
	fseek(f,0,SEEK_END);
	buff=ftell(f);
	fseek(f,0,SEEK_SET);
	return buff;
}
int main(int argc, char *argv[])
{
    if(argc!=3)
    {
	printf("Invalid input");
	return -1;
    }
    FILE *f=fopen(argv[1],"rb");
    if(!f)
    {
	printf("Couldn't open file");
	return -2;
    }
    printf("File size of the file %s in bits is:%u",argv[1],filesize(f));
    readelf(f,argv[2]);
    return 0;
}