rem ---------------------------------------------------------------------------

rem Perforce paths
set PATH=%ARM_GCC%;%PATH%

set TOP_DIR=../
set OBJ_DIR=%TOP_DIR%makefiles/obj
set ELF_DIR=%TOP_DIR%makefiles/bin

mkdir obj
mkdir bin

make -f make_demo TOP_DIR=%TOP_DIR% OBJ_DIR=%OBJ_DIR% ELF_DIR=%ELF_DIR%

pause
exit
