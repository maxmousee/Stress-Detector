@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=vsd_mex
set MEX_NAME=vsd_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2016a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for vsd > vsd_mex.mki
echo COMPILER=%COMPILER%>> vsd_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> vsd_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> vsd_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> vsd_mex.mki
echo LINKER=%LINKER%>> vsd_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> vsd_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> vsd_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> vsd_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> vsd_mex.mki
echo BORLAND=%BORLAND%>> vsd_mex.mki
echo OMPFLAGS= >> vsd_mex.mki
echo OMPLINKFLAGS= >> vsd_mex.mki
echo EMC_COMPILER=lcc64>> vsd_mex.mki
echo EMC_CONFIG=optim>> vsd_mex.mki
"C:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f vsd_mex.mk
