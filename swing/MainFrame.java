package swing;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.IOException;

public class MainFrame extends JFrame {

    private JTextArea textArea;      // Zone pour afficher la réponse du serveur
    private JTextField commandField; // Champ pour saisir la commande à envoyer
    private Client client;           // Pour communiquer avec le serveur C++

    // Deux actions : Envoyer et Quitter (réutilisées dans le menu et la barre d'outils)
    private Action actionEnvoyer;
    private Action actionQuitter;

    public MainFrame() {
        super("Fenêtre Principale - Client/Serveur");

        // Tentative de connexion au serveur
        try {
            // Ajustez l'hôte/port si nécessaire (par défaut: localhost:3331)
            client = new Client("localhost", 3331);
        } catch (IOException e) {
            JOptionPane.showMessageDialog(
                this,
                "Impossible de se connecter au serveur : " + e.getMessage(),
                "Erreur",
                JOptionPane.ERROR_MESSAGE
            );
        }

        // Zone de texte où s'afficheront les réponses du serveur
        textArea = new JTextArea(10, 40);
        textArea.setEditable(false);            // Pas de modification manuelle
        JScrollPane scrollPane = new JScrollPane(textArea);

        // Champ de saisie pour taper les commandes
        commandField = new JTextField(20);

        // --- Création des Actions ---

        // Action pour envoyer la commande
        actionEnvoyer = new AbstractAction("Envoyer") {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Vérifier si on est connecté
                if (client == null) {
                    textArea.append("Erreur : pas de connexion au serveur.\n");
                    return;
                }
                // Récupérer la commande dans le champ de texte
                String request = commandField.getText().trim();
                if (request.isEmpty()) return;

                // Afficher la commande dans la zone de texte (optionnel)
                textArea.append(">> " + request + "\n");

                // Envoyer la commande au serveur et récupérer la réponse
                String response = client.send(request);

                // Afficher la réponse dans la zone de texte
                if (response != null) {
                    String formattedResponse = response.replace(";", "\n");
                    textArea.append(formattedResponse + "\n");
                } else {
                    textArea.append("Aucune réponse du serveur (ou erreur).\n");
                }
                // Réinitialiser le champ de commande
                commandField.setText("");
            }
        };

        // Action pour quitter l'application
        actionQuitter = new AbstractAction("Quitter") {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        };

        // --- Barre de menus ---
        JMenuBar menuBar = new JMenuBar();
        JMenu menuFichier = new JMenu("Fichier");

        menuFichier.add(actionEnvoyer);
        menuFichier.addSeparator();
        menuFichier.add(actionQuitter);

        menuBar.add(menuFichier);
        setJMenuBar(menuBar);

        // --- Barre d'outils ---
        JToolBar toolBar = new JToolBar("Barre d'outils");
        toolBar.add(actionEnvoyer);
        toolBar.addSeparator();
        toolBar.add(actionQuitter);

        // --- Panneau du bas pour la saisie de commande ---
        JPanel commandPanel = new JPanel(new FlowLayout(FlowLayout.LEFT, 5, 5));
        commandPanel.add(new JLabel("Commande :"));
        commandPanel.add(commandField);

        // Bouton « Envoyer » (même action que dans le menu/barre d'outils)
        JButton btnEnvoyer = new JButton(actionEnvoyer);
        commandPanel.add(btnEnvoyer);

        // --- Mise en page (Layout) ---
        setLayout(new BorderLayout());
        add(toolBar, BorderLayout.NORTH);       // barre d'outils en haut
        add(scrollPane, BorderLayout.CENTER);   // zone de texte au centre
        add(commandPanel, BorderLayout.SOUTH);  // champ commande en bas

        // Configuration de la fenêtre
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();                          // Ajuste la taille en fonction du contenu
        setLocationRelativeTo(null);     // Centre la fenêtre sur l'écran
        setVisible(true);                // Rend la fenêtre visible
    }

    public static void main(String[] args) {
        // (Optionnel) Sur macOS, la barre de menus s’affichera tout en haut
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        // Lancement de l'UI sur le thread événementiel
        SwingUtilities.invokeLater(MainFrame::new);
    }
}
