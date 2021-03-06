#############################################################################
# Makefile for building: SendMail
# Generated by qmake (2.01a) (Qt 4.6.2) on: Mon Nov 7 21:27:23 2016
# Project:  SendMail.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -unix -o Makefile SendMail.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_SQL_LIB -DQT_CORE_LIB
CFLAGS        = -m64 -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -m64 -mtune=generic -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -g -pipe -Wall -Wp,-D_FORTIFY_SOURCE=2 -fstack-protector --param=ssp-buffer-size=4 -m64 -mtune=generic -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib64/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/QtCore -I/usr/include/QtSql -I/usr/include -Ibuild/moc
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)   -lQtSql -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = 
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/obj/

####### Files

SOURCES       = src/main.cpp \
		src/cprtfcdatabase.cpp build/moc/moc_cprtfcdatabase.cpp
OBJECTS       = build/obj/main.o \
		build/obj/cprtfcdatabase.o \
		build/obj/moc_cprtfcdatabase.o
DIST          = /usr/lib64/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf \
		SendMail.pro
QMAKE_TARGET  = SendMail
DESTDIR       = 
TARGET        = SendMail

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: SendMail.pro  /usr/lib64/qt4/mkspecs/linux-g++-64/qmake.conf /usr/lib64/qt4/mkspecs/common/g++-multilib.conf \
		/usr/lib64/qt4/mkspecs/common/unix.conf \
		/usr/lib64/qt4/mkspecs/common/linux.conf \
		/usr/lib64/qt4/mkspecs/qconfig.pri \
		/usr/lib64/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt4/mkspecs/features/qt_config.prf \
		/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt4/mkspecs/features/default_pre.prf \
		/usr/lib64/qt4/mkspecs/features/release.prf \
		/usr/lib64/qt4/mkspecs/features/default_post.prf \
		/usr/lib64/qt4/mkspecs/features/warn_on.prf \
		/usr/lib64/qt4/mkspecs/features/qt.prf \
		/usr/lib64/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt4/mkspecs/features/moc.prf \
		/usr/lib64/qt4/mkspecs/features/resources.prf \
		/usr/lib64/qt4/mkspecs/features/uic.prf \
		/usr/lib64/qt4/mkspecs/features/yacc.prf \
		/usr/lib64/qt4/mkspecs/features/lex.prf
	$(QMAKE) -unix -o Makefile SendMail.pro
/usr/lib64/qt4/mkspecs/common/g++-multilib.conf:
/usr/lib64/qt4/mkspecs/common/unix.conf:
/usr/lib64/qt4/mkspecs/common/linux.conf:
/usr/lib64/qt4/mkspecs/qconfig.pri:
/usr/lib64/qt4/mkspecs/features/qt_functions.prf:
/usr/lib64/qt4/mkspecs/features/qt_config.prf:
/usr/lib64/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt4/mkspecs/features/default_pre.prf:
/usr/lib64/qt4/mkspecs/features/release.prf:
/usr/lib64/qt4/mkspecs/features/default_post.prf:
/usr/lib64/qt4/mkspecs/features/warn_on.prf:
/usr/lib64/qt4/mkspecs/features/qt.prf:
/usr/lib64/qt4/mkspecs/features/unix/thread.prf:
/usr/lib64/qt4/mkspecs/features/moc.prf:
/usr/lib64/qt4/mkspecs/features/resources.prf:
/usr/lib64/qt4/mkspecs/features/uic.prf:
/usr/lib64/qt4/mkspecs/features/yacc.prf:
/usr/lib64/qt4/mkspecs/features/lex.prf:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile SendMail.pro

dist: 
	@$(CHK_DIR_EXISTS) build/obj/SendMail1.0.0 || $(MKDIR) build/obj/SendMail1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/obj/SendMail1.0.0/ && $(COPY_FILE) --parents src/cprtfcdatabase.h build/obj/SendMail1.0.0/ && $(COPY_FILE) --parents src/main.cpp src/cprtfcdatabase.cpp build/obj/SendMail1.0.0/ && (cd `dirname build/obj/SendMail1.0.0` && $(TAR) SendMail1.0.0.tar SendMail1.0.0 && $(COMPRESS) SendMail1.0.0.tar) && $(MOVE) `dirname build/obj/SendMail1.0.0`/SendMail1.0.0.tar.gz . && $(DEL_FILE) -r build/obj/SendMail1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc/moc_cprtfcdatabase.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc/moc_cprtfcdatabase.cpp
build/moc/moc_cprtfcdatabase.cpp: src/qsql_mysql.h \
		src/cprtfcdatabase.h
	/usr/lib64/qt4/bin/moc $(DEFINES) $(INCPATH) src/cprtfcdatabase.h -o build/moc/moc_cprtfcdatabase.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

build/obj/main.o: src/main.cpp src/cprtfcdatabase.h \
		src/qsql_mysql.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/main.o src/main.cpp

build/obj/cprtfcdatabase.o: src/cprtfcdatabase.cpp src/cprtfcdatabase.h \
		src/qsql_mysql.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/cprtfcdatabase.o src/cprtfcdatabase.cpp

build/obj/moc_cprtfcdatabase.o: build/moc/moc_cprtfcdatabase.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/obj/moc_cprtfcdatabase.o build/moc/moc_cprtfcdatabase.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

