@rem
@rem  Build atlast.exe file with Microsoft C from VS2010 -> Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 16.00.40219.01 for 80x86
@rem  Assumes C compiler is on the path
@rem  and that the LIB, INCLUDE, HELPFILES, and INIT variables have
@rem  been set properly.
@rem
cl /FAcs /DMEMSTAT /DEXPORT /DOS2 /F 8000 atlast.c atlmain.c /link /subsystem:console  /DYNAMICBASE:NO /FIXED /NXCOMPAT /MACHINE:X86 /DEBUG /MAP /MAPINFO:EXPORTS