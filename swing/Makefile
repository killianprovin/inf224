# Répertoire de sortie pour les fichiers compilés
BIN_DIR=bin
SRC_DIR=swing
MAIN_CLASS=Main

# Trouve tous les fichiers .java dans le dossier source
SOURCES=$(wildcard $(SRC_DIR)/*.java)

# Génère les fichiers .class correspondants dans le répertoire bin
CLASSES=$(SOURCES:$(SRC_DIR)/%.java=$(BIN_DIR)/%.class)

# Cible par défaut
all: $(BIN_DIR) $(CLASSES)

# Crée le dossier bin s'il n'existe pas
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile chaque fichier .java en fichier .class dans le dossier bin
$(BIN_DIR)/%.class: $(SRC_DIR)/%.java
	javac -d $(BIN_DIR) $<

# Lance le programme principal
run: all
	java -cp $(BIN_DIR) $(MAIN_CLASS)

# Nettoie les fichiers compilés
clean:
	rm -rf $(BIN_DIR)
