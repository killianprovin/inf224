#!/bin/bash

# Lancer le serveur C++
cd cpp
make run &
CPP_PID=$!

# Attendre un peu que le serveur démarre
sleep 1

# Lancer l’interface Swing
cd ../swing
make run

# Optionnel : tuer le serveur une fois que l’interface est fermée
kill $CPP_PID
