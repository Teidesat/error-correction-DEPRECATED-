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
include CMakeFiles\error-correction.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\error-correction.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\error-correction.dir\flags.make

CMakeFiles\error-correction.dir\src\main.cpp.obj: CMakeFiles\error-correction.dir\flags.make
CMakeFiles\error-correction.dir\src\main.cpp.obj: ..\src\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/error-correction.dir/src/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1422~1.279\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\error-correction.dir\src\main.cpp.obj /FdCMakeFiles\error-correction.dir\ /FS -c C:\Users\Shoo\CLionProjects\error-correction\src\main.cpp
<<

CMakeFiles\error-correction.dir\src\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/error-correction.dir/src/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1422~1.279\bin\Hostx86\x86\cl.exe > CMakeFiles\error-correction.dir\src\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Shoo\CLionProjects\error-correction\src\main.cpp
<<

CMakeFiles\error-correction.dir\src\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/error-correction.dir/src/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1422~1.279\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\error-correction.dir\src\main.cpp.s /c C:\Users\Shoo\CLionProjects\error-correction\src\main.cpp
<<

# Object files for target error-correction
error__correction_OBJECTS = \
"CMakeFiles\error-correction.dir\src\main.cpp.obj"

# External object files for target error-correction
error__correction_EXTERNAL_OBJECTS =

error-correction.exe: CMakeFiles\error-correction.dir\src\main.cpp.obj
error-correction.exe: CMakeFiles\error-correction.dir\build.make
error-correction.exe: CMakeFiles\error-correction.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable error-correction.exe"
	C:\Users\Shoo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.6817.18\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\error-correction.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\BUILDT~1\VC\Tools\MSVC\1422~1.279\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\error-correction.dir\objects1.rsp @<<
 /out:error-correction.exe /implib:error-correction.lib /pdb:C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\error-correction.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\error-correction.dir\build: error-correction.exe

.PHONY : CMakeFiles\error-correction.dir\build

CMakeFiles\error-correction.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\error-correction.dir\cmake_clean.cmake
.PHONY : CMakeFiles\error-correction.dir\clean

CMakeFiles\error-correction.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Shoo\CLionProjects\error-correction C:\Users\Shoo\CLionProjects\error-correction C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug C:\Users\Shoo\CLionProjects\error-correction\cmake-build-debug\CMakeFiles\error-correction.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\error-correction.dir\depend

