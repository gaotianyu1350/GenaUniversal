PROJECT = GenaUniversal
CPPDEPS = -MT$@ -MF$@.d -MD -MP
WXDIR = E:\wxWidgets-3.0.2
WXLIBDIR = $(WXDIR)\lib\gcc_lib
WXINCLUDEDIR = $(WXDIR)\include
SETUPDIR = $(WXLIBDIR)\mswu
LIBS = -lwxmsw30u_core -lwxbase30u -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lwxregexu -lwxexpat -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lwinspool -lwinmm -lshell32 -lcomctl32 -lole32 -loleaut32 -luuid -lrpcrt4 -ladvapi32 -lwsock32 -lwininet
DEFINES = -DHAVE_W32API_H -D__WXMSW__ -DNDEBUG -D_UNICODE -DNOPCH
WIDGETS_CXXFLAGS = -mthreads $(DEFINES) -I$(WXINCLUDEDIR) -I$(SETUPDIR) -W -Wall -Wno-ctor-dtor-privacy -std=gnu++11

RESOURCE = resource.rc

DIR_DEBUG = bin\Debug
DIROBJ_DEBUG = obj\Debug
BIN_DEBUG = $(DIR_DEBUG)\$(PROJECT).exe

OBJ_DEBUG = $(DIROBJ_DEBUG)\GenaUniversalApp.o $(DIROBJ_DEBUG)\GenaUniversalMain.o $(DIROBJ_DEBUG)\File.o $(DIROBJ_DEBUG)\FileGroup.o

RES_DEBUG = $(DIROBJ_DEBUG)\resource.o
$(RES_DEBUG): $(RESOURCE)
	windres --use-temp-file -i$< -o$@ --define __WXMSW__ --define NDEBUG --define _UNICODE  --include-dir $(SETUPDIR) --include-dir $(WXINCLUDEDIR) --define NOPCH

$(DIROBJ_DEBUG)\GenaUniversalApp.o: GenaUniversalApp.cpp
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -g
$(DIROBJ_DEBUG)\GenaUniversalMain.o: GenaUniversalMain.cpp
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -g
$(DIROBJ_DEBUG)\FileGroup.o: FileGroup.cpp
	g++ -c -o $@ $(CPPDEPS) $< -g
$(DIROBJ_DEBUG)\File.o: File.cpp
	g++ -c -o $@ $(CPPDEPS) $< -g

$(BIN_DEBUG): $(OBJ_DEBUG) $(RES_DEBUG)
	g++ -o $(BIN_DEBUG) $(OBJ_DEBUG) $(RES_DEBUG) -mthreads -L$(WXLIBDIR) $(LIBS) -static
$(DIR_DEBUG):
	-if not exist $(DIR_DEBUG) mkdir $(DIR_DEBUG)
$(DIROBJ_DEBUG):
	-if not exist $(DIROBJ_DEBUG) mkdir $(DIROBJ_DEBUG)
Debug: $(DIR_DEBUG) $(DIROBJ_DEBUG) $(BIN_DEBUG)
cleanDebug:
	-if exist $(DIROBJ_DEBUG)\*.o del $(DIROBJ_DEBUG)\*.o
	-if exist $(DIROBJ_DEBUG)\*.d del $(DIROBJ_DEBUG)\*.d
	-if exist $(BIN_DEBUG) del $(BIN_DEBUG)

DIR_RELEASE = bin\Release
DIROBJ_RELEASE = obj\Release
BIN_RELEASE = $(DIR_RELEASE)\$(PROJECT).exe

OBJ_RELEASE = $(DIROBJ_RELEASE)\GenaUniversalApp.o $(DIROBJ_RELEASE)\GenaUniversalMain.o $(DIROBJ_RELEASE)\FileGroup.o $(DIROBJ_RELEASE)\File.o

RES_RELEASE = $(DIROBJ_RELEASE)\resource.o
$(RES_RELEASE): $(RESOURCE)
	windres --use-temp-file -i$< -o$@ --define __WXMSW__ --define NDEBUG --define _UNICODE  --include-dir $(SETUPDIR) --include-dir $(WXINCLUDEDIR) --define NOPCH
	
$(DIROBJ_RELEASE)\GenaUniversalApp.o: GenaUniversalApp.cpp
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -O2
$(DIROBJ_RELEASE)\GenaUniversalMain.o: GenaUniversalMain.cpp
	g++ -c -o $@ $(WIDGETS_CXXFLAGS) $(CPPDEPS) $< -O2
$(DIROBJ_RELEASE)\File.o: File.cpp
	g++ -c -o $@ $(CPPDEPS) $< -O2
$(DIROBJ_RELEASE)\FileGroup.o: FileGroup.cpp
	g++ -c -o $@ $(CPPDEPS) $< -O2
	
$(BIN_RELEASE): $(OBJ_RELEASE) $(RES_RELEASE)
	g++ -o $(BIN_RELEASE) $(OBJ_RELEASE) $(RES_RELEASE) -mthreads -L$(WXLIBDIR) -Wl,--subsystem,windows $(LIBS) -static -mwindows
$(DIR_RELEASE):
	-if not exist $(DIR_RELEASE) mkdir $(DIR_RELEASE)
$(DIROBJ_RELEASE):
	-if not exist $(DIROBJ_RELEASE) mkdir $(DIROBJ_RELEASE)
Release: $(DIR_RELEASE) $(DIROBJ_RELEASE) $(BIN_RELEASE)
cleanRelease:
	-if exist $(DIROBJ_RELEASE)\*.o del $(DIROBJ_RELEASE)\*.o
	-if exist $(DIROBJ_RELEASE)\*.d del $(DIROBJ_RELEASE)\*.d
	-if exist $(BIN_RELEASE) del $(BIN_RELEASE)

.PHONY: Debug Release cleanDebug cleanRelease
