# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Shoo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.18\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Shoo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.18\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Shoo\CLionProjects\error-correction

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug

# Include any dependencies generated for this target.
include src\CMakeFiles\fec.dir\depend.make

# Include the progress variables for this target.
include src\CMakeFiles\fec.dir\progress.make

# Include the compile flags for this target's objects.
include src\CMakeFiles\fec.dir\flags.make

src\CMakeFiles\fec.dir\main.cpp.obj: src\CMakeFiles\fec.dir\flags.make
src\CMakeFiles\fec.dir\main.cpp.obj: ..\src\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/fec.dir/main.cpp.obj"
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\src
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1422~1.279\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\fec.dir\main.cpp.obj /FdCMakeFiles\fec.dir\ /FS -c C:\Users\Shoo\CLionProjects\error-correction\src\main.cpp
<<
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug

src\CMakeFiles\fec.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fec.dir/main.cpp.i"
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\src
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1422~1.279\bin\Hostx86\x86\cl.exe > CMakeFiles\fec.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Shoo\CLionProjects\error-correction\src\main.cpp
<<
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug

src\CMakeFiles\fec.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fec.dir/main.cpp.s"
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\src
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1422~1.279\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\fec.dir\main.cpp.s /c C:\Users\Shoo\CLionProjects\error-correction\src\main.cpp
<<
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug

# Object files for target fec
fec_OBJECTS = \
"CMakeFiles\fec.dir\main.cpp.obj"

# External object files for target fec
fec_EXTERNAL_OBJECTS =

src\fec.exe: src\CMakeFiles\fec.dir\main.cpp.obj
src\fec.exe: src\CMakeFiles\fec.dir\build.make
src\fec.exe: src\src.lib
src\fec.exe: src\CMakeFiles\fec.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fec.exe"
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\src
	C:\Users\Shoo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.18\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\fec.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1422~1.279\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\fec.dir\objects1.rsp @<<
 /out:fec.exe /implib:fec.lib /pdb:C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\src\fec.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console src.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug

# Rule to build all files generated by this target.
src\CMakeFiles\fec.dir\build: src\fec.exe

.PHONY : src\CMakeFiles\fec.dir\build

src\CMakeFiles\fec.dir\clean:
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\src
	$(CMAKE_COMMAND) -P CMakeFiles\fec.dir\cmake_clean.cmake
	cd C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug
.PHONY : src\CMakeFiles\fec.dir\clean

src\CMakeFiles\fec.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Shoo\CLionProjects\error-correction C:\Users\Shoo\CLionProjects\error-correction\src C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\src C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\src\CMakeFiles\fec.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src\CMakeFiles\fec.dir\depend
