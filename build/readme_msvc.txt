rem 
rem 2019/04/01
rem access violation bug in lookup detected in atlast 2.0
rem atlast 1.2 modified

# build with msvc C compiler - VS2010

cl /FAcs /DMEMSTAT /DEXPORT /DOS2 /F 8000 atlast.c atlmain.c /link /subsystem:console  /DYNAMICBASE:NO /FIXED /NXCOMPAT /MACHINE:X86 /DEBUG /MAP /MAPINFO:EXPORTS
