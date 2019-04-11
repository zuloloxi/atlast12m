@rem
@rem  Make file for Microsoft C.  Assumes C compiler is on the path
@rem  and that the LIB, INCLUDE, HELPFILES, and INIT variables have
@rem  been set properly.
@rem
cl /DMEMSTAT /DEXPORT /DOS2 /FPi87 /F 8000 /AL atlast.c atlmain.c
