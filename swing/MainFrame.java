import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.IOException;

public class MainFrame extends JFrame {

    private JTextArea textArea;      // Zone pour afficher la réponse du serveur
    private JTextField commandField; // Champ pour saisir la commande à envoyer
    private Client client;           // Pour communiquer avec le serveur C++

    private Action actionAllMedia;
    private Action actionAllGroup;
    private Action actionEnvoyer;
    private Action actionQuitter;

    public MainFrame() {
        super("Fenêtre Principale - Client/Serveur");

        // Tentative de connexion au serveur
        try {
            client = new Client("localhost", 3331);
        } catch (IOException e) {
            JOptionPane.showMessageDialog(
                this,
                "Impossible de se connecter au serveur : " + e.getMessage(),
                "Erreur",
                JOptionPane.ERROR_MESSAGE
            );
        }

        // Zone de texte pour les réponses du serveur
        textArea = new JTextArea(10, 40);
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);

        // Champ pour taper les commandes
        commandField = new JTextField(20);

        
        actionAllMedia = new AbstractAction("Afficher tous les médias") {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Vérifier si on est connecté
                if (client == null) {
                    textArea.append("Erreur : pas de connexion au serveur.\n");
                    return;
                }
                String request = "getallmultimedia";
                if (request.isEmpty()) return;

                // Afficher la commande dans la zone de texte
                textArea.append(">> " + request + "\n");

                // Envoyer la commande au serveur et récupérer la réponse
                String response = client.send(request);

                // Afficher la réponse dans la zone de texte
                if (response != null) {
                    // On remet les retour à la ligne car sinon ca fonctionnait pas si j'nevoyais directement \n 
                    String formattedResponse = response.replace(";", "\n");
                    textArea.append(formattedResponse + "\n");
                } else {
                    textArea.append("Aucune réponse du serveur (ou erreur).\n");
                }
                // Réinitialiser la commande
                commandField.setText("");
            }
        };

        actionAllGroup = new AbstractAction("Afficher tous les groupes") {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Vérifier si on est connecté
                if (client == null) {
                    textArea.append("Erreur : pas de connexion au serveur.\n");
                    return;
                }
                String request = "getallgroup";
                if (request.isEmpty()) return;

                // Afficher la commande dans la zone de texte 
                textArea.append(">> " + request + "\n");

                // Envoyer la commande au serveur et récupérer la réponse
                String response = client.send(request);

                // Afficher la réponse dans la zone de texte
                if (response != null) {
                    // On remet les retour à la ligne car sinon ca fonctionnait pas si j'nevoyais directement \n 
                    String formattedResponse = response.replace(";", "\n");
                    textArea.append(formattedResponse + "\n");
                } else {
                    textArea.append("Aucune réponse du serveur (ou erreur).\n");
                }
                // Réinitialiser la commande
                commandField.setText("");
            }
        };

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

                // Afficher la commande dans la zone de texte
                textArea.append(">> " + request + "\n");

                // Envoyer la commande au serveur et récupérer la réponse
                String response = client.send(request);

                // Afficher la réponse dans la zone de texte
                if (response != null) {
                    // On remet les retour à la ligne car sinon ca fonctionnait pas si j'nevoyais directement \n 
                    String formattedResponse = response.replace(";", "\n");
                    textArea.append(formattedResponse + "\n");
                } else {
                    textArea.append("Aucune réponse du serveur (ou erreur).\n");
                }
                // Réinitialiser la commande
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

        menuFichier.add(actionAllMedia);
        menuFichier.add(actionAllGroup);
        menuFichier.addSeparator();
        menuFichier.add(actionQuitter);

        menuBar.add(menuFichier);
        setJMenuBar(menuBar);

        // --- Barre d'outils ---
        JToolBar toolBar = new JToolBar("Barre d'outils");
        toolBar.add(actionAllMedia);
        toolBar.add(actionAllGroup);
        toolBar.addSeparator();
        toolBar.add(actionQuitter);

        // --- Panneau du bas pour la saisie de commande ---
        JPanel commandPanel = new JPanel(new FlowLayout(FlowLayout.LEFT, 5, 5));
        commandPanel.add(new JLabel("Commande :"));
        commandPanel.add(commandField);

        // Bouton « Envoyer »
        JButton btnEnvoyer = new JButton(actionEnvoyer);
        commandPanel.add(btnEnvoyer);

        // Zone avec le texte pour expliquer les commandes à droite
        JTextArea helpTextArea = new JTextArea();
        helpTextArea.setEditable(false);
        helpTextArea.setText("Liste des commandes :\n"
            + "- play nom_du_media\n"
            + "- searchmultimedia nom_du_media\n"
            + "- searchgroup nom_du_groupe\n"
            + "- getallmultimedia\n"
            + "- getallgroup");
        helpTextArea.setBackground(new Color(240, 240, 240));
        JScrollPane helpScrollPane = new JScrollPane(helpTextArea);
        helpScrollPane.setPreferredSize(new Dimension(300, 0));

        // Mise en page de la fenêtre
        setLayout(new BorderLayout());
        add(toolBar, BorderLayout.NORTH);      
        add(scrollPane, BorderLayout.CENTER);
        add(commandPanel, BorderLayout.SOUTH);
        add(helpScrollPane, BorderLayout.EAST);

        // Configuration finale de la fenêtre
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        System.setProperty("apple.laf.useScreenMenuBar", "true");

        SwingUtilities.invokeLater(MainFrame::new);
    }
}
