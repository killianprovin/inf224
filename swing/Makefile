##########################################
#
#  Makefile
#  Killian PROVIN
#  INF224 - TP C++ - http://www.telecom-paristech.fr/~elc/inf224
#
##########################################

#
# Nom du programme
#
PROG = Main

#
# Fichiers sources
#
SOURCES= Main.java MainFrame.java Client.java

#
# Compilateur Java
#
JC = javac

#
# Options du compilateur Java
#
JFLAGS = -g

##########################################
#
# Regles de construction/destruction des .class et de l'executable
#
 
all: classes

run: all
	java swing/${PROG}

classes: $(SOURCES:.java=.class)

clean:
	-@$(RM) *.class 1>/dev/null 2>&1
  
tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}


###########################################
#
# Regles implicites
#

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java
