##########################################
#
#  Makefile
#  Killian PROVIN
#  INF224 - TP Java - http://www.telecom-paristech.fr/~elc/inf224
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
JFLAGS = -g -classpath .

##########################################
#
# Regles de construction/destruction des .class et de l'executable
#
 
all: classes

run: all
	java $(PROG)

classes: Client.class MainFrame.class Main.class

Client.class: Client.java
	$(JC) $(JFLAGS) Client.java

MainFrame.class: MainFrame.java Client.class
	$(JC) $(JFLAGS) MainFrame.java

Main.class: Main.java MainFrame.class Client.class
	$(JC) $(JFLAGS) Main.java

clean:
	-@$(RM) *.class 1>/dev/null 2>&1
  
tar:
	tar cvf $(PROG).tar.gz $(SOURCES)
